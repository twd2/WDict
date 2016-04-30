#ifndef _IDICTIONARY_H_
#define _IDICTIONARY_H_

#include <string>
#include <vector>
#include "types.h"
#include "WordInfo.h"

class IDictionary
{
public:
    virtual WordInfo GetDesc(const std::string &word) = 0;
    virtual WordInfo GetSentences(const std::string &word) = 0;
    virtual void AddSentence(const std::string &word, const std::string &sent, const std::string &desc) = 0;
};

#endif // _IDICTIONARY_H_
