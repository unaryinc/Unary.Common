#include <Unary.Make/Systems/Depots.hpp>

namespace Unary::Make::Systems
{
    bool Depots::ParseDepot(const std::string& Path)
    {
        FILE* File = fopen(Path.data(), "r");

        char readBuffer[65536];
        rapidjson::FileReadStream Stream(File, readBuffer, sizeof(readBuffer));

        rapidjson::Document Document;
        Document.ParseStream(Stream);

        fclose(File);

        Structs::DepotManifest NewManifest;

        const std::string& OS = Utils::Static::OS;
        auto DepotTypes = Utils::Static::DepotTypes;

       std::string NewType = Document["Type"].GetString();

        if(DepotTypes.find(NewType) == DepotTypes.end())
        {
            return false;
        }

        NewManifest.Type = DepotTypes[NewType];
        NewManifest.ID.Author = Document["Author"].GetString();
        NewManifest.ID.Name = Document["Name"].GetString();
        NewManifest.ID.Version = Document["Version"].GetString();
        
        if(NewManifest.Type == Enums::DepotType::Data)
        {  
            auto ReleaseObj = Document["Data"][OS.data()]["Release"].GetObject();
            for(auto Ittr = ReleaseObj.MemberBegin(); Ittr != ReleaseObj.MemberEnd(); ++Ittr)
            {
                NewManifest.Variables.Release[Ittr->name.GetString()] = Ittr->value.GetString();
            }

            auto DebugObj = Document["Data"][OS.data()]["Debug"].GetObject();
            for(auto Ittr = DebugObj.MemberBegin(); Ittr != DebugObj.MemberEnd(); ++Ittr)
            {
                NewManifest.Variables.Debug[Ittr->name.GetString()] = Ittr->value.GetString();
            }
            return true;
        }
        else if(NewManifest.Type == Enums::DepotType::Binaries)
        {
            NewManifest.Binaries.ReleaseLibrary = Document["Binaries"][OS.data()]["Release"]["Library"].GetString();
            NewManifest.Binaries.ReleaseRuntime = Document["Binaries"][OS.data()]["Release"]["Runtime"].GetString();
            NewManifest.Binaries.DebugLibrary = Document["Binaries"][OS.data()]["Debug"]["Library"].GetString();
            NewManifest.Binaries.DebugRuntime = Document["Binaries"][OS.data()]["Debug"]["Runtime"].GetString();
        }
        else if(NewManifest.Type == Enums::DepotType::Sources)
        {
            NewManifest.Sources = Document["Sources"].GetString();
        }

        for(const auto& Variable : Document["Flags"][OS.data()]["Release"].GetArray())
        {
            NewManifest.Flags.Release.push_back(Variable.GetString());
        }
        for(const auto& Variable : Document["Flags"][OS.data()]["Debug"].GetArray())
        {
            NewManifest.Flags.Debug.push_back(Variable.GetString());
        }

        if(Document.HasMember("Patches"))
        {
            std::vector<Structs::DepotPatch> NewPatches;

            for(const auto& Patch : Document["Patches"].GetArray())
            {
                Structs::DepotPatch NewPatch;
                NewPatch.ID.Author = Patch["Author"].GetString();
                NewPatch.ID.Name = Patch["Name"].GetString();
                NewPatch.ID.Version = Patch["Version"].GetString();
                NewPatch.Path = Patch["Path"].GetString();
                NewPatches.push_back(NewPatch);
            }

            NewManifest.Patches.Patches = NewPatches;
        }

        NewManifest.Headers = Document["Headers"].GetString();

        Depots[NewManifest.GetString()] = NewManifest;

        return true;
    }
}