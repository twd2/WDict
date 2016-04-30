#ifndef _TEXTINPUTCONSOLE_H_
#define _TEXTINPUTCONSOLE_H_

#include "Console.h"
#include "ConsoleComponent.h"
#include <string>
#include <iostream>

#define TEXTINPUT_TOKEN 0
#define TEXTINPUT_LINE 1

class TextInputConsole
    : public ConsoleComponent
{
public:
    std::string Value, Message;
    int TokenOrLine;
    TextInputConsole(Console &Root, const std::string &Message, int TokenOrLine)
        : ConsoleComponent(Root), Message(Message), TokenOrLine(TokenOrLine)
    {
        
    }
    
    bool Show() override;
};

#endif // _TEXTINPUTCONSOLE_H_
