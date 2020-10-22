#include <Unary.Shear/Utils/String.hpp>

namespace Unary::Shear::Utils::String
{
    eastl::vector<eastl::string> Split(const eastl::string& Value, const eastl::string& Delimiter)
    {
        eastl::vector<eastl::string> Parts;
        eastl::string Buffer;
        
        eastl_size_t start = 0U;
        auto end = Value.find(Delimiter);

        while (end != eastl::string::npos)
        {
            Buffer.resize(end - start);
            Buffer.assign(Value.begin() + start, Value.begin() + end - Value.begin() - start);
            Parts.push_back(Buffer);
            start = end + Delimiter.length();
            end = Value.find(Delimiter, start);
        }

        return Parts;
    }

    eastl::string Replace(const eastl::string& Source, const eastl::string& From, const eastl::string& To)
    {
        eastl::string Result;
        Result.reserve(Source.length());

        eastl::string::size_type LastPos = 0;
        eastl::string::size_type FindPos;

        while (eastl::string::npos != (FindPos = Source.find(From, LastPos)))
        {
            Result.append(Source, LastPos, FindPos - LastPos);
            Result += To;
            LastPos = FindPos + From.length();
        }

        Result += Source.substr(LastPos);

        return Result;
    }

    bool EndsWith(const eastl::string& Target, const eastl::string& WithWhat)
    {
        return Target.size() >= WithWhat.size() && 0 == Target.compare(Target.size() - WithWhat.size(), WithWhat.size(), WithWhat);
    }

    bool StartsWith(const eastl::string& Target, const eastl::string& WithWhat)
    {
        return Target.size() >= WithWhat.size() && 0 == Target.compare(0, WithWhat.size(), WithWhat);
    }

#ifdef _WIN32
    eastl::string U16ToU8(const eastl::wstring& Target)
    {
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, &Target[0], (int)Target.size(), NULL, 0, NULL, NULL);
        eastl::string Result(size_needed, 0);
        WideCharToMultiByte(CP_UTF8, 0, &Target[0], (int)Target.size(), &Result[0], size_needed, NULL, NULL);
        return Result;
    }

    eastl::wstring U8ToU16(const eastl::string& Target)
    {
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, &Target[0], (int)Target.size(), NULL, 0);
        eastl::wstring Result(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, &Target[0], (int)Target.size(), &Result[0], size_needed);
        return Result;
    }
#endif
}