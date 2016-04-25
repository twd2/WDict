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
        wchar_t current = data[index];
        if (isBlank(current))
        {
            if (current == L'\n')
            {
                ++lineNumber;
                lineStart = index;
                tokens.push_back(MakeToken(TOKENTYPE_NEWLINE, L"\n"));
            }
        }
        else if (current == L',')
        {
            tokens.push_back(MakeToken(TOKENTYPE_SEPARATOR, L","));
        }
        else if (isIdFirst(current))
        {
            std::wstring word;
            word += current;
            while (nextIs(isId))
            {
                ++index;
                word += data[index];
            }

            tokens.push_back(MakeToken(TOKENTYPE_VALUE, word));
        }
        else if (current == L'\"')
        {
            std::wstring str;
            str += current;
            bool escape = false, ended = false;
            while (hasNext())
            {
                ++index;
                str += data[index];
                if (data[index] == L'\\' && !escape)
                {
                    escape = true;
                }
                else if (data[index] == L'\"' && !escape)
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
                throw Error(L"EOF", L"'\\\"'");
            }

            tokens.push_back(MakeToken(TOKENTYPE_VALUE, str));
        }
        else
        {
            throw Error(std::wstring() + L"'" + current + L"'", L"A-Z, a-z, 0-9, '.', '$', '_', '(', ')', '!', '&', '|', '^', '~', '-', '<', '>', '=', '+', '*', '/', '%'");
        }
        ++index;
    }
    return tokens;
}

bool Lexer::hasNext()
{
    return index < length - 1;
}

wchar_t Lexer::getNext()
{
    return data[index + 1];
}

std::wstring Lexer::nextChar()
{
    if (!hasNext())
    {
        return L"EOF";
    }
    else
    {
        return L"'" + std::wstring(1, data[index + 1]) + L"'";
    }
}

bool Lexer::nextIs(wchar_t what)
{
    return hasNext() && data[index + 1] == what;
}

bool Lexer::nextIs(bool (*cond)(wchar_t))
{
    return hasNext() && cond(data[index + 1]);
}

SyntaxError Lexer::Error(std::wstring unexp, std::wstring exp)
{
    return SyntaxError(L"Lexer: Unexpected " + unexp + L", expecting " + exp + L".", lineNumber, index - lineStart);
}

Token Lexer::MakeToken(TokenType type, std::wstring word)
{
    Token token(type, word, lineNumber, tokenStart - lineStart, index - lineStart);
    return token;
}

bool Lexer::isBlank(wchar_t a)
{
    return a == L' ' || a == L'\n' || a == L'\r' || a == L'\t';
}

bool Lexer::isDigitFirst(wchar_t a)
{
    return (a >= L'0' && a <= L'9') || a == L'.';
}

bool Lexer::isDigit(wchar_t a)
{
    return a >= L'0' && a <= L'9';
}

bool Lexer::isIdFirst(wchar_t a)
{
    return a != L'\"' && a != L',' && a != L'\n' && a != L'\r';
}

bool Lexer::isId(wchar_t a)
{
    return isIdFirst(a) || isDigit(a);
}

bool Lexer::isLetter(wchar_t a)
{
    return (a >= L'A' && a <= L'Z') || (a >= L'a' && a <= L'z');
}

bool Lexer::isUppercase(wchar_t a)
{
    return a >= L'A' && a <= L'Z';
}

bool Lexer::isLowercase(wchar_t a)
{
    return a >= L'a' && a <= L'z';
}