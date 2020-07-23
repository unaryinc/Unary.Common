#include <Unary.Make/Utils/Murmur.hpp>

namespace Unary::Make::Murmur
{
    uint64_t Hash(const void* Data, int Length, uint64_t Seed)
    {
        const uint64_t Const = 0xc6a4a7935bd1e995LLU;
        const int Offset = 47;
        
        uint64_t Hash = Seed ^ (Length * Const);

        const uint64_t* DataBegin = (const uint64_t*)Data;
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

        const unsigned char* DataSecond = (const unsigned char*)DataBegin;

        switch(Length & 7)
        {
            case 7: 
                Hash ^= uint64_t(DataSecond[6]) << 48;
            case 6: 
                Hash ^= uint64_t(DataSecond[5]) << 40;
            case 5: 
                Hash ^= uint64_t(DataSecond[4]) << 32;
            case 4: 
                Hash ^= uint64_t(DataSecond[3]) << 24;
            case 3: 
                Hash ^= uint64_t(DataSecond[2]) << 16;
            case 2: 
                Hash ^= uint64_t(DataSecond[1]) << 8;
            case 1: 
                Hash ^= uint64_t(DataSecond[0]);
                Hash *= Const;
        };

        Hash ^= Hash >> Offset;
        Hash *= Const;
        Hash ^= Hash >> Offset;

        return Hash;
    }
}