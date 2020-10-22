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

#include <Unary.Shear/Core/Object.hpp>

namespace Unary::Shear::Core
{
	Object::Object() : AppPtr(App::Get())
	{

	}

	Object::~Object()
	{
		AppPtr->Event.Unsubscribe(this);
	}

	void Object::Subscribe(const char* EventName, std::function<void(eastl::unordered_map<uint64_t, Variable>&)> Target)
	{
		uint64_t Hash = AppPtr->Hash(EventName, std::char_traits<char>::length(EventName));
		AppPtr->Event.Subscribe(Hash, this);
		Binds[Hash].push_back(Target);
	}

	void Object::Invoke(uint64_t Hash, eastl::unordered_map<uint64_t, Variable>& Args)
	{
		for (auto& Bind : Binds[Hash])
		{
			Bind(Args);
		}
	}

	bool Object::IsInstanceOf(uint64_t Hash) const
	{
		return GetType()->IsTypeOf(Hash);
	}

	bool Object::IsInstanceOf(const Type* Type) const
	{
		return GetType()->IsTypeOf(Type);
	}
}