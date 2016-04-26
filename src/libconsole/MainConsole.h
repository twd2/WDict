#ifndef _MAINCONSOLE_H_
#define _MAINCONSOLE_H_

#include "ConsoleComponent.h"
#include "Console.h"
#include "ButtonConsole.h"
#include <iostream>
#include <functional>

class MainConsole
    : public ConsoleComponent
{
public:
    MainConsole(Console &Root)
        : ConsoleComponent(Root)
    {
        
    }
    bool Show() override;
};

#endif // _MAINCONSOLE_H_