#ifndef _STRINGUTILS_H_
#define _STRINGUTILS_H_

#include <sstream>

class StringUtils
{
public:
    template <typename T>
    static std::string ToString(const T &a);
    
    template <typename T>
    static T FromString(const std::string &a);
    
    static std::string Escape(const std::string &str);
    static std::string Unescape(const std::string &str);
};

template <typename T>
std::string StringUtils::ToString(const T &a)
{
	std::stringstream ss;
	ss << a;
	return ss.str();
}

template <typename T>
T StringUtils::FromString(const std::string &a)
{
	std::stringstream ss;
	ss << a;
	T t;
	ss >> t;
	return t;
}

#endif // _STRINGUTILS_H_