#include "RetriveConsole.h"

RetriveConsole::RetriveConsole(Console &Root)
    : ConsoleComponent(Root), txtWord(Root, "请输入要查询的单词(输入空行返回):", TEXTINPUT_LINE)
{
    
}

bool RetriveConsole::Show()
{
    WithTitleConsole(Root, "单词查询").Show();
    
    auto history = Globals::CurrentUser->GetHistory(20);
    
    if (history.size() > 0)
    {
        outs << "查询历史" << endl;
        for (auto &word : history)
        {
            outs << word << " ";
        }
        outs << endl;
    }
    
    txtWord.Show();
    if (txtWord.Value != "")
    {
        Globals::CurrentUser->AppendHistory(txtWord.Value);
        Root.Goto(make_shared<WordConsole>(Root, txtWord.Value));
    }
    else
    {
        Root.Back();
    }
    
    return true;
}