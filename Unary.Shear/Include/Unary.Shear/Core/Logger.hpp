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

#ifdef _WIN32
#include <Windows.h>
#include <Unary.Shear/Utils/String.hpp>
#else

#endif

#include <EASTL/string.h>
#include <Unary.Shear/Core/App.hpp>

namespace Unary::Shear::Core
{
	class Logger
	{
		private:

		#ifdef _WIN32
			HANDLE Handle;
			eastl::wstring Buffer;
		#else

		#endif

			int* ReturnCode;

		public:

			Logger(int* ReturnPtr) : ReturnCode(ReturnPtr)
			{
				#ifdef _WIN32
				Handle = GetStdHandle(STD_OUTPUT_HANDLE);
				#else

				#endif
			}

			~Logger()
			{

			}

			void Message(const eastl::string& Text)
			{
				#ifdef _WIN32
				SetConsoleTextAttribute(Handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				Buffer = Utils::String::U8ToU16(Text);
				wprintf(L"%.*s\n", static_cast<uint32_t>(Buffer.length()), Buffer.c_str());
				#else

				printf("%.*s\n", static_cast<uint32_t>(Text.length()), Text.c_str());
				#endif
			}

			void Warning(const eastl::string& Text)
			{
				#ifdef _WIN32
				SetConsoleTextAttribute(Handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Buffer = Utils::String::U8ToU16(Text);
				wprintf(L"%.*s\n", static_cast<uint32_t>(Buffer.length()), Buffer.c_str());
				#else

				printf("%.*s\n", static_cast<uint32_t>(Text.length()), Text.c_str());
				#endif
			}
			
			void Error(const eastl::string& Text)
			{
				#ifdef _WIN32
				SetConsoleTextAttribute(Handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
				Buffer = Utils::String::U8ToU16(Text);
				wprintf(L"%.*s\n", static_cast<uint32_t>(Buffer.length()), Buffer.c_str());
				#else

				printf("%.*s\n", static_cast<uint32_t>(Text.length()), Text.c_str());
				#endif
			}

			void Panic(const eastl::string& Text)
			{
				#ifdef _WIN32
				SetConsoleTextAttribute(Handle, FOREGROUND_RED);
				Buffer = Utils::String::U8ToU16(Text);
				wprintf(L"%.*s\n", static_cast<uint32_t>(Buffer.length()), Buffer.c_str());
				MessageBox(nullptr, Text.c_str(), "Shear Panic", MB_OK);
				#else

				printf("%.*s\n", static_cast<uint32_t>(Text.length()), Text.c_str());
				#endif
				*ReturnCode = 1;
			}
	};
}