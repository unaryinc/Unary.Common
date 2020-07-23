#pragma once

#include <stdint.h>

namespace Unary::Make::Murmur
{
    uint64_t Hash(const void* Data, int Length, uint64_t Seed);
}