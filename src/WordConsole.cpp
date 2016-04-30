#include "WordConsole.h"
#include <typeinfo>

WordConsole::WordConsole(Console &Root, const string &Word)
    : ConsoleComponent(Root), btnBack(Root, 'b', "返回"), Word(Word)
{
    btnBack.OnClick = bind(&WordConsole::Back, this);
    Add(btnBack);
}

bool WordConsole::Show()
{
    auto wi = Globals::Dict->GetWord(Word);
    
    if (wi.Desc.size() > 0)
    {
        cout << "系统释义:" << endl;
        for (string desc : wi.Desc)
        {
            cout << "    " << desc << endl;
        }
    }
    else
    {
        cout << "未找到系统释义。" << endl;
    }
    
    if (wi.Sentances.size() > 0)
    {
        cout << "系统例句:" << endl;
        for (auto p : wi.Sentances)
        {
            cout << "    " << p.first << endl
                 << "    " << p.second << endl
                 << endl;
        }
    }
    else
    {
        cout << "未找到系统例句。" << endl;
    }
    
    for (auto ptr : Components)
    {
        ptr->Show();
    }
        
    DoButtons();

    return true;
}

void WordConsole::Back()
{
    Root.Back();
}