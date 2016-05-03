#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <stack>
#include <cstdlib>
#include <iostream>
#include <memory>
#include "UIImpl.h"

class ConsoleComponent;

class Console
    : public UIImpl
{
protected:
    std::istream &ins;
    std::ostream &outs;
public:
    std::stack<std::shared_ptr<ConsoleComponent> > Activities;
    
    Console(std::istream &ins, std::ostream &outs)
        : ins(ins), outs(outs)
    {
        
    }
    
    bool Show() override;
    void Clear();
    void Goto(std::shared_ptr<ConsoleComponent> act);
    void Back();
    void IgnoreLeftNewline();
    
    friend class ConsoleComponent;
};

#endif // _CONSOLE_H_