#include "Lexer.h"

Lexer::~Lexer()
{

}

std::vector<Token> Lexer::Do()
{
    std::vector<Token> tokens;
    while (index < length)
    {
        tokenStart = index;
        char current = data[index];
        if (isBlank(current))
        {
            if (current == '\n')
            {
                ++lineNumber;
                lineStart = index;
                tokens.push_back(MakeToken(TOKENTYPE_NEWLINE, "\n"));
            }
        }
        else if (current == ',')
        {
            tokens.push_back(MakeToken(TOKENTYPE_SEPARATOR, ","));
        }
        else if (isIdFirst(current))
        {
            std::string word;
            word += current;
            while (nextIs(isId))
            {
                ++index;
                word += data[index];
            }

            tokens.push_back(MakeToken(TOKENTYPE_VALUE, word));
        }
        else if (current == '\"')
        {
            std::string str;
            str += current;
            bool escape = false, ended = false;
            while (hasNext())
            {
                ++index;
                str += data[index];
                if (data[index] == '\\' && !escape)
                {
                    escape = true;
                }
                else if (data[index] == '\"' && !escape)
                {
                    ended = true;
                    break;
                }
                else
                {
                    escape = false;
                }
            }

            if (!ended)
            {
                throw Error("EOF", "'\\\"'");
            }

            tokens.push_back(MakeToken(TOKENTYPE_VALUE, str));
        }
        else
        {
            throw Error(std::string() + "'" + current + "'", "A-Z, a-z, 0-9, '.', '$', '_', '(', ')', '!', '&', '|', '^', '~', '-', '<', '>', '=', '+', '*', '/', '%'");
        }
        ++index;
    }
    return tokens;
}

bool Lexer::hasNext()
{
    return index < length - 1;
}

char Lexer::getNext()
{
    return data[index + 1];
}

std::string Lexer::nextChar()
{
    if (!hasNext())
    {
        return "EOF";
    }
    else
    {
        return "'" + std::string(1, data[index + 1]) + "'";
    }
}

bool Lexer::nextIs(char what)
{
    return hasNext() && data[index + 1] == what;
}

bool Lexer::nextIs(bool (*cond)(char))
{
    return hasNext() && cond(data[index + 1]);
}

SyntaxError Lexer::Error(std::string unexp, std::string exp)
{
    return SyntaxError("Lexer: Unexpected " + unexp + ", expecting " + exp + ".", lineNumber, index - lineStart);
}

Token Lexer::MakeToken(TokenType type, std::string word)
{
    Token token(type, word, lineNumber, tokenStart - lineStart, index - lineStart);
    return token;
}

bool Lexer::isBlank(char a)
{
    return a == ' ' || a == '\n' || a == '\r' || a == '\t';
}

bool Lexer::isDigitFirst(char a)
{
    return (a >= '0' && a <= '9') || a == '.';
}

bool Lexer::isDigit(char a)
{
    return a >= '0' && a <= '9';
}

bool Lexer::isIdFirst(char a)
{
    return a != '\"' && a != ',' && a != '\n' && a != '\r';
}

bool Lexer::isId(char a)
{
    return isIdFirst(a) || isDigit(a);
}

bool Lexer::isLetter(char a)
{
    return (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z');
}

bool Lexer::isUppercase(char a)
{
    return a >= 'A' && a <= 'Z';
}

bool Lexer::isLowercase(char a)
{
    return a >= 'a' && a <= 'z';
}