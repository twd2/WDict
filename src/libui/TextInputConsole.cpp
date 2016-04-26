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
        while (std::cin.peek() == '\r' || std::cin.peek() == '\n') 
        {
            char ch = std::cin.peek();
            std::cin.ignore();
            if (ch == '\n')
            {
                break;
            }
        }
        std::getline(std::cin, Text);
        break;
    }
    
    return true;
}