#ifndef _LEXER_H_
#define _LEXER_H_

#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include "SyntaxError.h"
#include "Token.h"

class Lexer
{
public:
    Lexer(std::wstring &str) : data(str)
    {
        length = str.length();
    }

    ~Lexer();
    std::vector<Token> Do();

    static bool isBlank(wchar_t);
    static bool isIdFirst(wchar_t);
    static bool isId(wchar_t);
    static bool isDigitFirst(wchar_t);
    static bool isDigit(wchar_t);
    static bool isLetter(wchar_t);
    static bool isUppercase(wchar_t);
    static bool isLowercase(wchar_t);

private:
    std::wstring &data;

    size_t length = 0;
    size_t index = 0;
    ptrdiff_t lineNumber = 1, lineStart = -1, tokenStart = 0;

    bool hasNext();
    wchar_t getNext();
    std::wstring nextChar();
    bool nextIs(wchar_t);
    bool nextIs(bool(*)(wchar_t));
    SyntaxError Error(std::wstring, std::wstring);
    Token MakeToken(TokenType, std::wstring);
};

#endif // _LEXER_H_