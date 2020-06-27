#pragma once

#include <Unary.Make/Units/DepotVersion.hpp>
#include <Unary.Make/Units/DepotPath.hpp>

namespace Unary::Make::Units
{
    class DepotID
    {
        private:

            DepotVersion Version;
            DepotPath Path;

        public:

            explicit DepotID(const DepotVersion& NewVersion, const DepotPath& NewPath)
            : Version(NewVersion), Path(NewPath)
            {
                
            }

            void SetVersion(const DepotVersion& Value)
            {
                Version = Value;
            }

            DepotVersion& GetVersion()
            {
                return Version;
            }

            void SetPath(const DepotPath& Value)
            {
                Path = Value;
            }

            DepotPath& GetPath()
            {
                return Path;
            }
    };
}