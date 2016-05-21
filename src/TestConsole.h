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
#include "QuestionBuilderConsole.h"

using namespace std;



class TestConsole
    : public ConsoleComponent
{
protected:
    QuestionBuilderConsole questionBuilder;
    shared_ptr<QuestionGenerator> questionGenerator;
    shared_ptr<WordIterator> wrongAnswerIter;
    shared_ptr<WordIterator> iter;
    WordIteratorCreator &iterCreator;
public:
    size_t Limit, Counters[ANSWER_COUNT] = {0};
    string Title;
    vector<string> IncorrectWords;
    TestConsole(Console &Root, WordIteratorCreator &iterCreator, size_t limit, const string &title);
    
    bool Show() override;
    
private:
    string word, answer;
    void initIter();
};

#endif // _TESTCONSOLE_H_
