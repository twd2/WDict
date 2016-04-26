#ifndef _CONFIRMCONSOLE_H_
#define _CONFIRMCONSOLE_H_

#include "Console.h"
#include "ConsoleComponent.h"
#include <string>
#include <iostream>

class ConfirmConsole
    : public ConsoleComponent
{
public:
    std::string Message;
    bool Default, Value;
    ConfirmConsole(Console &Root, const std::string &Message, bool Default)
        : ConsoleComponent(Root), Message(Message), Default(Default)
    {
        Value = Default;
    }
    
    bool Show() override;
};

#endif // _CONFIRMCONSOLE_H_
