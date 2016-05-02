#include "SelectConsole.h"

char SelectConsole::toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 'a';
    }
    return ch;
}

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
        for (size_t j = 0; j < Choices.size(); ++j)
        {
            auto &p = Choices[j];
            if (!IgnoreCase)
            {
                if (selected[i] == p.first)
                {
                    SelectedIndexes.push_back(j);
                }
            }
            else
            {
                if (toLower(selected[i]) == toLower(p.first))
                {
                    SelectedIndexes.push_back(j);
                }
            }
        }
    }
    return true;
}

bool SelectConsole::Selected(char ch)
{
    for (size_t index : SelectedIndexes)
    {
        if (!IgnoreCase)
        {
            if (Choices[index].first == ch)
            {
                return true;
            }
        }
        else
        {
            if (toLower(Choices[index].first) == toLower(ch))
            {
                return true;
            }
        }
    }
    
    return false;
}

bool SelectConsole::Selected(size_t index)
{
    return std::find(SelectedIndexes.begin(), SelectedIndexes.end(), index) != SelectedIndexes.end();
}