#include "Console.h"

bool Console::Show()
{
    std::cout << "hello, world" << std::endl;
    if (Activity)
    {
        return Activity->Show();
    }
    else
    {
        return false;
    }
}