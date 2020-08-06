#include <Unary.Make/Systems/Build.hpp>

namespace Unary::Make::Systems
{
    void Build::ParseBuild(const std::string& Path)
    {
        FILE* File = fopen(Path.data(), "r");

        char readBuffer[65536];
        rapidjson::FileReadStream Stream(File, readBuffer, sizeof(readBuffer));

        rapidjson::Document Document;
        Document.ParseStream(Stream);

        fclose(File);

        
    }
}