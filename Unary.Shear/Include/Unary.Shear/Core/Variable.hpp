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

#include <cstdint>
#include <EASTL/variant.h>
#include <EASTL/string.h>
#include <EASTL/vector.h>
#include <EASTL/array.h>
#include <EASTL/unordered_map.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/quaternion.hpp>
#include <Unary.Shear/Core/Object.hpp>

namespace Unary::Shear::Core
{
	class Object;

	using VariantValue = eastl::variant<bool, int8_t, uint8_t, int16_t, uint16_t, 
	int32_t, uint32_t, int64_t, uint64_t, float, double, glm::vec2, glm::vec3, 
	glm::vec4, glm::quat, eastl::array<float, 4>, eastl::array<int32_t, 4>, eastl::string,
	eastl::vector<uint8_t>, eastl::vector<uint64_t>, void*, Object*, glm::mat3, glm::mat3x4, glm::mat4>;

	enum class VariableType
	{
		None = 0, // int8_t again, but with None type
		Bool, // bool
		Int8, // int8_t
		UInt8, // uint8_t
		Int16, // int16_t
		UInt16, // uint16_t
		Int32, // int32_t
		UInt32, // uint32_t
		Int64, // int64_t
		UInt64, // uint64_t
		Float, // float
		Double, // double
		Vector2, // glm::vec2
		Vector3, // glm::vec3
		Vector4, // glm::vec4
		Quat, // glm::quat
		Rect, // eastl::array<float, 4>
		RectInt, // eastl::array<int32_t, 4>
		String, // eastl::string
		Buffer, // eastl::vector<uint8_t>
		UInt64Vec, // eastl::vector<uint64_t>
		VoidPtr, // void*
		ObjectPtr, // Object*
		Matrix3, // glm::mat3
		Matrix3x4, // glm::mat3x4
		Matrix4, // glm::mat4
		Count
	};

	static const char* VariableTypeNames[] =
	{
		"None",
		"Bool",
		"Int8",
		"UInt8",
		"Int16",
		"UInt16",
		"Int32",
		"UInt32",
		"Int64",
		"UInt64",
		"Float",
		"Double",
		"Vector2",
		"Vector3",
		"Vector4",
		"Quat",
		"Rect",
		"RectInt",
		"String",
		"Buffer",
		"UInt64Vec",
		"VoidPtr",
		"ObjectPtr",
		"Matrix3",
		"Matrix3x4",
		"Matrix4",
		nullptr
	};

	class Variable
	{
		private:

			VariableType VarType;
			VariantValue Val;

		public:

