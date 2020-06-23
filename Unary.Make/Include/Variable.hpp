#pragma once

#include <cstdint>
#include <iostream>
#include <rapidjson/reader.h>

namespace Unary::Make
{
	class Variable
	{
		public:

		enum Type
		{
			UI8,
			I8,
			UI16,
			I16,
			UI32,
			I32,
			UI64,
			I64,
			F,
			D,
			S,
			B
		};

		void Test()
		{
			std::cout << "Test from function" << std::endl;
		}
	};
}