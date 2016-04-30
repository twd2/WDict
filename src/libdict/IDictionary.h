#ifndef _IDICTIONARY_H_
#define _IDICTIONARY_H_

#include <string>
#include <vector>
#include "types.h"
#include "WordInfo.h"

// 基本词典接口
class IDictionary
{
private:
    //      词典,     例句
    IDictDB &dictDB, &sentDB;
public:
    IDictionary(IDictDB &dictDB, IDictDB &sentDB)
        : dictDB(dictDB), sentDB(sentDB)
    {

    }
    
    size_t Size()
    {
        return dictDB.size();
    }
    
    virtual WordInfo GetWord(const std::string &word);
    virtual void AddDesc(const std::string &word, const std::string &desc);
    virtual void AddSentence(const std::string &word, const std::string &sent, const std::string &desc);
    virtual void DelDesc(const std::string &word, size_t id);
    virtual void DelSentence(const std::string &word, size_t id);
};

#endif // _IDICTIONARY_H_
