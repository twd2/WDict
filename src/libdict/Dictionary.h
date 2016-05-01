#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include "types.h"
#include <memory>
#include <string>
#include <vector>
#include "IDictionary.h"
#include "StringUtils.h"

// extending basic interface, adding level data, used as global dictionary
class Dictionary
    : public IDictionary
{
private:
    //      level database
    IDictDB &levelDB;
    
public:
    Dictionary(IDictDB &dictDB, IDictDB &sentDB, IDictDB &levelDB)
        : IDictionary(dictDB, sentDB), levelDB(levelDB)
    {

    }

    int GetLevel(const std::string &word);
    
    void AddDesc(const std::string &word, const std::string &desc) override;
    void AddSentence(const std::string &word, const std::string &sent, const std::string &desc) override;
    void DelDesc(const std::string &word, size_t id) override;
    void DelSentence(const std::string &word, size_t id) override;
};

#endif // _DICTIONARY_H_
