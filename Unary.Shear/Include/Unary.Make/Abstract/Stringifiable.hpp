#pragma once

#include <string>

namespace Unary::Make::Abstract
{
    class Stringifiable
    {
        public:
            virtual std::string GetString() = 0;
    };
}