#ifndef _TEXTCONSOLE_H_
#define _TEXTCONSOLE_H_

#include <libdict.h>
#include <libui.h>
#include <libtextdb.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "WordConsole.h"
#include "EvaluateStrategy.h"

using namespace std;

class TextConsole
    : public ConsoleComponent
{
protected:
    TextInputConsole txtFilename, txtWord;
    string filename;
    vector<string> Words;
public:
    TextConsole(Console &Root);
    
    bool Show() override;
};

#endif // _TEXTCONSOLE_H_
