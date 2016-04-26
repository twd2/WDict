#ifndef _CONSOLE_COMPONENT_H_
#define _CONSOLE_COMPONENT_H_

class Console;

class ConsoleComponent
{
public:
    Console &Root;
    ConsoleComponent(Console &Root)
        : Root(Root)
    {
        
    }
    virtual bool Show() = 0;
};

#endif // _CONSOLE_COMPONENT_H_