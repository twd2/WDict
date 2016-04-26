#ifndef _CONSOLE_COMPONENT_H_
#define _CONSOLE_COMPONENT_H_

#include <vector>
#include <memory>

class Console;

class ConsoleComponent
{
public:
    std::vector<std::shared_ptr<ConsoleComponent> > Components;
    Console &Root;
    ConsoleComponent(Console &Root)
        : Root(Root)
    {
        
    }
    virtual bool Show() = 0;
    virtual void DoButtons();
};

#endif // _CONSOLE_COMPONENT_H_