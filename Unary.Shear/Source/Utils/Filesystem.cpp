#include <Unary.Shear/Utils/Filesystem.hpp>

/*

Filesystem::~Filesystem()
{
	for (auto& Stream : PackageStreams)
	{
		Stream.second->close();
		delete Stream.second;
	}
}

void Filesystem::Pack(const eastl::string& Path)
{
	eastl::unordered_map<eastl::string, eastl::vector<PackageEntry>> PackageEntries;

	{
		// Vector of files, that we are going to sort out
		eastl::vector<eastl::tuple<PackageEntrySort, PackageEntry>> Entries;

		int32_t PackageCounter = 0;
		eastl::unordered_map<eastl::string, int32_t> PackageNamesTable;
		eastl::vector<eastl::string> PackageNames;

		for (auto& p : std::filesystem::recursive_directory_iterator(Path.data()))
		{
			PackageEntry NewEntry;
			// Skip folder entries
			if (!p.is_regular_file() || p.path().extension().string() == ".upf") { continue; }
			// Replace Windows slashes if needed
			NewEntry.FullPath = Utils::String::Replace(p.path().string().data(), "\\", "/");
			// Make a relative path and check for being inside a folder
			NewEntry.RelativePath = Utils::String::Replace(NewEntry.FullPath, Path + '/', "");
			eastl::string PackageName = Utils::String::Split(NewEntry.RelativePath, '/')[0];
			NewEntry.RelativePath = Utils::String::Replace(NewEntry.RelativePath, PackageName + '/', "");
			if (NewEntry.RelativePath.size() > 254) { continue; }
			// Package name creation
			PackageEntrySort NewSort;
			if (PackageNamesTable.find(PackageName) != PackageNamesTable.end())
			{
				NewSort.PackageIndex = PackageNamesTable[PackageName];
			}
			else
			{
				NewSort.PackageIndex = PackageCounter;
				PackageNamesTable[PackageName] = PackageCounter;
				PackageNames.push_back(PackageName);
				PackageCounter++;
			}

			NewSort.ModTime = p.last_write_time().time_since_epoch().count();
			// Putting current file into the pool of other potential entries
			Entries.push_back(eastl::make_tuple(NewSort, NewEntry));
		}
		// Sorting entries by mod time in order to act like .zip by inserting new/modified stuff at the end of the
		// file while trying to somewhat keep delta to the minimum in the middle of the pack
		std::sort(Entries.begin(), Entries.end(), [](const std::tuple<PackageEntrySort, PackageEntry>& Left,
			const std::tuple<PackageEntrySort, PackageEntry>& Right) { return std::get<0>(Left).ModTime < std::get<0>(Right).ModTime; });

		// Splitting entries into packages per every type
		for (auto& Entry : Entries) { PackageEntries[PackageNames[std::get<0>(Entry).PackageIndex]].push_back(std::get<1>(Entry)); }
	}
	
	// Temp buffer for the file reading/writing
	std::vector<char> Buffer(1024);

	for (auto& Package : PackageEntries)
	{
		if (Package.second.size() == 0) { continue; }
		std::string PackagePath = Path + '/' + Package.first + ".upf";
		// Recreate package if already presented
		if (std::filesystem::exists(PackagePath)) { std::filesystem::remove(PackagePath); }

		std::ofstream PackageStream(PackagePath, std::ios_base::binary);

		// Magic number and version
		PackageStream.write("UPF", 3);
		PackageStream.write(&Version, 1);

		for (auto& Entry : Package.second)
		{
			// Writing file name size - 1 byte
			PackageStream << static_cast<unsigned char>(Entry.RelativePath.size());
			// Writing file name - ? bytes
			PackageStream.write(Entry.RelativePath.data(), Entry.RelativePath.size());
			// Opening the target file for the read
			std::ifstream FileData(Entry.FullPath, std::ifstream::binary);
			// Retrieving the file size
			FileData.seekg(0, std::ios_base::end);
			uint64_t FileSize = static_cast<uint64_t>(FileData.tellg());
			// Writing the file size - 8 bytes
			PackageStream.write(reinterpret_cast<const char*>(&FileSize), sizeof(uint64_t));
			FileData.seekg(0, std::ios_base::beg);
			// Reading target file with a buffer of 1024 bytes and writing to the output package
			while (!FileData.eof())
			{
				FileData.read(Buffer.data(), Buffer.size());
				std::streamsize s = FileData.gcount();
				PackageStream.write(Buffer.data(), s);
			}
			FileData.close();
		}
		PackageStream.close();
	}
}

void Filesystem::Unpack(const std::string& Path)
{
	// Creating temp buffer for file data
	std::vector<char> Buffer(1024);

	// Looping through every file in a target path
	for (auto& p : std::filesystem::directory_iterator(Path))
	{
		// Skip folder entries
		if (!p.is_regular_file()) { continue; }
		// Check if file is a package
		std::string PackagePath = Replace(p.path().string(), "\\", "/");
		if (!EndsWith(PackagePath, ".upf")) { continue; }
		// Setting up metadata
		std::string PackageName = Split(Split(PackagePath, '/').back(), '.')[0];
		std::string OutputFolder = Path + '/' + PackageName;
		// Recreate folder if already presented
		if (std::filesystem::exists(OutputFolder)) { std::filesystem::remove_all(OutputFolder); }
		// Opening the stream to package
		std::ifstream PackageStream(PackagePath, std::ios_base::binary);
		// Validating the package and getting the size
		auto PackageSize = ValidatePack(PackageStream, Buffer);
		if (PackageSize == 0) { continue; }
		// Loop until the end of the package or until successfull overflow attepmt
		while (PackageStream.tellg() < PackageSize)
		{
			// Reading the string size of the file path
			unsigned char StringSize;
			PackageStream.read(Buffer.data(), 1);
			std::memcpy(&StringSize, &Buffer[0], 1);
			// Reading the path of a file
			std::string FileName(static_cast<size_t>(StringSize), '\0');
			PackageStream.read(FileName.data(), StringSize);
			// Reading the size of a file
			uint64_t FileSize;
			PackageStream.read(Buffer.data(), 8);
			std::memcpy(&FileSize, &Buffer[0], 8);
			// Creating the output file that we are unpacking right now and also some additional metadata
			std::string CurrentFilePath = OutputFolder + '/' + FileName;
			std::filesystem::create_directories(std::filesystem::path(CurrentFilePath).parent_path());
			std::ofstream OutputFile(CurrentFilePath, std::ios_base::binary);
			// Looping and writing all the needed data
			while (FileSize != 0)
			{
				if (FileSize / 1024 != 0)
				{
					PackageStream.read(Buffer.data(), 1024);
					OutputFile.write(Buffer.data(), 1024);
					FileSize -= 1024;
				}
				else
				{
					PackageStream.read(Buffer.data(), FileSize);
					OutputFile.write(Buffer.data(), FileSize);
					break;
				}
			}
			// Closing the output stream
			OutputFile.close();
		}
		// Closing the package stream
		PackageStream.close();
	}
}

void Filesystem::AddSource(const std::string& Path, RootType TargetRootType)
{
	for (auto& p : std::filesystem::directory_iterator(Path))
	{
		RootType NewRootType;

		if (p.is_regular_file() && p.path().extension() == ".upf") { NewRootType = RootType::Package; }
		else if (p.is_directory()) { NewRootType = RootType::OS; }
		else { continue; }

		if (TargetRootType != NewRootType) { continue; }

		Root NewRoot;
		NewRoot.Path = Replace(p.path().string(), "\\", "/");
		NewRoot.Type = NewRootType;

		Roots[RootCounter] = NewRoot;

		if (NewRootType == RootType::OS) { AddDir(Path, RootCounter); }
		else { AddPack(Path, RootCounter); }

		RootCounter++;
	}
}

void Filesystem::AddDir(const std::string& RootParent, uint32_t RootIndex)
{
	std::string& Path = Roots[RootIndex].Path;

	for (auto& p : std::filesystem::recursive_directory_iterator(Path))
	{
		std::string EntryPath = Replace(Replace(p.path().string(), "\\", "/"), RootParent + '/', "");
		Entry NewEntry;
		NewEntry.RootIndex = RootIndex;
		uint64_t PathHash = Hash(EntryPath.data(), EntryPath.size(), 0);
		Entries[PathHash] = NewEntry;
	}
}

std::streampos Filesystem::ValidatePack(std::ifstream& PackStream, std::vector<char>& Buffer)
{
	// Getting the package size and returning non zero variable
	PackStream.seekg(0, std::ios_base::end);
	auto PackageSize = PackStream.tellg();
	PackStream.seekg(0, std::ios_base::beg);
	// Sanity check for package size
	if (PackageSize < 15) { return 0; }

	// Reading the magic number and validating
	PackStream.read(Buffer.data(), 3);
	if (Buffer[0] != 'U' || Buffer[1] != 'P' || Buffer[2] != 'F') { return 0; }

	// Reading the version and validating
	PackStream.read(Buffer.data(), 1);
	if (Version != Buffer[0]) { return 0; }

	return PackageSize;
}

void Filesystem::AddPack(const std::string& RootParent, uint32_t RootIndex)
{
	std::string& Path = Roots[RootIndex].Path;
	std::string PackageName = Split(Replace(Path, RootParent + '/', ""), '.')[0];

	std::vector<char> Buffer(256);

	std::ifstream* PackageStream = new std::ifstream(Path, std::ios_base::binary);

	auto PackageSize = ValidatePack(*PackageStream, Buffer);
	if (PackageSize == 0) { return; }

	while (PackageStream->tellg() < PackageSize)
	{
		Entry NewEntry;
		NewEntry.RootIndex = RootIndex;

		// Reading the string size of the file path
		unsigned char StringSize;
		PackageStream->read(Buffer.data(), 1);
		std::memcpy(&StringSize, &Buffer[0], 1);
		// Reading the path of a file
		std::string FileName(static_cast<size_t>(StringSize), '\0');
		PackageStream->read(FileName.data(), StringSize);
		std::string FilePath = PackageName + '/' + FileName;
		// Reading the size of a file
		uint64_t FileSize;
		PackageStream->read(Buffer.data(), 8);
		std::memcpy(&FileSize, &Buffer[0], 8);
		NewEntry.Size = FileSize;
		NewEntry.Offset = PackageStream->tellg();
		uint64_t PathHash = Hash(FilePath.data(), FilePath.size(), 0);
		Entries[PathHash] = NewEntry;
		// Ignoring actual file data
		PackageStream->ignore(NewEntry.Size);
	}
	
	PackageStreams[RootIndex] = PackageStream;
}

std::vector<char> Filesystem::GetFile(const std::string& FilePath)
{
	uint64_t FileNameHash = Hash(FilePath.data(), FilePath.size(), 0);

	if (Entries.find(FileNameHash) != Entries.end())
	{
		Entry& TargetEntry = Entries[FileNameHash];
		Root& TargetRoot = Roots[TargetEntry.RootIndex];
		std::vector<char> Buffer(TargetEntry.Size);
		
		if (TargetRoot.Type == RootType::OS)
		{
			std::ifstream InputStream(TargetRoot.Path + Replace(FilePath, Split(FilePath, '/')[0], ""), std::ios_base::binary);
			InputStream.read(Buffer.data(), TargetEntry.Size);
			InputStream.close();
		}
		else
		{
			std::ifstream* InputStream = PackageStreams[TargetEntry.RootIndex];
			InputStream->seekg(TargetEntry.Offset);
			InputStream->read(Buffer.data(), TargetEntry.Size);
		}

		return Buffer;
	}
	else
	{
		return {};
	}
}

*/