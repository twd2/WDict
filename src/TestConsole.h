#ifndef _TESTCONSOLE_H_
#define _TESTCONSOLE_H_

#include <libdict.h>
#include <libui.h>
#include <libtextdb.h>
#include <iostream>
#include <string>

using namespace std;

class TestConsole
    : public ConsoleComponent
{
protected:
    ButtonConsole btnBack;
public:
    size_t Limit = 50;
    TestConsole(Console &Root);
    
    bool Show() override;
    
    void Back();
};

#endif // _TESTCONSOLE_H_
