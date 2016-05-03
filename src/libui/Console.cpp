#include "Console.h"
#include "ConsoleComponent.h"

bool Console::Show()
{
    if (!Activities.empty() && Activities.top())
    {
        return Activities.top()->Show();
    }
    return false;
}

void Console::Clear()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void Console::Goto(std::shared_ptr<ConsoleComponent> act)
{
    Activities.push(act);
}

void Console::Back()
{
    Activities.pop();
}

void Console::IgnoreLeftNewline()
{
    while (ins.peek() == '\r' || ins.peek() == '\n') 
    {
        char ch = ins.peek();
        ins.ignore();
        if (ch == '\n')
        {
            break;
        }
    }
}