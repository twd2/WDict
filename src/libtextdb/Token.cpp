#include "Token.h"

Token::~Token()
{

}

bool Token::operator==(const Token &b)
{
    return Value == b.Value && Type == b.Type;
}

bool Token::operator!=(const Token &b)
{
    return !(*this == b);
}

std::wstring Token::Name(TokenType type)
{
    static std::map<TokenType, std::wstring> names;
    if (names[TOKENTYPE_EOF] == L"")
    {
        //init
        names[TOKENTYPE_NOTTOKEN] = L"?";
        names[TOKENTYPE_VALUE] = L"VALUE";
        names[TOKENTYPE_SEPARATOR] = L"SEPARATOR";
        names[TOKENTYPE_NEWLINE] = L"NEWLINE";
        names[TOKENTYPE_EOF] = L"EOF";
    }

    return names[type];
}