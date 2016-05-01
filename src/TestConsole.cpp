#include "TestConsole.h"

TestConsole::TestConsole(Console &Root)
    : ConsoleComponent(Root), btnBack(Root, 'b', "返回")
{
    btnBack.OnClick = bind(&TestConsole::Back, this);
    Add(btnBack);
}

bool TestConsole::Show()
{
    ShowSubComponents();
    DoButtons();
    
    return true;
}

void TestConsole::Back()
{
    Root.Back();
}