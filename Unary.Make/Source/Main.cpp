#include <iostream>
#include <vector>
#include <string>

#include <Variable.hpp>

using namespace Unary::Make;

// Unary.Make.exe g++ Make.unary

int main(int argc, char *argv[])
{
    std::vector<std::string> Arguments;
 
    for(int i = 0; i < argc; ++i)
    {
        Arguments.push_back(argv[i]);
    }

    std::cout << "Test" << std::endl;

    Variable Test;
    Test.Test();
}