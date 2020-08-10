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

#include <unordered_map>
#include <fstream>
#include <cstdint>
#include <filesystem>

#include <Unary.Make/Systems/System.hpp>
#include <Unary.Make/Containers/PoolRegistry.hpp>

namespace Unary::Make::Systems
{
    DeclareSystem(TempFiles)
    {
        private:

            Containers::PoolRegistry<std::ofstream> Registry;
            std::string Path = "../Temp/Unary.Make/";

        public:

            DeclareType(Unary::Make::Systems::TempFiles)

            void Init();

            void Clear();
            
            uint64_t Create()
            {
                uint64_t Result = Registry.Add();
                return Result;
            }

            bool Open(uint64_t Value)
            {
                if(Registry.Get(Value).has_value())
                {
                    Registry.Get(Value).value()->open(Path + std::to_string(Value));
                    return true;
                }

                return false;
            }

            std::optional<std::ofstream*> Get(uint64_t Value)
            {
                return Registry.Get(Value);
            }

            bool Close(uint64_t Value)
            {
                if(Registry.Get(Value).has_value())
                {
                    Registry.Get(Value).value()->close();
                    return true;
                }

                return false;
            }

            bool Remove(uint64_t Value)
            {
                if(Registry.Get(Value).has_value())
                {
                    std::filesystem::remove(Path + std::to_string(Value));
                    return Registry.Remove(Value);
                }
                
                return false;
            }
    };
}