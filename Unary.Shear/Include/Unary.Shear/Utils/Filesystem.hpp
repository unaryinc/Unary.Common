/*
MIT License

Copyright (c) 2020 Unary Incorporated

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

/*

#include <EASTL/vector.h>
#include <EASTL/string.h>
#include <EASTL/unordered_map.h>
#include <filesystem>
#include <iostream>
#include <EASTL/tuple.h>
#include <fstream>
#include <EASTL/chrono.h>
#include <EASTL/array.h>

#include <Unary.Shear/Utils/String.hpp>
#include <Unary.Shear/Utils/Murmur.hpp>

using namespace Unary::Shear;

class Filesystem
{
	public:

		enum class RootType : uint8_t
		{
			Package,
			OS
		};

	private:

		struct Root
		{
			RootType Type = RootType::OS;
			eastl::string Path;
		};

		struct Entry
		{
			uint32_t RootIndex;
			std::streampos Offset;
			uint64_t Size;
		};

		struct PackageEntrySort
		{
			uint64_t ModTime = 0;
			uint32_t PackageIndex = 0;
		};

		struct PackageEntry
		{
			eastl::string FullPath;
			eastl::string RelativePath;
		};

		uint32_t RootCounter = 0;
		eastl::unordered_map<uint32_t, std::ifstream*> PackageStreams;
		eastl::unordered_map<uint32_t, Root> Roots;
		eastl::unordered_map<uint64_t, Entry> Entries;

		const char Version = '\0';

		void AddDir(const eastl::string& RootParent, uint32_t RootIndex);
		std::streampos ValidatePack(std::ifstream& PackStream, eastl::vector<char>& Buffer);
		void AddPack(const eastl::string& RootParent, uint32_t RootIndex);

	public:

		~Filesystem();

		void Pack(const eastl::string& Path);
		void Unpack(const eastl::string& Path);

		void AddSource(const eastl::string& Path, RootType TargetRootType);

		eastl::vector<char> GetFile(const eastl::string& FilePath);
};

*/