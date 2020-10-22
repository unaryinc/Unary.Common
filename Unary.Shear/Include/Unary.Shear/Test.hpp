#pragma once

#include <EASTL/vector.h>
#include <EASTL/string.h>
class Test
{
	private:

		eastl::vector<eastl::string> Intr;
		
	public:

		explicit Test()
		{
			Intr.push_back("This");
			Intr.push_back("is");
			Intr.push_back("a");
			Intr.push_back("test");
		}

		~Test()
		{
			;
		}
};