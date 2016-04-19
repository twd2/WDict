#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <map>
#include <string>
#include <cstddef>

using std::size_t;
using std::ptrdiff_t;

enum TokenType
{
    TOKENTYPE_NOTTOKEN,
    TOKENTYPE_VALUE, // not separator [$_A-Za-z][$_A-Za-z0-9]*
    TOKENTYPE_SEPARATOR,
    TOKENTYPE_NEWLINE,
    TOKENTYPE_EOF = -1
};

class Token
{
public:
    TokenType Type;
    std::string Value; // raw string / StringValue / CharValue

    ptrdiff_t LineNumber, ColumnStart, ColumnEnd;

    Token(TokenType type, std::string value)
        : Type(type), Value(value), LineNumber(-1), ColumnStart(-1), ColumnEnd(-1)
    {
        
    }

    Token(TokenType type, std::string value, ptrdiff_t lineNumber, ptrdiff_t columnStart, ptrdiff_t columnEnd) 
        : Type(type), Value(value), LineNumber(lineNumber), ColumnStart(columnStart), ColumnEnd(columnEnd)
    {
        
    }

    ~Token();

    bool operator==(const Token &b);
    bool operator!=(const Token &b);

    static std::string Name(TokenType);
};

#endif // _TOKEN_H_