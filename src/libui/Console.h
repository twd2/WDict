#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <stack>
#include <cstdlib>
#include <iostream>
#include <memory>
#include "UIImpl.h"
#include "ConsoleComponent.h"

class Console
    : public UIImpl
{
public:
    std::stack<std::shared_ptr<ConsoleComponent> > Activities;
    bool Show() override;
    void Clear();
    void Goto(std::shared_ptr<ConsoleComponent> act);
    void Back();
    void IgnoreLeftNewline();
};

#endif // _CONSOLE_H_