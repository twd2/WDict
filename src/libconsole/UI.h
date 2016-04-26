#ifndef _UI_H_
#define _UI_H_

#include "UIImpl.h"
#include <memory>
#include <iostream>

class UI
{
private:
    static std::shared_ptr<UIImpl> ui;
    
public:
    // static interfaces
    static void Init(std::shared_ptr<UIImpl> ui);
    static void Start();
};

#endif // _UI_H_