#include "LearnConsole.h"

LearnConsole::LearnConsole(Console &Root)
    : ConsoleComponent(Root), btnBack(Root, 'b', "返回")
{
    btnBack.OnClick = bind(&LearnConsole::Back, this);
    Add(btnBack);
}

bool LearnConsole::Show()
{
    
    WithLimitIterator wli(Limit, make_shared<RandomWordIterator>(Globals::RandomEngine, *Globals::Dict));
    while (wli.HaveNext())
    {
        cout << wli.Next() << endl;
    }
    
    ShowSubComponents();
    DoButtons();
    
    return true;
}

void LearnConsole::Back()
{
    Root.Back();
}