			VariableType GetType() { return VarType; }
			eastl::string GetTypeString() { return VariableTypeNames[static_cast<int32_t>(VarType)]; }
			// Constructors
			Variable() : VarType(VariableType::None), Val(0) {}
			Variable(bool Value) : VarType(VariableType::Bool), Val(Value) {}
			Variable(int8_t Value) : VarType(VariableType::Int8), Val(Value) {}
			Variable(uint8_t Value) : VarType(VariableType::UInt8), Val(Value) {}
			Variable(int16_t Value) : VarType(VariableType::Int16), Val(Value) {}
			Variable(uint16_t Value) : VarType(VariableType::UInt16), Val(Value) {}
			Variable(int32_t Value) : VarType(VariableType::Int32), Val(Value) {}
			Variable(uint32_t Value) : VarType(VariableType::UInt32), Val(Value) {}
			Variable(int64_t Value) : VarType(VariableType::Int64), Val(Value) {}
			Variable(uint64_t Value) : VarType(VariableType::UInt64), Val(Value) {}
			Variable(float Value) : VarType(VariableType::Float), Val(Value) {}
			Variable(double Value) : VarType(VariableType::Double), Val(Value) {}
			Variable(const glm::vec2& Value) : VarType(VariableType::Vector2), Val(Value) {}
			Variable(const glm::vec3& Value) : VarType(VariableType::Vector3), Val(Value) {}
			Variable(const glm::vec4& Value) : VarType(VariableType::Vector4), Val(Value) {}
			Variable(const glm::quat& Value) : VarType(VariableType::Quat), Val(Value) {}
			Variable(const eastl::array<float, 4>& Value) : VarType(VariableType::Rect), Val(Value) {}
			Variable(const eastl::array<int32_t, 4>& Value) : VarType(VariableType::RectInt), Val(Value) {}
			Variable(const eastl::string& Value) : VarType(VariableType::String), Val(Value) {}
			Variable(const eastl::vector<uint8_t>& Value) : VarType(VariableType::Buffer), Val(Value) {}
			Variable(const eastl::vector<uint64_t>& Value) : VarType(VariableType::UInt64Vec), Val(Value) {}
			Variable(void* Value) : VarType(VariableType::VoidPtr), Val(Value) {}
			Variable(Object* Value) : VarType(VariableType::ObjectPtr), Val(Value) {}
			Variable(const glm::mat3& Value) : VarType(VariableType::Matrix3), Val(Value) {}
			Variable(const glm::mat3x4& Value) : VarType(VariableType::Matrix3x4), Val(Value) {}
			Variable(const glm::mat4& Value) : VarType(VariableType::Matrix4), Val(Value) {}
			// Getters
			bool GetBool() { if (VarType == VariableType::Bool) { return eastl::get<bool>(Val); } else { return false; } }
			int8_t GetInt8() { if (VarType == VariableType::Int8) { return eastl::get<int8_t>(Val); } else { return 0; } }
			uint8_t GetUInt8() { if (VarType == VariableType::UInt8) { return eastl::get<uint8_t>(Val); } else { return 0; } }
			int16_t GetInt16() { if (VarType == VariableType::Int16) { return eastl::get<int16_t>(Val); } else { return 0; } }
			uint16_t GetUInt16() { if (VarType == VariableType::UInt16) { return eastl::get<uint16_t>(Val); } else { return 0; } }
			int32_t GetInt32() { if (VarType == VariableType::Int32) { return eastl::get<int32_t>(Val); } else { return 0; } }
			uint32_t GetUInt32() { if (VarType == VariableType::UInt32) { return eastl::get<uint32_t>(Val); } else { return 0; } }
			int64_t GetInt64() { if (VarType == VariableType::Int64) { return eastl::get<int64_t>(Val); } else { return 0; } }
			uint64_t GetUInt64() { if (VarType == VariableType::UInt64) { return eastl::get<uint64_t>(Val); } else { return 0; } }
			float GetFloat() { if (VarType == VariableType::Float) { return eastl::get<float>(Val); } else { return 0.0f; } }
			double GetDouble() { if (VarType == VariableType::Double) { return eastl::get<double>(Val); } else { return 0.0L; } }
			glm::vec2 GetVector2() { if (VarType == VariableType::Vector2) { return eastl::get<glm::vec2>(Val); } else { return {}; } }
			glm::vec3 GetVector3() { if (VarType == VariableType::Vector3) { return eastl::get<glm::vec3>(Val); } else { return {}; } }
			glm::vec4 GetVector4() { if (VarType == VariableType::Vector4) { return eastl::get<glm::vec4>(Val); } else { return {}; } }
			glm::quat GetQuat() { if (VarType == VariableType::Quat) { return eastl::get<glm::quat>(Val); } else { return {}; } }
			eastl::array<float, 4> GetRect() { if (VarType == VariableType::Rect) { return eastl::get<eastl::array<float, 4>>(Val); } else { return {}; } }
			eastl::array<int32_t, 4> GetRectInt() { if (VarType == VariableType::RectInt) { return eastl::get<eastl::array<int32_t, 4>>(Val); } else { return {}; } }
			eastl::string GetString() { if (VarType == VariableType::String) { return eastl::get<eastl::string>(Val); } else { return {}; } }
			eastl::vector<uint8_t> GetBuffer() { if (VarType == VariableType::Buffer) { return eastl::get<eastl::vector<uint8_t>>(Val); } else { return {}; } }
			eastl::vector<uint64_t> GetUInt64Vec() { if (VarType == VariableType::UInt64Vec) { return eastl::get<eastl::vector<uint64_t>>(Val); } else { return {}; } }
			void* GetVoidPtr() { if (VarType == VariableType::VoidPtr) { return eastl::get<void*>(Val); } else { return nullptr; } }
			template<typename T>
			T* GetVoidPtr() { if (VarType == VariableType::VoidPtr) { return static_cast<T*>(eastl::get<void*>(Val)); } else { return nullptr; } }
			Object* GetObjectPtr() { if (VarType == VariableType::ObjectPtr) { return eastl::get<Object*>(Val); } else { return nullptr; } }
			template<typename T>
			T* GetObjectPtr() { if (VarType == VariableType::ObjectPtr) { return static_cast<T*>(eastl::get<Object*>(Val)); } else { return nullptr; } }
			glm::mat3 GetMatrix3() { if (VarType == VariableType::Matrix3) { return eastl::get<glm::mat3>(Val); } else { return {}; } }
			glm::mat3x4 GetMatrix3x4() { if (VarType == VariableType::Matrix3x4) { return eastl::get<glm::mat3x4>(Val); } else { return {}; } }
			glm::mat4 GetMatrix4() { if (VarType == VariableType::Matrix4) { return eastl::get<glm::mat4>(Val); } else { return {}; } }
			// Setters
			void SetBool(bool Value) { if (VarType == VariableType::Bool) { Val = Value; } }
			void SetInt8(int8_t Value) { if (VarType == VariableType::Int8) { Val = Value; } }
			void SetUInt8(uint8_t Value) { if (VarType == VariableType::UInt8) { Val = Value; } }
			void SetInt16(int16_t Value) { if (VarType == VariableType::Int16) { Val = Value; } }
			void SetUInt16(uint16_t Value) { if (VarType == VariableType::UInt16) { Val = Value; } }
			void SetInt32(int32_t Value) { if (VarType == VariableType::Int32) { Val = Value; } }
			void SetUInt32(uint32_t Value) { if (VarType == VariableType::UInt32) { Val = Value; } }
			void SetInt64(int64_t Value) { if (VarType == VariableType::Int64) { Val = Value; } }
			void SetUInt64(uint64_t Value) { if (VarType == VariableType::UInt64) { Val = Value; } }
			void SetFloat(float Value) { if (VarType == VariableType::Float) { Val = Value; } }
			void SetDouble(double Value) { if (VarType == VariableType::Double) { Val = Value; } }
			void SetVector2(const glm::vec2& Value) { if (VarType == VariableType::Vector2) { Val = Value; } }
			void SetVector3(const glm::vec3& Value) { if (VarType == VariableType::Vector3) { Val = Value; } }
			void SetVector4(const glm::vec4& Value) { if (VarType == VariableType::Vector4) { Val = Value; } }
			void SetQuat(const glm::quat& Value) { if (VarType == VariableType::Quat) { Val = Value; } }
			void SetRect(const eastl::array<float, 4>& Value) { if (VarType == VariableType::Rect) { Val = Value; } }
			void SetRectInt(const eastl::array<int32_t, 4>& Value) { if (VarType == VariableType::RectInt) { Val = Value; } }
			void SetString(const eastl::string& Value) { if (VarType == VariableType::String) { Val = Value; } }
			void SetBuffer(const eastl::vector<uint8_t>& Value) { if (VarType == VariableType::Buffer) { Val = Value; } }
			void SetUInt64Vec(const eastl::vector<uint64_t>& Value) { if (VarType == VariableType::UInt64Vec) { Val = Value; } }
			void SetVoidPtr(void* Value) { if (VarType == VariableType::VoidPtr) { Val = Value; } }
			template<typename T>
			void SetVoidPtr(T* Value) { if (VarType == VariableType::VoidPtr) { Val = static_cast<void*>(Value); } }
			void SetObjectPtr(Object* Value) { if (VarType == VariableType::ObjectPtr) { Val = Value; } }
			template<typename T>
			void SetObjectPtr(T* Value) { if (VarType == VariableType::ObjectPtr) { Val = static_cast<Object*>(Value); } }
			void SetMatrix3(const glm::mat3& Value) { if (VarType == VariableType::Matrix3) { Val = Value; } }
			void SetMatrix3x4(const glm::mat3x4& Value) { if (VarType == VariableType::Matrix3x4) { Val = Value; } }
			void SetMatrix4(const glm::mat4& Value) { if (VarType == VariableType::Matrix4) { Val = Value; } }
			// String getters
			eastl::string GetBoolString()
			{
				if (VarType == VariableType::Bool) 
				{ 
					return eastl::get<bool>(Val) ? "True" : "False";
				}
				else 
				{ 
					return {}; 
				}
			}
			eastl::string GetInt8String() 
			{ 
				if (VarType == VariableType::Int8) 
				{
					return eastl::to_string(eastl::get<int8_t>(Val));
				}
				else
				{
					return {};
				}
			}
			eastl::string GetUInt8String() 
			{ 
				if (VarType == VariableType::UInt8)
				{ 
					return eastl::to_string(eastl::get<uint8_t>(Val));
				}
				else
				{
					return {};
				}
			}
			eastl::string GetInt16String() 
			{ 
				if (VarType == VariableType::Int16) 
				{ 
					return eastl::to_string(eastl::get<int16_t>(Val));
				}
				else
				{
					return {};
				}
			}
			eastl::string GetUInt16String() 
			{ 
				if (VarType == VariableType::UInt16) 
				{ 
					return eastl::to_string(eastl::get<uint16_t>(Val));
				}
				else
				{
					return {};
				}
			}
			eastl::string GetInt32String() 
			{ 
				if (VarType == VariableType::Int32) 
				{ 
					return eastl::to_string(eastl::get<int32_t>(Val));
				}
				else
				{
					return {};
				}
			}
			eastl::string GetUInt32String() 
			{ 
				if (VarType == VariableType::UInt32) 
				{ 
					return eastl::to_string(eastl::get<uint32_t>(Val));
				}
				else
				{
					return {};
				}
			}
			eastl::string GetInt64String()
			{ 
				if (VarType == VariableType::Int64)
				{
					return eastl::to_string(eastl::get<int64_t>(Val));
				}
				else
				{
					return {};
				}
			}
			eastl::string GetUInt64String() 
			{ 
				if (VarType == VariableType::UInt64) 
				{
					return eastl::to_string(eastl::get<uint64_t>(Val));
				}
				else
				{
					return {};
				}
			}
			eastl::string GetFloatString() 
			{ 
				if (VarType == VariableType::Float)
				{ 
					return eastl::to_string(eastl::get<float>(Val));
				}
				else
				{
					return {};
				}
			}
			eastl::string GetDoubleString() 
			{ 
				if (VarType == VariableType::Double)
				{
					return eastl::to_string(eastl::get<double>(Val));
				}
				else
				{
					return {};
				}
			}
			eastl::string GetVector2String() 
			{ 
				if (VarType == VariableType::Vector2)
				{ 
					glm::vec2 Result = eastl::get<glm::vec2>(Val);
					return '[' + eastl::to_string(Result.x) + ',' + eastl::to_string(Result.y) + ']';
				}
				else
				{
					return {};
				}
			}
			eastl::string GetVector3String() 
			{ 
				if (VarType == VariableType::Vector3) 
				{ 
					glm::vec3 Result = eastl::get<glm::vec3>(Val);
					return '[' + eastl::to_string(Result.x) + ',' + eastl::to_string(Result.y) + ',' + eastl::to_string(Result.z) + ']';
				}
				else
				{
					return {};
				}
			}
			eastl::string GetVector4String() 
			{ 
				if (VarType == VariableType::Vector4) 
				{
					glm::vec4 Result = eastl::get<glm::vec4>(Val);
					return '[' + eastl::to_string(Result.x) + ',' + eastl::to_string(Result.y) + 
					',' + eastl::to_string(Result.z) + ',' + eastl::to_string(Result.w) + ']';
				}
				else
				{
					return {};
				}
			}
			eastl::string GetQuatString() 
			{ 
				if (VarType == VariableType::Quat) 
				{ 
					glm::quat Result = eastl::get<glm::quat>(Val);
					return '[' + eastl::to_string(Result.x) + ',' + eastl::to_string(Result.y) +
						',' + eastl::to_string(Result.z) + ',' + eastl::to_string(Result.w) + ']';
				}
				else
				{
					return {};
				}
			}
			eastl::string GetRectString() 
			{ 
				if (VarType == VariableType::Rect)
				{ 
					eastl::array<float, 4> Result = eastl::get<eastl::array<float, 4>>(Val); //-V112
					return '[' + eastl::to_string(Result[0]) + ',' + eastl::to_string(Result[1]) +
						',' + eastl::to_string(Result[2]) + ',' + eastl::to_string(Result[3]) + ']';
				}
				else
				{
					return {};
				}
			}
			eastl::string GetRectIntString() 
			{ 
				if (VarType == VariableType::RectInt)
				{ 
					eastl::array<int, 4> Result = eastl::get<eastl::array<int, 4>>(Val); //-V112
					return '[' + eastl::to_string(Result[0]) + ',' + eastl::to_string(Result[1]) +
						',' + eastl::to_string(Result[2]) + ',' + eastl::to_string(Result[3]) + ']';
				}
				else
				{
					return {};
				}
			}
			eastl::string GetBufferString() 
			{ 
				if (VarType == VariableType::Buffer) 
				{ 
					eastl::vector<uint8_t> Result = eastl::get<eastl::vector<uint8_t>>(Val);

					if (Result.size() == 0)
					{
						return "[]";
					}
					else if (Result.size() == 1)
					{
						return "['" + eastl::to_string(Result[0]) + "']";
					}
					else
					{
						eastl::string Output("[");
						Output.resize((Result.size() * 3) + (Result.size() + 1));
						
						for (eastl_size_t i = 0; i < Result.size(); ++i)
						{
							Output += '\'' + Result[i] + '\'';

							if (i != Result.size() - 1)
							{
								Output += ',';
							}
						}
						Output += "]";
						return Output;
					}
				}
				else
				{
					return {};
				}
			}
			eastl::string GetUInt64VecString()
			{
				if (VarType == VariableType::UInt64Vec)
				{
					eastl::vector<uint64_t> Result = eastl::get<eastl::vector<uint64_t>>(Val);

					if (Result.size() == 0)
					{
						return "[]";
					}
					else if (Result.size() == 1)
					{
						return "['" + eastl::to_string(Result[0]) + "']";
					}
					else
					{
						eastl::string Output("[");
						Output.resize((Result.size() * 3) + (Result.size() + 1));

						for (eastl_size_t i = 0; i < Result.size(); ++i)
						{
							Output += '\'' + Result[i] + '\'';

							if (i != Result.size() - 1)
							{
								Output += ',';
							}
						}
						Output += "]";
						return Output;
					}
				}
				else
				{
					return {};
				}
			}
			eastl::string GetVoidPtrString() 
			{ 
				if (VarType == VariableType::VoidPtr) 
				{ 
					void* Result = eastl::get<void*>(Val);
					std::ostringstream Stream;
					Stream << Result;
					return Stream.str().data();
				}
				else
				{
					return {};
				}
			}
			eastl::string GetObjectPtrString() 
			{ 
				if (VarType == VariableType::ObjectPtr)
				{ 
					Object* Result = eastl::get<Object*>(Val);
					std::ostringstream Stream;
					Stream << Result;
					return Stream.str().data();
				}
				else
				{
					return {};
				}
			}
			eastl::string GetMatrix3String() 
			{ 
				if (VarType == VariableType::Matrix3) 
				{ 
					glm::mat3 Result = eastl::get<glm::mat3>(Val);
					return '[' + eastl::to_string(Result[0][0]) + ',' + eastl::to_string(Result[0][1]) + ',' + eastl::to_string(Result[0][2]) + ',' + 
					eastl::to_string(Result[1][0]) + ',' + eastl::to_string(Result[1][1]) + ',' + eastl::to_string(Result[1][2]) + ',' + 
					eastl::to_string(Result[2][0]) + ',' + eastl::to_string(Result[2][1]) + ',' + eastl::to_string(Result[2][2]) + ']';
				}
				else
				{
					return {};
				}
			}
			eastl::string GetMatrix3x4String() 
			{ 
				if (VarType == VariableType::Matrix3x4) 
				{
					glm::mat3x4 Result = eastl::get<glm::mat3x4>(Val);
					return '[' + eastl::to_string(Result[0][0]) + ',' + eastl::to_string(Result[0][1]) + ',' + eastl::to_string(Result[0][2]) + ',' + eastl::to_string(Result[0][3]) + ',' +
					eastl::to_string(Result[1][0]) + ',' + eastl::to_string(Result[1][1]) + ',' + eastl::to_string(Result[1][2]) + ',' + eastl::to_string(Result[1][3]) + ',' +
					eastl::to_string(Result[2][0]) + ',' + eastl::to_string(Result[2][1]) + ',' + eastl::to_string(Result[2][2]) + ',' + eastl::to_string(Result[2][3]) + ']';
				}
				else
				{
					return {};
				}
			}
			eastl::string GetMatrix4String() 
			{ 
				if (VarType == VariableType::Matrix4)
				{
					glm::mat4 Result = eastl::get<glm::mat4>(Val);
					return '[' + eastl::to_string(Result[0][0]) + ',' + eastl::to_string(Result[0][1]) + ',' + eastl::to_string(Result[0][2]) + ',' + eastl::to_string(Result[0][3]) + ',' +
					eastl::to_string(Result[1][0]) + ',' + eastl::to_string(Result[1][1]) + ',' + eastl::to_string(Result[1][2]) + ',' + eastl::to_string(Result[1][3]) + ',' +
					eastl::to_string(Result[2][0]) + ',' + eastl::to_string(Result[2][1]) + ',' + eastl::to_string(Result[2][2]) + ',' + eastl::to_string(Result[2][3]) + ',' +
					eastl::to_string(Result[3][0]) + ',' + eastl::to_string(Result[3][1]) + ',' + eastl::to_string(Result[3][2]) + ',' + eastl::to_string(Result[3][3]) + ']';
				}
				else
				{
					return {};
				}
			}
			eastl::string GetValueString()
			{
				switch (VarType)
				{
					case VariableType::None:
						return {};
					case VariableType::Bool:
						return GetBoolString();
					case VariableType::Int8:
						return GetInt8String();
					case VariableType::UInt8:
						return GetUInt8String();
					case VariableType::Int16:
						return GetInt16String();
					case VariableType::UInt16:
						return GetUInt16String();
					case VariableType::Int32:
						return GetInt32String();
					case VariableType::UInt32:
						return GetUInt32String();
					case VariableType::Int64:
						return GetInt64String();
					case VariableType::UInt64:
						return GetUInt64String();
					case VariableType::Float:
						return GetFloatString();
					case VariableType::Double:
						return GetDoubleString();
					case VariableType::Vector2:
						return GetVector2String();
					case VariableType::Vector3:
						return GetVector3String();
					case VariableType::Vector4:
						return GetVector4String();
					case VariableType::Quat:
						return GetQuatString();
					case VariableType::Rect:
						return GetRectString();
					case VariableType::RectInt:
						return GetRectIntString();
					default:
					case VariableType::String:
						return eastl::get<eastl::string>(Val);
					case VariableType::Buffer:
						return GetBufferString();
					case VariableType::UInt64Vec:
						return GetUInt64VecString();
					case VariableType::VoidPtr:
						return GetVoidPtrString();
					case VariableType::ObjectPtr:
						return GetObjectPtrString();
					case VariableType::Matrix3:
						return GetMatrix3String();
					case VariableType::Matrix3x4:
						return GetMatrix3x4String();
					case VariableType::Matrix4:
						return GetMatrix4String();
				}
			}
	};
}
