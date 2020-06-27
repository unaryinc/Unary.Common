#include <Unary.Make/Units/DepotVersion.hpp>

namespace Unary::Make::Units
{
    std::string DepotVersion::GetString()
    {
        return std::to_string(Major) + '.' + std::to_string(Minor) + '.' + std::to_string(Patch);
    }
}