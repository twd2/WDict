#ifndef _SELECTCONSOLE_H_
#define _SELECTCONSOLE_H_

#include "ConsoleComponent.h"
#include "Console.h"
#include <string>
#include <vector>
#include <utility>

class SelectConsole
    : public ConsoleComponent
{
public:
    std::vector<std::pair<char, std::string> > Choices;
    std::vector<size_t> SelectedIndexes;
    std::string Message;
    
    SelectConsole(Console &Root, const std::string &message)
        : ConsoleComponent(Root), Message(message)
    {
        
    }
    
    bool Show() override;
};

#endif // _SELECTCONSOLE_H_
