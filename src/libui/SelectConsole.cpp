#include "SelectConsole.h"

bool SelectConsole::Show()
{
    for (auto &p : Choices)
    {
        std::cout << "(" << p.first << ") " << p.second << std::endl;
    }
    std::cout << Message << " ";
    
    std::string selected;
    Root.IgnoreLeftNewline();
    std::getline(std::cin, selected);
    
    SelectedIndexes.clear();
    for (size_t i = 0; i < selected.length(); ++i)
    {
        for (auto &p : Choices)
        {
            if (selected[i] == p.first)
            {
                SelectedIndexes.push_back(i);
            }
        }
    }
    return true;
}