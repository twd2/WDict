#ifndef _CONSOLE_COMPONENT_H_
#define _CONSOLE_COMPONENT_H_

#include <vector>
#include <memory>

class Console;

class ConsoleComponent
{
public:
    std::vector<ConsoleComponent*> Components;
    Console &Root;
    ConsoleComponent(Console &Root)
        : Root(Root)
    {
        
    }
    void Add(ConsoleComponent &comp);
    virtual bool Show() = 0;
    virtual void DoButtons();
    virtual void DoButtons(char key);
};

#endif // _CONSOLE_COMPONENT_H_