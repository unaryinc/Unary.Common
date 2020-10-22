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

#include <Unary.Shear/Core/Object.hpp>

#include <asio.hpp>

namespace Unary::Shear::Systems
{
	class IOContext : public Core::Object
	{
		private:

			asio::io_service IO;

		public:

			IOContext()
			{
				//EventSubscribe(Test, Unary::Shear::Systems::IOContext::Test)


				Subscribe("Test", std::bind(&Unary::Shear::Systems::IOContext::Test, this, std::placeholders::_1));
			}

			ShearCTTI(Unary::Shear::Systems::IOContext, Unary::Shear::Core::Object)

			~IOContext()
			{

			}

			void Test(eastl::unordered_map<uint64_t, Core::Variable>& Args)
			{
				Args[123] = "This is a test";
			}

			asio::io_service& GetIO()
			{
				return IO;
			}
	};
}