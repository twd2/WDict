#include "ConsoleComponent.h"
#include "ButtonConsole.h"

void ConsoleComponent::Add(ConsoleComponent &comp)
{
    Components.push_back(&comp);
}

void ConsoleComponent::ShowSubComponents()
{
    for (auto ptr : Components)
    {
        ptr->Show();
    }
}

void ConsoleComponent::DoButtons()
{
    char ch;
    ch = std::cin.get();
    Root.IgnoreLeftNewline();
    DoButtons(ch);
}

void ConsoleComponent::DoButtons(char key)
{
    for (auto ptr : Components)
    {
        auto bcptr = dynamic_cast<ButtonConsole*>(ptr);
        if (!bcptr)
        {
            continue;
        }
        
        if (bcptr->Key == key)
        {
            bcptr->OnClick();
        }
    }
}