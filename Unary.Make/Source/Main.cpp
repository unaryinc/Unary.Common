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

#include <iostream>
#include <vector>
#include <string>

#include <Unary.Make/Systems/System.hpp>
#include <Unary.Make/Enums/ErrorCode.hpp>

using namespace Unary::Make;

int main(int argc, char *argv[])
{
    try
    {
        std::vector<std::string> Arguments;

        for(int i = 0; i < argc; ++i)
        {
            Arguments.push_back(argv[i]);
        }

        Systems::Sys NewSys;

        NewSys.Init();
        NewSys.Run(&Arguments);
        NewSys.Clear();

        return static_cast<int>(Enums::ErrorCode::Ok);
    }
    catch(std::exception& e)
    {
        std::cout << "An unhandled exception occured: " << e.what() << std::endl;
        return static_cast<int>(Enums::ErrorCode::GenericError);
    }
    
}