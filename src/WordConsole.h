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
    ButtonConsole btnAddDesc, btnAddSent, btnDelDesc, btnDelSent, btnBack;
public:
    string Word;
    WordConsole(Console &Root, const string &Word);
    bool Show() override;

private:
    static void PrintWord(const string &str, WordInfo wi);
    void AddDesc();
    void AddSent();
    void DelDesc();
    void DelSent();
    void Back();
    // void
};

#endif // _WORDCONSOLE_H_
