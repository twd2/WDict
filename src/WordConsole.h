#ifndef _WORDCONSOLE_H_
#define _WORDCONSOLE_H_

#include <libui.h>
#include <string>
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
    
    static void PrintWord(const string &str, WordInfo wi);
private:
    void AddDesc();
    void AddSent();
    void DelDesc();
    void DelSent();
    void Back();
};

#endif // _WORDCONSOLE_H_
