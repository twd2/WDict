#include "ConfirmConsole.h"

bool ConfirmConsole::Show()
{
    std::cout << Message << "(Y/N)[" << (Default ? 'Y' : 'N') << "] ";
    std::string ch;
    while (std::cin.peek() == '\r' || std::cin.peek() == '\n') 
    {
        char ch = std::cin.peek();
        std::cin.ignore();
        if (ch == '\n')
        {
            break;
        }
    }
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