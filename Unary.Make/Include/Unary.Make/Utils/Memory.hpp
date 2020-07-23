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

#include <array>
#include <cstdint>
#include <memory>
#include <cstring>

namespace Unary::Make::Utils::Memory
{
	template <typename T>
	uint8_t GetByte(T& Target, int Index)
	{
		return reinterpret_cast<uint8_t*>(&Target)[Index];
	}

	template <typename T>
	void SetByte(T& Target, uint8_t Byte, int Index)
	{
		reinterpret_cast<uint8_t*>(&Target)[Index] = Byte;
	}

	template <typename T, typename R>
	void FromBytes(R& Result, T& Target, size_t Index, size_t Count)
	{
		if constexpr (std::is_same<T, uint8_t*>::value)
		{
			std::memcpy(&Result, Target + Index, Count);
		}
		else
		{
			std::memcpy(&Result, reinterpret_cast<uint8_t*>(&Target) + Index, Count);
		}
	}

	template <typename T, typename R>
	R FromBytes(T& Target, size_t Index, size_t Count)
	{
		R Result {};

		if constexpr(std::is_same<T, uint8_t*>::value)
		{
			std::memcpy(&Result, Target + Index, Count);
		}
		else
		{
			std::memcpy(&Result, reinterpret_cast<uint8_t*>(&Target) + Index, Count);
		}
		
		return Result;
	}
}