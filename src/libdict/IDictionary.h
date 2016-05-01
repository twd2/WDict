#ifndef _IDICTIONARY_H_
#define _IDICTIONARY_H_

#include <string>
#include <vector>
#include "types.h"
#include "WordInfo.h"

// 基本词典接口
class IDictionary
{
protected:
    //      词典,     例句
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
    
    virtual WordInfo GetWord(const std::string &word);
    virtual void AddDesc(const std::string &word, const std::string &desc);
    virtual void AddSentence(const std::string &word, const std::string &sent, const std::string &desc);
    virtual void DelDesc(const std::string &word, size_t id);
    virtual void DelSentence(const std::string &word, size_t id);
private:
    void refreshWordsCache();
};

#endif // _IDICTIONARY_H_
