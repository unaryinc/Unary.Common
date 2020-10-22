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

#include <EASTL/string.h>
#include <Unary.Shear/Systems/Sys.hpp>
#include <Unary.Shear/Utils/Murmur.hpp>

namespace Unary::Shear::Systems
{

    class System
    {
        public:
            Sys* SysPtr = nullptr;

            virtual void Init() = 0;
            virtual void Clear() = 0;
    };

#define URHO3D_OBJECT(typeName, baseTypeName) \
        virtual uint64_t GetHash() const override { return GetTypeInfoStatic()->GetHash(); } \
        virtual const eastl::string& GetName() const override { return GetTypeInfoStatic()->GetName(); } \
        virtual const Urho3D::TypeInfo* GetTypeInfo() const override { return GetTypeInfoStatic(); } \
        static uint64_t GetHashStatic() { return GetTypeInfoStatic()->GetHash(); } \
        static const Urho3D::String& GetTypeNameStatic() { return GetTypeInfoStatic()->GetTypeName(); } \
        static const Urho3D::TypeInfo* GetTypeInfoStatic() { static const Urho3D::TypeInfo typeInfoStatic(#typeName, BaseClassName::GetTypeInfoStatic()); return &typeInfoStatic; }
}