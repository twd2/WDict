#ifndef _WORDINFO_H_
#define _WORDINFO_H_

#include <string>
#include <vector>

class WordInfo
{
public:
    std::string Word;
    std::vector<std::string> Desc;
    std::vector<std::pair<std::string, std::string> > Sentances;
    std::vector<unsigned long> Counters;
};

#endif // _WORDINFO_H_
