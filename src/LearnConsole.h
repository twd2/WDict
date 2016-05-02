#ifndef _LEARNCONSOLE_H_
#define _LEARNCONSOLE_H_

#include <libdict.h>
#include <libui.h>
#include <libtextdb.h>
#include <iostream>
#include <string>
#include "Globals.h"
#include "WordConsole.h"

using namespace std;

class LearnConsole
    : public ConsoleComponent
{
protected:
    ButtonConsole btnGot, btnWord, btnBack;
    shared_ptr<WordIterator> iter;
public:
    size_t Limit;
    LearnConsole(Console &Root, size_t Limit);
    
    bool Show() override;
    
    void Got();
    void Word();
    void Back();
private:
    void initIter();
    std::string word;
};

#endif // _LEARNCONSOLE_H_
