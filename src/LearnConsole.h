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

/// 学习界面
class LearnConsole
    : public ConsoleComponent
{
protected:
	/// 按钮们，单词列表
    ButtonConsole btnGot, btnWord, btnBack;
    shared_ptr<WordIterator> iter;
public:
	/// 单词数
    size_t Limit;
	/// 构造
    LearnConsole(Console &Root, size_t Limit);

    bool Show() override;

	/// 功能按钮
    void Got();
    void Word();
    void Back();

private:
	/// 当前单词
    std::string word;
	/// 初始化单词迭代器
    void initIter();
};

#endif // _LEARNCONSOLE_H_
