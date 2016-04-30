#include "TextInputConsole.h"

bool TextInputConsole::Show()
{
    std::cout << Message << " ";
    switch (TokenOrLine)
    {
    case TEXTINPUT_TOKEN:
        std::cin >> Text;
        break;
    case TEXTINPUT_LINE:
        Root.IgnoreLeftNewline();
        std::getline(std::cin, Text);
        break;
    }
    
    return true;
}