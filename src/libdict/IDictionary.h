#ifndef _IDICTIONARY_H_
#define _IDICTIONARY_H_

#include <string>
#include <vector>
#include <functional>
#include "types.h"
#include "DictStringUtils.h"
#include "WordInfo.h"

// basic dictionary interface
class IDictionary
{
protected:
    //      dict,    sentences
    IDictDB &dictDB, &sentDB;
    std::vector<std::string> words;
public:
    IDictionary(IDictDB &dictDB, IDictDB &sentDB);
    
    size_t Size()
    {
        return words.size();
    }
    
    std::string operator[](size_t index)
    {
        return words[index];
    }
    
    std::vector<std::string> GetRelated(const std::string &word, size_t limit = 50)
    {
        return GetRelated(word, std::function<size_t (const std::string&, const std::string&)>([] (const std::string &input, const std::string &temp) {
            return DictStringUtils::Distance(input, temp);
        }), limit);
    }
    
    std::vector<std::string> GetRelated(const std::string &word, std::function<size_t (const std::string&, const std::string&)> pred, size_t limit = 50);
    
    virtual WordInfo GetWord(const std::string &word);
    virtual void AddDesc(const std::string &word, const std::string &desc);
    virtual void AddSentence(const std::string &word, const std::string &sent, const std::string &desc);
    virtual void DelDesc(const std::string &word, size_t id);
    virtual void DelSentence(const std::string &word, size_t id);
private:
    void refreshWordsCache();
};

#endif // _IDICTIONARY_H_
