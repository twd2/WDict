#ifndef _WORDCONSOLE_H_
#define _WORDCONSOLE_H_

#include <libui.h>
#include <string>
#include <iostream>
#include <functional>
#include "Globals.h"

using namespace std;

/// 词条界面
class WordConsole
    : public ConsoleComponent
{
protected:
    /// 按钮们
    ButtonConsole btnAddDesc, btnAddSent, btnDelDesc, btnDelSent, btnSearch, btnReport, btnBack;
public:
    /// 单词
    string Word;
    /// 构造
    WordConsole(Console &Root, const string &Word);
    bool Show() override;

    /// 输出单词信息
    static void PrintWord(ostream &outs, const string &str, WordInfo wi);
private:
    /// 功能们
    void AddDesc();
    void AddSent();
    void DelDesc();
    void DelSent();
    void Back();
    void Search();
    void Report();
};

#endif // _WORDCONSOLE_H_
