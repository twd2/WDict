#include "RetriveConsole.h"

bool RetriveConsole::Show()
{
    auto history = Globals::CurrentUser->GetHistory(20);
    
    if (history.size() > 0)
    {
        cout << "²éÑ¯ÀúÊ·" << endl;
        for (auto &word : history)
        {
            cout << word << " ";
        }
        cout << endl;
    }
    
    txtWord.Show();
    if (txtWord.Value != "")
    {
        Globals::CurrentUser->AppendHistory(txtWord.Value);
        Root.Goto(make_shared<WithTitleConsole>(txtWord.Value, make_shared<WordConsole>(Root, txtWord.Value)));
    }
    else
    {
        Root.Back();
    }
    
    return true;
}