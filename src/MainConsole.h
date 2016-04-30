#ifndef _MAINCONSOLE_H_
#define _MAINCONSOLE_H_

#include <libui.h>
#include <iostream>
#include <functional>

class MainConsole
    : public ConsoleComponent
{
protected:
    ButtonConsole btn0, btnX;
public:
    MainConsole(Console &Root);
    bool Show() override;

private:
    void About();
    void Exit();
};

#endif // _MAINCONSOLE_H_