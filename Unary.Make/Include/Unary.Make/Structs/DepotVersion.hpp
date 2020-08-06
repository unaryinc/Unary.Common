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
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include <Unary.Make/Utils/Murmur.hpp>
#include <Unary.Make/Utils/String.hpp>

namespace Unary::Make::Structs
{
    class DepotVersion
    {
        private:

            uint32_t Major;
            uint32_t Minor;
            uint32_t Patch;

        public:

            std::string GetString()
            {
                return std::to_string(Major) + '.' + std::to_string(Minor) + '.' + std::to_string(Patch);
            }

            uint64_t GetHash()
            {
                std::string String = GetString();
                return Utils::Murmur::Hash(String.data(), static_cast<uint64_t>(String.length()), 0);
            }

            DepotVersion()
            : Major(0), Minor(0), Patch(0)
            {
                
            }

            DepotVersion(uint32_t NewMajor, uint32_t NewMinor, uint32_t NewPatch)
            : Major(NewMajor), Minor(NewMinor), Patch(NewPatch)
            {
                
            }

            DepotVersion(const std::string& Value)
            {
                std::vector<std::string> Parts = Utils::String::Split(Value, '.');

                if(Parts.size() != 3)
                {
                    Major = std::stoi(Parts[0]);
                    Minor = std::stoi(Parts[1]);
                    Patch = std::stoi(Parts[2]);
                }
            }

            void Set(uint32_t NewMajor, uint32_t NewMinor, uint32_t NewPatch)
            {
                Major = NewMajor;
                Minor = NewMinor;
                Patch = NewPatch;
            }

            void SetMajor(const uint32_t& Value)
            {
                Major = Value;
            }

            const uint32_t& GetMajor() const
            {
                return Major;
            }

            void SetMinor(const uint32_t& Value)
            {
                Minor = Value;
            }

            const uint32_t& GetMinor() const
            {
                return Minor;
            }

            void SetPatch(const uint32_t& Value)
            {
                Patch = Value;
            }

            const uint32_t& GetPatch() const
            {
                return Patch;
            }

            bool operator==(const DepotVersion& Target)
            {
                if(Major == Target.GetMajor() && 
                Minor == Target.GetMinor() &&
                Patch == Target.GetPatch())
                {
                    return true;
                }
                return false;
            }

            bool operator!=(const DepotVersion& Target)
            {
                if(Major != Target.Major || 
                Minor != Target.Minor ||
                Patch != Target.Patch)
                {
                    return true;
                }
                return false;
            }

            bool operator>=(const DepotVersion& Target)
            {
                if(Major >= Target.Major && 
                Minor >= Target.Minor &&
                Patch >= Target.Patch)
                {
                    return true;
                }
                return false;
            }

            bool operator<=(const DepotVersion& Target)
            {
                if(Major <= Target.Major && 
                Minor <= Target.Minor &&
                Patch <= Target.Patch)
                {
                    return true;
                }
                return false;
            }

            void operator=(const std::string& Value)
            {
                std::vector<std::string> Parts = Utils::String::Split(Value, '.');

                if(Parts.size() == 3)
                {
                    Major = std::stoi(Parts[0]);
                    Minor = std::stoi(Parts[1]);
                    Patch = std::stoi(Parts[2]);
                }
            }
    };
}