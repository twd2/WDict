#include "StringUtils.h"

std::wstring StringUtils::Escape(const std::wstring &str)
{
    std::wstringstream ss;
    
    bool need = false;
    
    for (wchar_t ch : str)
    {
        if (ch == L'\"' || ch == L'\r' || ch == L'\n' || ch == L',' || ch == L'\\')
        {
            need = true;
            break;
        }
    }
    
    if (!need)
    {
        return str;
    }
    
    ss << L"\"";
    for (wchar_t ch : str)
    {
        if (ch == L'\"')
        {
            ss << L"\\\"";
        }
        else if (ch == L'\r')
        {
            ss << L"\\r";
        }
        else if (ch == L'\n')
        {
            ss << L"\\n";
        }
        else if (ch == L'\\')
        {
            ss << L"\\\\";
        }
        else
        {
            ss << ch;
        }
    }
    ss << L"\"";
    
    return ss.str();
}

std::wstring StringUtils::Unescape(const std::wstring &str)
{
    std::wstringstream ss;
    
    if (str == L"" || str[0] != L'\"')
    {
        return str;
    }
    
    for (size_t i = 1; i < str.length() - 1; ++i)
    {
        const wchar_t &ch = str[i];
        if (ch == L'\\')
        {
            ++i;
            const wchar_t &nch = str[i];
            if (nch == L'n')
            {
                ss << L'\n';
            }
            else if (nch == L't')
            {
                ss << L'\t';
            }
            else if (nch == L'r')
            {
                ss << L'\r';
            }
            else if (nch == L'\"' || L'\\')
            {
                ss << nch;
            }
        }
        else
        {
            ss << ch;
        }
    }
    
    return ss.str();
}