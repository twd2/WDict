#ifndef _LEARNCONSOLE_H_
#define _LEARNCONSOLE_H_

#include <libdict.h>
#include <libui.h>
#include <libtextdb.h>
#include <iostream>
#include <string>
#include "Globals.h"

using namespace std;

class LearnConsole
    : public ConsoleComponent
{
protected:
    ButtonConsole btnBack;
public:
    size_t Limit = 5;
    LearnConsole(Console &Root);
    
    bool Show() override;
    
    void Back();
};

#endif // _LEARNCONSOLE_H_
