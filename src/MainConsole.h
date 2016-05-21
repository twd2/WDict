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

class MainConsole
    : public ConsoleComponent
{
protected:
    ButtonConsole btnRetrive, btnText, btnLearn, btnTestAsLearn, btnTest, btnAbout, btnHackMe, btnExit;
public:
    MainConsole(Console &Root);
    bool Show() override;

private:
    void Retrive();
    void Text();
    void Learn();
    void TestAsLearn();
    void Test();
    void About();
    void HackMe();
    void Exit();
};

#endif // _MAINCONSOLE_H_