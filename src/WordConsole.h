#ifndef _WORDCONSOLE_H_
#define _WORDCONSOLE_H_

#include <libui.h>
#include <iostream>
#include <functional>
#include "Globals.h"

using namespace std;

class WordConsole
    : public ConsoleComponent
{
protected:
    ButtonConsole btnBack;
public:
    string Word;
    WordConsole(Console &Root, const string &Word);
    bool Show() override;

private:
    void Back();
    // void
};

#endif // _WORDCONSOLE_H_
