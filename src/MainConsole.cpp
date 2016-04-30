#include "MainConsole.h"

MainConsole::MainConsole(Console &Root)
    : ConsoleComponent(Root), btn0(Root, '0', "关于"), btnX(Root, 'x', "退出")
{
    btn0.OnClick = std::bind(&MainConsole::About, this);
    Add(btn0);

    btnX.OnClick = std::bind(&MainConsole::Exit, this);
    Add(btnX);
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