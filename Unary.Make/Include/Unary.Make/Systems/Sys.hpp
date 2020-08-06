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

#include <string>
#include <unordered_map>
#include <iostream>
#include <memory>
#include <any>
#include <vector>
#include <algorithm>

#include <Unary.Make/Systems/System.hpp>
#include <Unary.Make/Utils/TypeAccessor.hpp>


namespace Unary::Make::Systems
{
	class System;

	class Sys
	{
		private:

			std::unordered_map<std::string, System*> Modules;
			std::vector<std::string> Order;

		public:

			void Init()
			{
				
			}

			bool Run(std::vector<std::string>* Args);

			void Clear();

			template <typename T>
			T* Add();

			template <typename T>
			T* Get();

			
	};
}