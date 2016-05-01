#include "LearnConsole.h"

LearnConsole::LearnConsole(Console &Root)
    : ConsoleComponent(Root), btnBack(Root, 'b', "返回")
{
    btnBack.OnClick = bind(&LearnConsole::Back, this);
    Add(btnBack);
}

bool LearnConsole::Show()
{
    ShowSubComponents();
    DoButtons();
    
    return true;
}

void LearnConsole::Back()
{
    Root.Back();
}