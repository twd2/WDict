#ifndef _MAINCONSOLE_H_
#define _MAINCONSOLE_H_

#include <libui.h>
#include <iostream>
#include <functional>
#include <memory>
#include "RetriveConsole.h"

using namespace std;

class MainConsole
    : public ConsoleComponent
{
protected:
    ButtonConsole btnRetrive, btnAbout, btnExit;
public:
    MainConsole(Console &Root);
    bool Show() override;

private:
    void Retrive();
    void About();
    void Exit();
};

#endif // _MAINCONSOLE_H_