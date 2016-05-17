#ifndef _TEXTINPUTCONSOLE_H_
#define _TEXTINPUTCONSOLE_H_

#include "Console.h"
#include "ConsoleComponent.h"
#include <string>
#include <iostream>

/// 枚举：文本框类型
enum textinput_type_t
{
    TEXTINPUT_TOKEN,/// 输入一个Token，使用ins>>
    TEXTINPUT_LINE/// 输入一行，使用getline
};

/// 文本框元件
/// 形如 Your name is:
class TextInputConsole
    : public ConsoleComponent
{
public:
	/// 输入值与提示信息
    std::string Value, Message;
	/// 文本框类型
    textinput_type_t Type;
	/// 构造
    TextInputConsole(Console &Root, const std::string &Message, textinput_type_t Type)
        : ConsoleComponent(Root), Message(Message), Type(Type)
    {

    }

	/// 显示
    bool Show() override;
};

#endif // _TEXTINPUTCONSOLE_H_
