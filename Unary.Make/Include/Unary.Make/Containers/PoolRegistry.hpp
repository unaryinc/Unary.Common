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
#include <string>

#include <Unary.Make/Enums/ErrorCode.hpp>
#include <Unary.Make/Containers/Optional.hpp>

namespace Unary::Make::Containers
{
    template<class T>
    class PoolRegistry
    {
        private:
            
            uint64_t Counter = 0;
            std::vector<uint64_t> Cache;
            std::unordered_map<uint64_t, T*> Values;

        public:

            uint64_t Add()
            {
                uint64_t Result;

                if(Cache.size() != 0)
                {
                    Result = Cache[0];
                    Cache.erase(Cache.begin());
                    Values[Result] = new T();
                }
                else
                {
                    Result = Counter;
                    Values[Result] = new T();
                    Counter++;
                }

                return Result;
            }

            Containers::Optional<T*> Get(uint64_t Index)
            {
                Containers::Optional<T*> Result;

                if(Values.find(Index) != Values.end())
                {
                    Result.Code = Enums::ErrorCode::Ok;
                    Result.Value = Values[Index];
                }
                else
                {
                    Result.Code = Enums::ErrorCode::DoesNotExist;
                    Result.Value = nullptr;
                }
                
                return Result;
            }

            Enums::ErrorCode Remove(uint64_t Index)
            {
                if(Values.find(Index) != Values.end())
                {
                    Cache.push_back(Index);
                    delete Values[Index];
                    Values.erase(Index);
                    return Enums::ErrorCode::Ok;
                }
                else
                {
                    return Enums::ErrorCode::DoesNotExist;
                }
            }
    };

    typedef PoolRegistry<std::string> StringPoolRegistry;
    typedef PoolRegistry<uint64_t> UInt64PoolRegistry;
    typedef PoolRegistry<bool> BoolPoolRegistry;
}