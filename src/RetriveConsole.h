#ifndef _RETRIVECONSOLE_H_
#define _RETRIVECONSOLE_H_

#include <libui.h>
#include <iostream>
#include <memory>
#include "WordConsole.h"

using namespace std;

class RetriveConsole
    : public ConsoleComponent
{
protected:
    TextInputConsole txtWord;
public:
    RetriveConsole(Console &Root);
    
    bool Show() override;
};

#endif // _RETRIVECONSOLE_H_
