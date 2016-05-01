#include "WithTitleConsole.h"

bool WithTitleConsole::Show()
{
    Root.Clear();
    if (title.length() < 80)
    {
        std::cout << std::string((80 - title.length()) / 2, ' ') << title << std::endl;
    }
    else
    {
        std::cout << title << std::endl;
    }
    
    std::cout << std::string(80, '=') << std::endl;
    return comp->Show();
}