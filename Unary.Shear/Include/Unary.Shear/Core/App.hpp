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
#include <EASTL/unordered_map.h>
#include <EASTL/memory.h>
#include <EASTL/vector.h>
#include <EASTL/algorithm.h>

#ifdef SHEAR_DEBUG
#include <Unary.Shear/Core/StringHashes.hpp>
#else
#include <Unary.Shear/Utils/Murmur.hpp>
#endif

#include <Unary.Shear/Core/Singletone.hpp>

#include <Unary.Shear/Core/Logger.hpp>
#include <Unary.Shear/Core/Events.hpp>

#include <Unary.Shear/Core/Object.hpp>
#include <Unary.Shear/Core/Variable.hpp>

#include <Unary.Shear/Utils/TypeAccessor.hpp>
#include <Unary.Shear/Utils/String.hpp>

namespace Unary::Shear::Core
{
	class Object;

	class App
	{
		private:

			static App* Instance;

			eastl::unordered_map<eastl::string, Object*> Systems;
			eastl::vector<eastl::string> Order;
			#ifdef SHEAR_DEBUG
			StringHashes Hashes;
			#endif

			void AddSys(eastl::vector<eastl::string>& Args);

		public:

			int ReturnCode = 0;
			bool Running = true;
			Logger Log;
			Events Event;

			App() : Log(&ReturnCode)
			{};

			~App() {};

			App(App& AnotherApp) = delete;
			void operator=(const App&) = delete;
			static App* Get()
			{
				if (Instance = nullptr)
				{
					Instance = new App();
				}
				return Instance;
			}

			#ifdef _WIN32
			void Init(int argc, wchar_t* argv[])
			{
				eastl::vector<eastl::string> Arguments;
				for (int i = 0; i < argc; ++i)
				{
					Arguments.push_back(Utils::String::U16ToU8(argv[i]));
				}
				AddSys(Arguments);
			}
			#else
			void Init(int argc, char* argv[])
			{
				eastl::vector<eastl::string> Arguments;
				for (int i = 0; i < argc; ++i)
				{
					Arguments.push_back(argv[i]);
				}
				AddSys(Arguments);
			}
			#endif

			uint64_t Hash(const eastl::string& String)
			{
				#ifdef SHEAR_DEBUG
				return Hashes.GetString(String);
				#else
				return Utils::Murmur::Str(String);
				#endif
			}

			uint64_t Hash(const char* String, int32_t Length)
			{
				#ifdef SHEAR_DEBUG
				return Hashes.GetCString(String, Length);
				#else
				return Utils::Murmur::Ptr(String, Length);
				#endif
			}

			bool Run();

			void Clear();

			template <typename T>
			T* AddSystem();

			template <typename T>
			T* GetSystem();
	};
}