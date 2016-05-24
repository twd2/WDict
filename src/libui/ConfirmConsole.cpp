#include "ConfirmConsole.h"

bool ConfirmConsole::Show()
{
    outs << Message << "(Y/N)[" << (Default ? 'Y' : 'N') << "] ";
    std::string ch;
    while (std::getline(ins, ch))
    {
        if (ch == "Y" || ch == "y")
        {
            Value = true;
            break;
        }
        else if (ch == "N" || ch == "n")
        {
            Value = false;
            break;
        }
        else if (ch == "")
        {
            Value = Default;
            break;
        }
        outs << Message << "(Y/N)[" << (Default ? 'Y' : 'N') << "] ";
    }
    return true;
}
