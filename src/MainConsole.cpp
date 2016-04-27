#include "MainConsole.h"

MainConsole::MainConsole(Console &Root)
    : ConsoleComponent(Root), btn0(Root, '0', "关于"), btnX(Root, 'x', "退出")
{
    btn0.OnClick = std::function<void ()>(
        [this]()
        { 
            std::cout << "twd2" << std::endl;
        }
    );
    Add(btn0);

    btnX.OnClick = std::function<void ()>(
        [this]()
        {
            ConfirmConsole cc(this->Root, "您确定要退出吗?", true);
            cc.Show();
            if (cc.Value)
            {
                this->Root.Goto(nullptr);
            }
        }
    );
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