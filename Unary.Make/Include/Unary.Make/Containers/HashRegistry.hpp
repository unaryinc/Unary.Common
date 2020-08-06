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

#include <vector>
#include <unordered_map>
#include <string>
#include <optional>

#include <Unary.Make/Utils/Murmur.hpp>

namespace Unary::Make::Containers
{
    template<class V>
    class HashRegistry
    {
        private:
        
            std::unordered_map<uint64_t, V> Values;
        
        public:

            std::optional<uint64_t> Add(V Value)
            {
                uint64_t Hash = Murmur::Hash(Value.begin(), Value.length(), 0);

                std::optional<uint64_t> Result;

                if(Values.find(Hash) == Values.end())
                {
                    Result.value = Hash;
                    Values[Hash] = Value;
                }

                return Result;
            }

            std::optional<V> Get(uint64_t Key)
            {
                std::optional<V> Result;

                if(Values.find(Key) != Values.end())
                {    
                    Result.value = Values[Key];    
                }

                return Result;
            }

            bool Remove(uint64_t Key)
            {
                if(Values.find(Key) != Values.end())
                {
                    Values.erase(Key);
                    return true;
                }
                
                return false;
            }
            
    };

    typedef HashRegistry<std::string> StringHashRegistry;
}