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

#include <Unary.Make/Utils/Murmur.hpp>

namespace Unary::Make::Utils::Murmur
{
    uint64_t Hash(const uint64_t* Data, uint64_t Length, uint64_t Seed)
    {
        const uint64_t Const = 0xc6a4a7935bd1e995LLU;
        const int Offset = 47;
        
        uint64_t Hash = Seed ^ (Length * Const);

        const uint64_t* DataBegin = Data;
        const uint64_t* DataEnd = DataBegin + (Length / 8);

        while(DataBegin != DataEnd)
        {
            uint64_t Key = *DataBegin++;

            Key *= Const; 
            Key ^= Key >> Offset; 
            Key *= Const; 
        
            Hash ^= Key;
            Hash *= Const; 
        }

        const uint64_t* DataSecond = DataBegin;

        switch(Length & 7)
        {
            case 7: 
                Hash ^= static_cast<uint64_t>(DataSecond[6]) << 48;
            case 6: 
                Hash ^= static_cast<uint64_t>(DataSecond[5]) << 40;
            case 5: 
                Hash ^= static_cast<uint64_t>(DataSecond[4]) << 32; //-V112
            case 4: 
                Hash ^= static_cast<uint64_t>(DataSecond[3]) << 24;
            case 3: 
                Hash ^= static_cast<uint64_t>(DataSecond[2]) << 16;
            case 2: 
                Hash ^= static_cast<uint64_t>(DataSecond[1]) << 8;
            case 1: 
                Hash ^= static_cast<uint64_t>(DataSecond[0]);
                Hash *= Const;
        };

        Hash ^= Hash >> Offset;
        Hash *= Const;
        Hash ^= Hash >> Offset;

        return Hash;
    }
}