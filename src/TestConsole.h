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


/// 测试界面
class TestConsole
    : public ConsoleComponent
{
protected:
    /// 问题界面，问题生成器，错误答案生成器，正确答案生成器，单词迭代器生成器
    QuestionBuilderConsole questionBuilder;
    shared_ptr<QuestionGenerator> questionGenerator;
    shared_ptr<WordIterator> wrongAnswerIter;
    shared_ptr<WordIterator> iter;
    WordIteratorCreator &iterCreator;
public:
    /// 问题数量，答案计数器
    size_t Limit, Counters[ANSWER_COUNT] = {0};
    /// 标题
    string Title;
    /// 答错的词
    vector<string> IncorrectWords;
    ///构造
    TestConsole(Console &Root, WordIteratorCreator &iterCreator, size_t limit, const string &title);

    bool Show() override;

private:
    /// 当前词与答案
    string word, answer;
    /// 初始化迭代器
    void initIter();
};

#endif // _TESTCONSOLE_H_
