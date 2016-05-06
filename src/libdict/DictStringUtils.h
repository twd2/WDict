#ifndef _DICTSTRINGUTILS_H_
#define _DICTSTRINGUTILS_H_

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

class DictStringUtils
{
public:
    template <typename T>
    static std::string ToString(const T &a);
    
    template <typename T>
    static T FromString(const std::string &a);
	
	static std::vector<std::string> GetWords(std::string text, bool unique = false);
	static size_t Distance(const std::string &a, const std::string &b);
};

template <typename T>
std::string DictStringUtils::ToString(const T &a)
{
	std::stringstream ss;
	ss << a;
	return ss.str();
}

template <typename T>
T DictStringUtils::FromString(const std::string &a)
{
	std::stringstream ss;
	ss << a;
	T t;
	ss >> t;
	return t;
}

#endif // _DICTSTRINGUTILS_H_