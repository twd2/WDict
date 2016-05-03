#include "ConfirmConsole.h"

bool ConfirmConsole::Show()
{
    std::cout << Message << "(Y/N)[" << (Default ? 'Y' : 'N') << "] ";
    std::string ch;
    while (std::getline(std::cin, ch))
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
        std::cout << Message << "(Y/N)[" << (Default ? 'Y' : 'N') << "] ";
    }
    return true;
}