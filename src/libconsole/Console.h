#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <iostream>
#include <memory>
#include "UIImpl.h"
#include "ConsoleComponent.h"

class Console
    : public UIImpl
{
public:
    std::shared_ptr<ConsoleComponent> Activity = nullptr;
    bool Show() override;
};

#endif // _CONSOLE_H_