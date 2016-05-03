#ifndef _CONSOLE_COMPONENT_H_
#define _CONSOLE_COMPONENT_H_

#include <vector>
#include <memory>
#include "Console.h"

class ConsoleComponent
{
protected:
    std::istream &ins;
    std::ostream &outs;
public:
    std::vector<ConsoleComponent*> Components;
    Console &Root;
    ConsoleComponent(Console &Root)
        : ins(Root.ins), outs(Root.outs), Root(Root)
    {
        
    }
    void Add(ConsoleComponent &comp);
    void ShowSubComponents();
    virtual bool Show() = 0;
    virtual void DoButtons();
    virtual void DoButtons(char key);
};

#endif // _CONSOLE_COMPONENT_H_