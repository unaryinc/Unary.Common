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

#include <string>
#include <vector>

#include <Unary.Make/Utils/Static.hpp>

namespace Unary::Make::Structs
{
    struct DepotFlags
    {
        std::vector<std::string> Release;
        std::vector<std::string> Debug;

        std::string GetString()
        {
            std::string Result = "Release: ";

            size_t ReleaseSize = Release.size();
            for(size_t i = 0; i < ReleaseSize; ++i)
            {
                Result += Release[i];
                if(i != ReleaseSize - 1)
                {
                    Result += ',';
                }
            }

            Result += Utils::Static::NewLine + "Debug: ";

            size_t DebugSize = Release.size();
            for(size_t i = 0; i < DebugSize; ++i)
            {
                Result += Debug[i];
                if(i != DebugSize - 1)
                {
                    Result += ',';
                }
            }

            return Result;
        }
    };
}