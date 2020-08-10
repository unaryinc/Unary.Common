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

#include <stdint.h>
#include <string>
#include <filesystem>

#include <Unary.Make/Systems/System.hpp>

namespace Unary::Make::Systems
{
    DeclareSystem(SourceCode)
    {
        public:

            DeclareType(Unary::Make::Systems::SourceCode)

            void Init()
            {
                OutputDocument.SetObject();
            }

            rapidjson::Document& GetDocument()
            {
                return OutputDocument;
            }

            void Clear()
            {
                if(OutputDocument.MemberBegin() == OutputDocument.MemberEnd())
                {
                    OutputDocument.AddMember("Error", "Output is empty", OutputDocument.GetAllocator());
                }

                if(std::filesystem::exists("Output.json"))
                {
                    std::filesystem::remove("Output.json");
                }

                FILE* File = fopen("Output.json", "w");

                char Buffer[65536];
                rapidjson::FileWriteStream Stream(File, Buffer, sizeof(Buffer));
 
                rapidjson::PrettyWriter<rapidjson::FileWriteStream> Writer(Stream);
                OutputDocument.Accept(Writer);

                fclose(File);
            }
    };
}