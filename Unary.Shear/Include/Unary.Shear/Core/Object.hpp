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

#include <cstdint>
#include <functional>
#include <string>
#include <EASTL/string.h>
#include <EASTL/unordered_map.h>

#include <Unary.Shear/Core/Events.hpp>
#include <Unary.Shear/Core/Type.hpp>
#include <Unary.Shear/Core/App.hpp>
#include <Unary.Shear/Core/Variable.hpp>


namespace Unary::Shear::Core
{
    class Events;
	class App;
    class Variable;
    class Type;

	class Object
	{
        protected:

            App* AppPtr;

        private:

            eastl::unordered_map<uint64_t, eastl::vector<std::function<void(eastl::unordered_map<uint64_t, Variable>&)>>> Binds;

		public:

			explicit Object();
			~Object();

            virtual uint64_t GetHash() const = 0;
            virtual const eastl::string& GetName() const = 0;
            virtual const Type* GetType() const = 0;
            static const Type* GetTypeStatic() { return nullptr; }

            bool IsInstanceOf(uint64_t Hash) const;
            bool IsInstanceOf(const Type* Type) const;

            void Subscribe(const char* EventName, std::function<void(eastl::unordered_map<uint64_t, Variable>&)> Target);
            void Invoke(uint64_t Hash, eastl::unordered_map<uint64_t, Variable>& Args);

            template<typename T> 
            bool IsInstanceOf() const 
            {
                return IsInstanceOf(T::GetTypeStatic()); 
            }

            template<typename T> 
            T* Cast()
            {
                return IsInstanceOf<T>() ? static_cast<T*>(this) : nullptr; 
            }

            template<typename T> 
            const T* Cast() const 
            {
                return IsInstanceOf<T>() ? static_cast<const T*>(this) : nullptr; 
            }
	};

#define ShearSubscribe(EventName, Function) Subscribe(AppPtr->Subscribe(#EventName, this), std::bind(&Function, this, std::placeholders::_1));
}