#include <cstdint>

void* __cdecl operator new[](size_t size, const char* name, int flags, unsigned debugFlags, const char* file, int line)
{
	//fmt::print("Allocated {} for allocator named {}\n", size, name);
	return new uint8_t[size];
}

void* __cdecl operator new[](size_t size, size_t, size_t, const char* name, int flags, unsigned debugFlags, const char* file, int line)
{
	//fmt::print("Allocated {} for allocator named {}\n", size, name);
	return new uint8_t[size];
}