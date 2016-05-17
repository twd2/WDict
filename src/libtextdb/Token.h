#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <map>
#include <string>
#include <cstddef>

using std::size_t;
using std::ptrdiff_t;

/// 枚举：Token种类
enum TokenType
{
    TOKENTYPE_NOTTOKEN, // 非token
    TOKENTYPE_VALUE, // 值，由$、_、字母、数字组成的不以数字开头的字符串， [$_A-Za-z][$_A-Za-z0-9]*
    TOKENTYPE_SEPARATOR, // 分隔符
    TOKENTYPE_NEWLINE, // 新行
    TOKENTYPE_EOF = -1 // 文件尾
};

/// Token
class Token
{
public:
	/// 类型与内容
    TokenType Type;
    std::string Value; // raw string / Value

	/// Token在原文件中的位置
    ptrdiff_t LineNumber, ColumnStart, ColumnEnd;

	/// 构造Token
    Token(TokenType type, std::string value)
        : Type(type), Value(value), LineNumber(-1), ColumnStart(-1), ColumnEnd(-1)
    {

    }

    Token(TokenType type, std::string value, ptrdiff_t lineNumber, ptrdiff_t columnStart, ptrdiff_t columnEnd)
        : Type(type), Value(value), LineNumber(lineNumber), ColumnStart(columnStart), ColumnEnd(columnEnd)
    {

    }

    ~Token();

	/// 检测Token值与内容是否相同
    bool operator==(const Token &b);
    bool operator!=(const Token &b);

	/// 获取Token类型名
    static std::string Name(TokenType type);
};

#endif // _TOKEN_H_