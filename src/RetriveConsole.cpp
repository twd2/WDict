#include "RetriveConsole.h"

bool RetriveConsole::Show()
{
    txtWord.Show();
    if (txtWord.Value != "")
    {
        Root.Goto(make_shared<WithTitleConsole>(txtWord.Value, make_shared<WordConsole>(Root, txtWord.Value)));
        std::cout << txtWord.Value << std::endl;
    }
    else
    {
        Root.Back();
    }
    
    return true;
}