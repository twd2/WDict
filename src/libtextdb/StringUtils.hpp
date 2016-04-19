#ifndef _STRINGUTILS_HPP_
#define _STRINGUTILS_HPP_

#include <sstream>

class StringUtils
{
public:
    template <typename T>
    static std::string ToString(const T&);
    
    template <typename T>
    static T FromString(const std::string&);
    
    static std::string Escape(const std::string&);
    static std::string Unescape(const std::string&);
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

#endif // _STRINGUTILS_HPP_