#include "StringUtils.h"

std::string StringUtils::Escape(const std::string &str)
{
    std::stringstream ss;
    
    bool need = false;
    
    for (char ch : str)
    {
        if (ch == '\"' || ch == '\r' || ch == '\n' || ch == ',' || ch == '\\')
        {
            need = true;
            break;
        }
    }
    
    if (!need)
    {
        return str;
    }
    
    ss << "\"";
    for (char ch : str)
    {
        if (ch == '\"')
        {
            ss << "\\\"";
        }
        else if (ch == '\r')
        {
            ss << "\\r";
        }
        else if (ch == '\n')
        {
            ss << "\\n";
        }
        else if (ch == '\\')
        {
            ss << "\\\\";
        }
        else
        {
            ss << ch;
        }
    }
    ss << "\"";
    
    return ss.str();
}

std::string StringUtils::Unescape(const std::string &str)
{
    std::stringstream ss;
    
    if (str == "" || str[0] != '\"')
    {
        return str;
    }
    
    for (size_t i = 1; i < str.length() - 1; ++i)
    {
        const char &ch = str[i];
        if (ch == '\\')
        {
            ++i;
            const char &nch = str[i];
            if (nch == 'n')
            {
                ss << '\n';
            }
            else if (nch == 't')
            {
                ss << '\t';
            }
            else if (nch == 'r')
            {
                ss << '\r';
            }
            else if (nch == '\"' || '\\')
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
