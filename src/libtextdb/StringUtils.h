#ifndef _STRINGUTILS_H_
#define _STRINGUTILS_H_

#include <string>
#include <sstream>

class StringUtils
{
public:
    template <typename T>
    static std::wstring ToString(const T&);
    
    template <typename T>
    static T FromString(const std::wstring&);
    
    static std::wstring Escape(const std::wstring&);
    static std::wstring Unescape(const std::wstring&);
};

template <typename T>
std::wstring StringUtils::ToString(const T &a)
{
	std::wstringstream ss;
	ss << a;
	return ss.str();
}

template <typename T>
T StringUtils::FromString(const std::wstring &a)
{
	std::wstringstream ss;
	ss << a;
	T t;
	ss >> t;
	return t;
}

#endif // _STRINGUTILS_H_