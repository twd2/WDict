#ifndef _CONFIRMCONSOLE_H_
#define _CONFIRMCONSOLE_H_

#include "Console.h"
#include "ConsoleComponent.h"
#include <string>
#include <iostream>

/// 是/否确认元件
/// 形如message(Y/N)[Y]
/// 显示后可以获取输入值
class ConfirmConsole
    : public ConsoleComponent
{
public:
    /// 消息前缀
    std::string Message;
    /// 默认值，输入值
    bool Default, Value;
    /// 构造
    ConfirmConsole(Console &Root, const std::string &Message, bool Default)
        : ConsoleComponent(Root), Message(Message), Default(Default)
    {
        Value = Default;
    }

    /// 显示
    bool Show() override;
};

#endif // _CONFIRMCONSOLE_H_
