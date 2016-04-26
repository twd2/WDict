#ifndef _BUTTONCONSOLE_H_
#define _BUTTONCONSOLE_H_

#include "ConsoleComponent.h"
#include "Console.h"
#include <string>
#include <functional>

class ButtonConsole
    : public ConsoleComponent
{
private:
    std::function<void ()> onClick;
public:
    char Key;
    std::string Title;
    
    ButtonConsole(Console &Root, char key, const std::string &title, std::function<void ()> onClick)
        : ConsoleComponent(Root), onClick(onClick), Key(key), Title(title)
    {
        
    }
    
    
    void OnClick()
    {
        onClick();
    }
    bool Show() override;
};

#endif // _BUTTONCONSOLE_H_