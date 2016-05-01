#include "TextInputConsole.h"

bool TextInputConsole::Show()
{
    std::cout << Message << " ";
    switch (Type)
    {
    case TEXTINPUT_TOKEN:
        std::cin >> Value;
        break;
    case TEXTINPUT_LINE:
        Root.IgnoreLeftNewline();
        std::getline(std::cin, Value);
        break;
    }
    
    return true;
}