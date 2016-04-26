#include "WithTitleConsole.h"

bool WithTitleConsole::Show()
{
    Root.Clear();
    std::cout << std::string(40, ' ') << title << std::endl;
    std::cout << std::string(80, '=') << std::endl;
    return comp->Show();
}