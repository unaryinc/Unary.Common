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

#include <Unary.Make/Structs/DepotID.hpp>

namespace Unary::Make::Structs
{
    struct BuildID
    {
        // Depot identifier
        DepotID ID;

        // Is this build a debug build
        bool Type;

        // Hash used per build if sourcecode pathing was involved
        uint64_t Hash;

        std::string GetString()
        {
            std::string Result = ID.GetString();

            if(Type)
            {
                Result += ".Debug.";
            }
            else
            {
                Result += ".Release.";
            }

            if(Hash != 0)
            {
                Result += std::to_string(Hash);
            }

            return Result;
        }
    };
}