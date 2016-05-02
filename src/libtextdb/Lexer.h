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
    Lexer(std::string &str)
        : data(str)
    {
        length = str.length();
    }

    ~Lexer();
    std::vector<Token> Do();

    static bool isBlank(char a);
    static bool isIdFirst(char a);
    static bool isId(char a);
    static bool isDigitFirst(char a);
    static bool isDigit(char a);
    static bool isLetter(char a);
    static bool isUppercase(char a);
    static bool isLowercase(char a);

private:
    std::string &data;

    size_t length = 0;
    size_t index = 0;
    ptrdiff_t lineNumber = 1, lineStart = -1, tokenStart = 0;

    bool hasNext();
    char getNext();
    std::string nextChar();
    bool nextIs(char what);
    bool nextIs(bool (*pred)(char));
    SyntaxError Error(std::string, std::string);
    Token MakeToken(TokenType, std::string);
};

#endif // _LEXER_H_