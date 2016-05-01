#include "TestConsole.h"

TestConsole::TestConsole(Console &Root)
    : ConsoleComponent(Root), btnBack(Root, 'b', "返回"), selAnswer(Root, "请作答:")
{
    btnBack.OnClick = bind(&TestConsole::Back, this);
    Add(btnBack);
}

bool TestConsole::Show()
{
    selAnswer.Choices.clear();
    selAnswer.Choices.push_back(make_pair('A', "hello"));
    selAnswer.Choices.push_back(make_pair('B', "world"));
    selAnswer.Choices.push_back(make_pair('C', "int.你好"));
    selAnswer.Choices.push_back(make_pair('D', "n.世界"));
    selAnswer.Show();
    
    ShowSubComponents();
    DoButtons();
    
    return true;
}

void TestConsole::Back()
{
    Root.Back();
}