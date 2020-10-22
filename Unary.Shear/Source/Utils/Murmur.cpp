#include <Unary.Shear/Utils/Murmur.hpp>

namespace Unary::Shear::Utils::Murmur
{
    uint64_t Ptr(const void* Data, uint64_t Length, uint64_t Seed)
    {
        const uint64_t Const = 0xc6a4a7935bd1e995LLU;
        const int Offset = 47;

        uint64_t Hash = Seed ^ (Length * Const);

        const uint64_t* DataBegin = static_cast<const uint64_t*>(Data); //-V206
        const uint64_t* DataEnd = DataBegin + (Length / 8);

        while (DataBegin != DataEnd)
        {
            uint64_t Key = *DataBegin++;

            Key *= Const;
            Key ^= Key >> Offset;
            Key *= Const;

            Hash ^= Key;
            Hash *= Const;
        }

        const unsigned char* DataSecond = reinterpret_cast<const unsigned char*>(DataBegin); //-V206

        switch (Length & 7)
        {
        case 7:
            Hash ^= static_cast<uint64_t>(DataSecond[6]) << 48;
            [[fallthrough]];
        case 6:
            Hash ^= static_cast<uint64_t>(DataSecond[5]) << 40;
            [[fallthrough]];
        case 5:
            Hash ^= static_cast<uint64_t>(DataSecond[4]) << 32; //-V112
            [[fallthrough]];
        case 4:
            Hash ^= static_cast<uint64_t>(DataSecond[3]) << 24;
            [[fallthrough]];
        case 3:
            Hash ^= static_cast<uint64_t>(DataSecond[2]) << 16;
            [[fallthrough]];
        case 2:
            Hash ^= static_cast<uint64_t>(DataSecond[1]) << 8;
            [[fallthrough]];
        case 1:
            Hash ^= static_cast<uint64_t>(DataSecond[0]);
            Hash *= Const;
        };

        Hash ^= Hash >> Offset;
        Hash *= Const;
        Hash ^= Hash >> Offset;

        return Hash;
    }

    uint64_t Str(const eastl::string& String, uint64_t Seed)
    {
        return Ptr(String.data(), String.length(), Seed);
    }
}