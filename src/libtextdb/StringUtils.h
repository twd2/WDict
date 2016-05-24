#ifndef _STRINGUTILS_H_
#define _STRINGUTILS_H_

#include <sstream>

/// 字符串处理工具
class StringUtils
{
public:
    /// 转化为字符串
    template <typename T>
    static std::string ToString(const T &a);

    /// 从字符串构造
    template <typename T>
    static T FromString(const std::string &a);

    /// 对字符串进行转义和反转义
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
