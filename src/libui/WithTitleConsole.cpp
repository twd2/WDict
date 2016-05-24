#include "WithTitleConsole.h"

bool WithTitleConsole::Show()
{
    Root.Clear();
    if (title.length() < 80)
    {
        outs << std::string((80 - title.length()) / 2, ' ') << title << std::endl;
    }
    else
    {
        outs << title << std::endl;
    }
    
    outs << std::string(80, '=') << std::endl;
    
    if (comp)
    {
        return comp->Show();
    }
    else
    {
        return true;
    }
}
