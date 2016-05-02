#ifndef _TESTCONSOLE_H_
#define _TESTCONSOLE_H_

#include <libdict.h>
#include <libui.h>
#include <libtextdb.h>
#include <random>
#include <iostream>
#include <string>
#include <functional>
#include "Globals.h"
#include "WordConsole.h"

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
    shared_ptr<WordIterator> wrongAnswerIter;
    shared_ptr<WordIterator> iter;
public:
    size_t Limit;
    TestConsole(Console &Root, size_t Limit);
    
    bool Show() override;
    
    void Back();
    
private:
    string word;
    void initIter();
    answer_t CheckAnswer(const string &word); // check if the answer is correct
    answer_t CheckAnswerTF(const string &word);
    answer_t CheckAnswerSelDesc(const string &word);
    answer_t CheckAnswerSelWord(const string &word);
};

#endif // _TESTCONSOLE_H_
