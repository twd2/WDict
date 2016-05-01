#ifndef _TEXTINPUTCONSOLE_H_
#define _TEXTINPUTCONSOLE_H_

#include "Console.h"
#include "ConsoleComponent.h"
#include <string>
#include <iostream>

enum textinput_type_t
{
    TEXTINPUT_TOKEN,
    TEXTINPUT_LINE
};

class TextInputConsole
    : public ConsoleComponent
{
public:
    std::string Value, Message;
    textinput_type_t Type;
    TextInputConsole(Console &Root, const std::string &Message, textinput_type_t Type)
        : ConsoleComponent(Root), Message(Message), Type(Type)
    {
        
    }
    
    bool Show() override;
};

#endif // _TEXTINPUTCONSOLE_H_
