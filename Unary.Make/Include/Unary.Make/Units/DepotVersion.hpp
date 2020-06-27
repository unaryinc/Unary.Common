#pragma once

#include <Unary.Make/Abstract/Stringifiable.hpp>

#include <string>

namespace Unary::Make::Units
{
    class DepotVersion : public Abstract::Stringifiable
    {
        private:

            int Major;
            int Minor;
            int Patch;

        public:

            std::string GetString();

            DepotVersion(int NewMajor, int NewMinor, int NewPatch)
            : Major(NewMajor), Minor(NewMinor), Patch(NewPatch)
            {
                
            }

            void Set(int NewMajor, int NewMinor, int NewPatch)
            {
                Major = NewMajor;
                Minor = NewMinor;
                Patch = NewPatch;
            }

            void SetMajor(const int& Value)
            {
                Major = Value;
            }

            const int& GetMajor() const
            {
                return Major;
            }

            void SetMinor(const int& Value)
            {
                Minor = Value;
            }

            const int& GetMinor() const
            {
                return Minor;
            }

            void SetPatch(const int& Value)
            {
                Patch = Value;
            }

            const int& GetPatch() const
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
    };
}