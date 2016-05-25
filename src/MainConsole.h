#ifndef _MAINCONSOLE_H_
#define _MAINCONSOLE_H_

#include <libui.h>
#include <iostream>
#include <functional>
#include <memory>
#include "RetriveConsole.h"
#include "TextConsole.h"
#include "LearnConsole.h"
#include "TestConsole.h"
#include "HtmlQuestionBuilder.h"

using namespace std;

/// 首页
class MainConsole
    : public ConsoleComponent
{
protected:
    /// 按钮们
    ButtonConsole btnRetrive, btnText, btnLearn, btnTestAsLearn, btnTest, btnAbout, btnHackMe, btnExit;
public:
    /// 构造
    MainConsole(Console &Root);
    bool Show() override;

private:
    /// 进入各功能
    void Retrive();
    void Text();
    void Learn();
    void TestAsLearn();
    void Test();
    void About();
    /// 命令解析
    static pair<string, string> parseCommand(string cmdarg);
    void HackMe();
    void Exit();
};

#endif // _MAINCONSOLE_H_
