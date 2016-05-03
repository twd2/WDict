#include "MainConsole.h"

MainConsole::MainConsole(Console &Root)
    : ConsoleComponent(Root), btnRetrive(Root, '1', "单词查询"), btnText(Root, '2', "分析文本"), btnLearn(Root, '3', "学习"),
                              btnTest(Root, '4', "测验"), btnAbout(Root, 'a', "关于"), btnExit(Root, 'x', "退出")
{
    btnRetrive.OnClick = bind(&MainConsole::Retrive, this);
    Add(btnRetrive);
    
    btnText.OnClick = bind(&MainConsole::Text, this);
    Add(btnText);
    
    btnLearn.OnClick = bind(&MainConsole::Learn, this);
    Add(btnLearn);
    
    btnTest.OnClick = bind(&MainConsole::Test, this);
    Add(btnTest);
    
    btnAbout.OnClick = bind(&MainConsole::About, this);
    Add(btnAbout);

    btnExit.OnClick = bind(&MainConsole::Exit, this);
    Add(btnExit);
}

bool MainConsole::Show()
{
    WithTitleConsole(Root, "词典").Show();
    
    outs << "欢迎使用词典, 您可以输入对应字符来进入相应功能:" << endl;
    
    ShowSubComponents();
    DoButtons();

    return true;
}

void MainConsole::Retrive()
{
    Root.Goto(make_shared<RetriveConsole>(Root));
}

void MainConsole::Text()
{
    Root.Goto(make_shared<TextConsole>(Root));
}

void MainConsole::Learn()
{
    // TODO: specify limit
    Root.Goto(make_shared<LearnConsole>(Root, 20));
}

void MainConsole::Test()
{
    // TODO: specify limit
    Root.Goto(make_shared<TestConsole>(Root, 20));
}

void MainConsole::About()
{
    outs << "一个背单词程序。" << endl;
    ConfirmConsole cc(Root, "Fork me on GitHub?", true);
    cc.Show();
    if (cc.Value)
    {
        Globals::Open("https://github.com/twd2/WDict");
    }
}

void MainConsole::Exit()
{
    ConfirmConsole cc(Root, "您确定要退出吗?", true);
    cc.Show();
    if (cc.Value)
    {
        Root.Goto(nullptr);
    }
}