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

#include <Unary.Make/Systems/Sys.hpp>

#include <Unary.Make/Systems/Arguments.hpp>
#include <Unary.Make/Systems/TempFiles.hpp>

namespace Unary::Make::Systems
{
	void Sys::Init()
	{
		Modules = new std::unordered_map<std::string, System*>();
		Order = new std::vector<std::string>();
	}

	void Sys::Clear()
	{
		for (int i = Order->size() - 1; i >= 0; --i)
		{
			Modules->operator[](Order->operator[](i))->Clear();
			Delete(Modules->operator[](Order->operator[](i)));
			Modules->erase(Order->operator[](i));
			Order->erase(Order->begin() + i);
		}

		Delete(Order);
		Delete(Modules);
	}

	void Sys::Run(std::vector<std::string>* Args)
	{
		Add<Arguments>();
		Get<Arguments>()->Set(Args);

		Add<TempFiles>();
	}

	template<typename T>
	T* Sys::Add()
	{
		std::string TypeName = Utils::TypeAccessor<T>().GetType();
		if (Modules->find(TypeName) != Modules->end())
		{
			std::cout << "Module " + TypeName + " is already registered." << std::endl;
			return nullptr;
		}
		Modules->operator[](TypeName) = new T();
		Order->push_back(TypeName);
		(*Modules)[TypeName]->SysPtr = this;
		(*Modules)[TypeName]->Init();
		return static_cast<T*>((*Modules)[TypeName]);
	}

	template<typename T>
	T* Sys::Get()
	{
		std::string TypeName = Utils::TypeAccessor<T>().GetType();

		auto Itr = Modules->find(TypeName);
		
		if (Itr == Modules->end())
		{
			std::cout << "Could not find module " + TypeName + " ." << std::endl;
			return nullptr;
		}
		else
		{
			return static_cast<T*>(Itr->second);
		}
	}
}