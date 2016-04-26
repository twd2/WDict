#include "WithTitleConsole.h"

bool WithTitleConsole::Show()
{
    std::cout << std::string(40, ' ') << title << std::endl;
    std::cout << std::string(80, '=') << title << std::endl;
    return comp->Show();
}