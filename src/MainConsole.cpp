#include "MainConsole.h"

MainConsole::MainConsole(Console &Root)
    : ConsoleComponent(Root), btnRetrive(Root, '0', "查词"), btnText(Root, '1', "分析文本"),
                              btnAbout(Root, 'z', "关于"), btnExit(Root, 'x', "退出")
{
    btnRetrive.OnClick = std::bind(&MainConsole::Retrive, this);
    Add(btnRetrive);
    
    btnText.OnClick = std::bind(&MainConsole::Text, this);
    Add(btnText);
    
    btnAbout.OnClick = std::bind(&MainConsole::About, this);
    Add(btnAbout);

    btnExit.OnClick = std::bind(&MainConsole::Exit, this);
    Add(btnExit);
}

bool MainConsole::Show()
{
    std::cout << "欢迎使用词典, 您可以输入对应字符来进入相应功能:" << std::endl;
    
    for (auto ptr : Components)
    {
        ptr->Show();
    }
        
    DoButtons();

    return true;
}

void MainConsole::Retrive()
{
    Root.Goto(make_shared<WithTitleConsole>("单词查询", make_shared<RetriveConsole>(Root)));
}

void MainConsole::Text()
{
    Root.Goto(make_shared<WithTitleConsole>("文本分析", make_shared<TextConsole>(Root)));
}

void MainConsole::About()
{
    std::cout << "一个背单词程序。" << std::endl;
    ConfirmConsole cc(Root, "好?", true);
    cc.Show();
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