#ifndef _TESTCONSOLE_H_
#define _TESTCONSOLE_H_

#include <libdict.h>
#include <libui.h>
#include <libtextdb.h>
#include <iostream>
#include <string>
#include "Globals.h"

using namespace std;

enum answer_t
{
    ANSWER_CORRECT,
    ANSWER_WRONG,
    ANSWER_BACK
};

class TestConsole
    : public ConsoleComponent
{
protected:
    ButtonConsole btnBack;
    shared_ptr<WordIterator> iter;
public:
    size_t Limit;
    TestConsole(Console &Root, size_t Limit);
    
    bool Show() override;
    
    void Back();
    
private:
    std::string word;
    void initIter();
    answer_t CheckAnswer(const std::string &word); // check if the answer is correct
};

#endif // _TESTCONSOLE_H_
