#pragma once

#include <string>

namespace Unary::Make::Units
{
    class DepotPath
    {
        private:

            std::string Value;

        public:

            DepotPath(const std::string& NewValue)
            : Value(NewValue)
            {

            }

            void SetValue(const std::string& NewValue)
            {
                Value = NewValue;

                
            }

            const std::string& GetValue() const
            {
                return Value;
            }

            bool operator==(const DepotPath& Target)
            {
                if(Value == Target.GetValue())
                {
                    return true;
                }
                return false;
            }

            bool operator!=(const DepotPath& Target)
            {
                if(Value != Target.GetValue())
                {
                    return true;
                }
                return false;
            }
    };
}