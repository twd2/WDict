#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include "types.h"
#include <memory>
#include <string>
#include <vector>
#include "IDictionary.h"

class Dictionary
    : public IDictionary
{
private:
    //      词典,     例句
    IDictDB &dictDB, &sentDB;
    
public:
    Dictionary(IDictDB &dictDB, IDictDB &sentDB)
        : dictDB(dictDB), sentDB(sentDB)
    {

    }
    
    // implementation for IDictionary
    WordInfo GetDesc(const std::string &word) override;
    WordInfo GetSentences(const std::string &word) override;
    void AddSentence(const std::string &word, const std::string &sent, const std::string &desc) override;
};

#endif // _DICTIONARY_H_
