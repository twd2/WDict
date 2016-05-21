#include "SelectConsole.h"

char SelectConsole::ToLower(char ch)
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
        outs << "(" << p.first << ") " << p.second << std::endl;
    }
    outs << Message << " ";
    
    std::string selected;
    std::getline(ins, selected);
    Value = selected;
    
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
                if (ToLower(selected[i]) == ToLower(p.first))
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
            if (ToLower(Choices[index].first) == ToLower(ch))
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