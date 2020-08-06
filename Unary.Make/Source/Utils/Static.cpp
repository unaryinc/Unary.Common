#include <Unary.Make/Utils/Static.hpp>

namespace Unary::Make::Utils
{
    std::unordered_map<std::string, Enums::DepotType> Static::DepotTypes =
    {
        { "Headers", Enums::DepotType::Headers },
        { "Sources", Enums::DepotType::Sources },
        { "Binaries", Enums::DepotType::Binaries },
        { "Data", Enums::DepotType::Data}
    };

    #ifdef _WIN32
        std::string Static::NewLine = "\r\n";
        std::string Static::OS = "Windows";
        std::string Static::RuntimeExtension = ".dll";
        std::string Static::LibraryExtension = ".a";
    #elif
        std::string Static::NewLine = '\n';
        std::string Static::OS = "Linux";
        std::string Static::RuntimeExtension = ".so";
        std::string Static::LibraryExtension = ".a";
    #endif
}