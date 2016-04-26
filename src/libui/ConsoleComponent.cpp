#include "ConsoleComponent.h"
#include "ButtonConsole.h"

void ConsoleComponent::Add(ConsoleComponent &comp)
{
    Components.push_back(std::shared_ptr<ConsoleComponent>(&comp));
}

void ConsoleComponent::Add(std::shared_ptr<ConsoleComponent> comp)
{
    Components.push_back(comp);
}

void ConsoleComponent::DoButtons()
{
    DoButtons(std::cin.get());
}

void ConsoleComponent::DoButtons(char key)
{
    for (auto &ptr : Components)
    {
        auto bcptr = std::dynamic_pointer_cast<ButtonConsole>(ptr);
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