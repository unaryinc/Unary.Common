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

#include <Unary.Shear/Core/App.hpp>
#include <EASTL/string.h>
#include <Unary.Shear/Utils/Murmur.hpp>
#include <cstdint>

namespace Unary::Shear::Core
{
    class App;

    class Type
    {
        public:

            explicit Type(const char* NewName, const Type* NewBaseType);
            ~Type();

            bool IsTypeOf(uint64_t type) const;
            bool IsTypeOf(const Type* Type) const;
            template<typename T>
            bool IsTypeOf() const { return IsTypeOf(T::GetTypeStatic()); }
            uint64_t GetHash() const { return Hash; }
            const eastl::string& GetName() const { return Name; }
            const Type* GetBaseType() const { return BaseType; }

        private:

            uint64_t Hash;
            eastl::string Name;
            const Type* BaseType;
    };

#define ShearCTTI(ObjectName, BaseName) \
virtual uint64_t GetHash() const override { return GetTypeStatic()->GetHash(); } \
virtual const eastl::string& GetName() const override { return GetTypeStatic()->GetName(); } \
virtual const Unary::Shear::Core::Type* GetType() const override { return GetTypeStatic(); } \
static uint64_t GetHashStatic() { return GetTypeStatic()->GetHash(); } \
static const eastl::string& GetNameStatic() { return GetTypeStatic()->GetName(); } \
static const Unary::Shear::Core::Type* GetTypeStatic() { static const Unary::Shear::Core::Type TypeStatic(#ObjectName, BaseName::GetTypeStatic()); return &TypeStatic; }

}