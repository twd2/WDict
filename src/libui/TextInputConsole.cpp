#include "TextInputConsole.h"

bool TextInputConsole::Show()
{
    outs << Message << " ";
    switch (Type)
    {
    case TEXTINPUT_TOKEN:
        ins >> Value;
        Root.IgnoreLeftNewline();
        break;
    case TEXTINPUT_LINE:
        std::getline(ins, Value);
        break;
    }
    
    return true;
}