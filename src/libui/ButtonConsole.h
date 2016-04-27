#ifndef _BUTTONCONSOLE_H_
#define _BUTTONCONSOLE_H_

#include "ConsoleComponent.h"
#include "Console.h"
#include <string>
#include <functional>

class ButtonConsole
    : public ConsoleComponent
{
public:
    std::function<void ()> OnClick;
    char Key;
    std::string Title;
    
    ButtonConsole(Console &Root, char key, const std::string &title)
        : ConsoleComponent(Root), Key(key), Title(title)
    {
        
    }
    
    bool Show() override;
};

#endif // _BUTTONCONSOLE_H_