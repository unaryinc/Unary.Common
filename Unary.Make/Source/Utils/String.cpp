#include <Unary.Make/Utils/String.hpp>

namespace Unary::Make::Utils::String
{
    std::vector<std::string> Split(const std::string& Value, const char& Delimiter)
    {
        std::vector<std::string> Parts;
        std::istringstream StringStream(Value);
        std::string Temp;
        
        while (std::getline(StringStream, Temp, Delimiter)) 
        {
            Parts.push_back(Temp);
        }

        return Parts;
    }
}