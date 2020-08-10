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

#include <stdint.h>
#include <string>
#include <filesystem>


#include <Unary.Make/Systems/System.hpp>

#include <Unary.Make/Systems/Build.hpp>
#include <Unary.Make/Systems/Depots.hpp>

#include <Unary.Make/Units/ThreadPool.hpp>
#include <Unary.Make/Structs/ObjectData.hpp>

namespace Unary::Make::Systems
{
    DeclareSystem(Compiler)
    {
        private:

            Build* BuildPtr;
            Depots* DepotsPtr;

            std::string Path;

        public:

            DeclareType(Unary::Make::Systems::Compiler)

            bool Process()
            {

            }

            void Init()
            {
                BuildPtr = SysPtr->Get<Build>();
                DepotsPtr = SysPtr->Get<Depots>();


                Units::ThreadPool pool(std::thread::hardware_concurrency());

                std::string CompilerPath;
                std::string GlobalFlags;

                std::vector<Structs::ObjectData> ObjectPool;

                std::vector< std::future<int> > results;

                for(int i = 0; i < 8; ++i) {
                    results.emplace_back(
                        pool.enqueue([i] {
                            std::cout << "hello " << i << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "world " << i << std::endl;
                            return i*i;
                        })
                    );
                }

                for(auto && result: results)
                    std::cout << result.get() << ' ';
                std::cout << std::endl;
            }

            void Clear()
            {
                
            }
    };
}