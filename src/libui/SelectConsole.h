#ifndef _SELECTCONSOLE_H_
#define _SELECTCONSOLE_H_

#include "ConsoleComponent.h"
#include "Console.h"
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

class SelectConsole
    : public ConsoleComponent
{
public:
    bool IgnoreCase = false;
    std::vector<std::pair<char, std::string> > Choices;
    std::vector<size_t> SelectedIndexes;
    std::string Message;
    
    SelectConsole(Console &Root, const std::string &message)
        : ConsoleComponent(Root), Message(message)
    {
        
    }
    
    void Add(char ch, const std::string &title)
    {
        Choices.push_back(std::make_pair(ch, title));
    }
    
    bool Show() override;
    
    bool Selected(char ch);
    bool Selected(size_t index);
    
private:
    static char toLower(char ch);
};

#endif // _SELECTCONSOLE_H_
