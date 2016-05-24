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

std::string Token::Name(TokenType type)
{
    static std::map<TokenType, std::string> names;
    if (names[TOKENTYPE_EOF] == "")
    {
        //init
        names[TOKENTYPE_NOTTOKEN] = "?";
        names[TOKENTYPE_VALUE] = "VALUE";
        names[TOKENTYPE_SEPARATOR] = "SEPARATOR";
        names[TOKENTYPE_NEWLINE] = "NEWLINE";
        names[TOKENTYPE_EOF] = "EOF";
    }

    return names[type];
}
