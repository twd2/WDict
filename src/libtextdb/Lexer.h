#ifndef _LEXER_H_
#define _LEXER_H_

#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include "SyntaxError.h"
#include "Token.h"

/// 词法分析器
class Lexer
{
public:

	/// 使用待解析字符串构造
    Lexer(std::string &str)
        : data(str)
    {
        length = str.length();
    }
	~Lexer();

	/// 进行词法分析
    std::vector<Token> Do();

	/// 字符种类
    static bool isBlank(char a);// 空格，回车，Tab
    static bool isIdFirst(char a);// 非引号，回车，逗号
    static bool isId(char a);// 非引号，回车，逗号
    static bool isDigitFirst(char a);// 数字或小数点
    static bool isDigit(char a);// 数字
    static bool isLetter(char a);// 字母
    static bool isUppercase(char a);// 大写字母
    static bool isLowercase(char a);// 小写字母

private:

	/// 输入字符串
    std::string &data;

	/// 当前分析位置
    size_t length = 0;
    size_t index = 0;
    ptrdiff_t lineNumber = 1, lineStart = -1, tokenStart = 0;

	/// 寻找下一个字符
    bool hasNext();
    char getNext();
    std::string nextChar();
    bool nextIs(char what);
    bool nextIs(bool (*pred)(char));

	/// 生成错误
    SyntaxError Error(std::string, std::string);
	/// 生成Token
    Token MakeToken(TokenType, std::string);
};

#endif // _LEXER_H_