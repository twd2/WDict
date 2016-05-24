#ifndef _DICTSTRINGUTILS_H_
#define _DICTSTRINGUTILS_H_

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

/// 字符串工具
class DictStringUtils
{
public:
    /// 从字符串输入与输出
    template <typename T>
    static std::string ToString(const T &a);

    template <typename T>
    static T FromString(const std::string &a);

    /// 从文章获取单词组
    static std::vector<std::string> GetWords(std::string text, bool unique = false);
    /// 海明距离
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

template <>
std::string DictStringUtils::ToString(const std::string &a);

template <>
std::string DictStringUtils::FromString(const std::string &a);

#endif // _DICTSTRINGUTILS_H_
