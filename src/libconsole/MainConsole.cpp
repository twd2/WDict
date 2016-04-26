#include "MainConsole.h"

bool MainConsole::Show()
{
    std::cout << "REAL HELLO!" << std::endl;
    
    ButtonConsole btn0(Root, '0', "About", std::function<void ()>(
        [this]()
        { 
            std::cout << "twd2" << std::endl;
        }
    ));

    ButtonConsole btnX(Root, 'x', "Exit", std::function<void ()>(
        [this]()
        { 
            Root.Goto(nullptr);
        }
    ));
    btn0.OnClick();

    
    return true;
}