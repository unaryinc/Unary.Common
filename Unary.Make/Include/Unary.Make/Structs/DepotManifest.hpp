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

#include <string>

#include <Unary.Make/Enums/DepotType.hpp>
#include <Unary.Make/Structs/DepotID.hpp>
#include <Unary.Make/Structs/DepotVersion.hpp>
#include <Unary.Make/Structs/DepotFlags.hpp>
#include <Unary.Make/Structs/DepotBinaries.hpp>
#include <Unary.Make/Structs/DepotVariables.hpp>
#include <Unary.Make/Structs/DepotPatches.hpp>

namespace Unary::Make::Structs
{
    struct DepotManifest
    {
        public:
        // Type of a depot, "Headers", "Sources", "Binaries", "Variables"
        Enums::DepotType Type;

        // Unique ID of this depot
        Structs::DepotID ID;

        //Flags that are treated accordingly to the type
        Structs::DepotFlags Flags;

        // Path for the headers
        std::string Headers;

        // Path for the sources
        std::string Sources;

        // Precompiled libraries go here
        Structs::DepotBinaries Binaries;

        // Metadata that is provided by this Depot
        Structs::DepotData Variables;

        // Patches that are required to the target Depot
        Structs::DepotPatches Patches;

        std::string GetString()
        {
            return ID.GetString();
        }
    };
}