#include "ButtonConsole.h"

bool ButtonConsole::Show()
{
    std::cout << "[" << Key << "]    " << Title << std::endl;
    return true;
}