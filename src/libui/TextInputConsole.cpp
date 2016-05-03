#include "TextInputConsole.h"

bool TextInputConsole::Show()
{
    std::cout << Message << " ";
    switch (Type)
    {
    case TEXTINPUT_TOKEN:
        std::cin >> Value;
        Root.IgnoreLeftNewline();
        break;
    case TEXTINPUT_LINE:
        std::getline(std::cin, Value);
        break;
    }
    
    return true;
}