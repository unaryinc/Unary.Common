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
#include <EASTL/vector.h>
#include <EASTL/tuple.h>

namespace Unary::Shear::Core
{
	class StringHashes
	{
		private:

			eastl::unordered_map<uint64_t, eastl::string> Hashes;
			eastl::vector<eastl::tuple<uint64_t, eastl::string, eastl::string>> Duplicates;

		public:

			StringHashes() {};
			~StringHashes() {};

			uint64_t GetString(const eastl::string& String)
			{
				uint64_t Hash = Utils::Murmur::Str(String);

				if (Hashes.find(Hash) == Hashes.end())
				{
					Hashes[Hash] = String;
				}
				else if(Hashes[Hash] != String)
				{
					Duplicates.push_back(eastl::make_tuple(Hash, Hashes[Hash], String));
				}

				return Hash;
			}

			uint64_t GetCString(const char* String, int32_t Length)
			{
				eastl::string NewString(String, Length);
				uint64_t Hash = Utils::Murmur::Str(NewString);

				if (Hashes.find(Hash) == Hashes.end())
				{
					Hashes[Hash] = NewString;
				}
				else if(Hashes[Hash] != NewString)
				{
					Duplicates.push_back(eastl::make_tuple(Hash, Hashes[Hash], NewString));
				}

				return Hash;
			}
	};
}