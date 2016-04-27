#include "ConsoleComponent.h"
#include "ButtonConsole.h"

void ConsoleComponent::Add(ConsoleComponent &comp)
{
    Components.push_back(&comp);
}

void ConsoleComponent::DoButtons()
{
    DoButtons(std::cin.get());
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