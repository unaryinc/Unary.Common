#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <iterator>

#include <Unary.Make/Enums/ReturnCode.hpp>
#include <Unary.Make/Utils/Murmur.hpp>
//#include <Unary.Make/Units/DepotID.hpp>

using namespace Unary::Make::Enums;

// Unary.Make.exe Make.unary


int main(int argc, char *argv[])
{
    std::vector<std::string> Arguments;

    for(int i = 0; i < argc; ++i)
    {
        Arguments.push_back(argv[i]);
    }
    
/*
    if(Arguments.size() < 2)
    {
        return static_cast<int>(ReturnCode::InvalidArgumentCount);
    }
*/
    
    return static_cast<int>(ReturnCode::Ok);
}