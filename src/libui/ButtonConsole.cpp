#include "ButtonConsole.h"

bool ButtonConsole::Show()
{
    outs << "[" << Key << "]    " << Title << std::endl;
    return true;
}
