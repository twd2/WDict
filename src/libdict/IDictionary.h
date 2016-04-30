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
    
    virtual WordInfo GetDesc(const std::string &word);
    virtual WordInfo GetSentences(const std::string &word);
    virtual void AddSentence(const std::string &word, const std::string &sent, const std::string &desc);
};

#endif // _IDICTIONARY_H_
