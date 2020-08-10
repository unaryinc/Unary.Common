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

#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <regex>
#include <optional>

#include <Unary.Make/Abstract/Patchers.hpp>
#include <Unary.Make/Utils/String.hpp>


namespace Unary::Make::Units
{
    enum TextPatcherOperationType : uint8_t
    {
        InsertBefore,
        InsertAfter,
        RemoveLine,
        RemoveRange,
        ReplaceLine,
        ReplaceRange
    };

    struct TextPatcherOperation
    {
        TextPatcherOperationType Type;
        int Begin;
        int End;
        std::vector<std::string> Value;
    };

    class TextPatcher : public Patchers
    {
        private:

            std::unordered_map<std::string, TextPatcherOperation> Operations;

        public:

            bool Patch(const std::vector<Structs::PatcherData>& Data)
            {
                std::string TempString;
                std::regex OperationRegex{"\/*=*\/ (.*?) \/*=*\/"};
                std::smatch Match;

                for(size_t i = 0; i < Data.size(); ++i)
                {
                    std::ifstream NewPatch(Data[i].PatchPath);
                    TextPatcherOperation NewOperation;
                    bool Reading = false;

                    while (std::getline(NewPatch, TempString))
                    {
                        if(std::regex_match(TempString, Match, OperationRegex))
                        {
                            std::vector<std::string> OperationPieces = Utils::String::Split(Match[0], ' ');

                            if(OperationPieces[0] == "Insert")
                            {
                                if(OperationPieces[1] == "before")
                                {
                                    NewOperation.Type = TextPatcherOperationType::InsertBefore;
                                }
                                else
                                {
                                    NewOperation.Type = TextPatcherOperationType::InsertAfter;
                                }

                                NewOperation.Begin = std::stoi(OperationPieces[3]);
                                Reading = true;
                            }
                            else if(OperationPieces[0] == "Remove")
                            {
                                if(OperationPieces[2] == "from")
                                {
                                    NewOperation.Type = TextPatcherOperationType::RemoveRange;
                                    NewOperation.Begin = std::stoi(OperationPieces[3]);
                                    NewOperation.End = std::stoi(OperationPieces[5]);
                                }
                                else
                                {
                                    NewOperation.Type = TextPatcherOperationType::RemoveLine;
                                    NewOperation.Begin = std::stoi(OperationPieces[2]);
                                }
                                Reading = false;
                            }
                            else
                            {
                                if(OperationPieces[2] == "from")
                                {
                                    NewOperation.Type = TextPatcherOperationType::ReplaceRange;
                                    NewOperation.Begin = std::stoi(OperationPieces[3]);
                                    NewOperation.End = std::stoi(OperationPieces[5]);
                                }
                                else
                                {
                                    NewOperation.Type = TextPatcherOperationType::ReplaceLine;
                                    NewOperation.Begin = std::stoi(OperationPieces[2]);
                                }
                                Reading = true;
                            }
                        }

                        if(TempString == "")
                        {
                            continue;
                        }

                        if(Reading)
                        {
                            for(auto& Char : TempString)
                            {
                                if(Char != ' ' || Char != '\t')
                                {
                                    NewOperation.Value.push_back(TempString);
                                    break;
                                }
                            }
                        }
                    }
                }

                std::vector<std::string> TargetLines;

                return {};
            }
    };
}