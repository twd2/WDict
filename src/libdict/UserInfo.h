#ifndef _USERINFO_H_
#define _USERINFO_H_

#include "types.h"
#include <memory>
#include <string>
#include <vector>
#include "Dictionary.h"

enum counter_t
{
    COUNTER_RETRIVE, // 查询次数
    COUNTER_LEARN, // 学习次数
    COUNTER_TEST, // 测试次数
    COUNTER_PASS // 回答正确次数
};

class UserInfo
    : public Dictionary
{
private:
    //     基本信息, 学习记录, 用户词典, 用户例句
    IDictDB &infoDB, &counterDB;
    std::string historyFilename;
public:
    std::string Name;
    
    UserInfo(IDictDB &infoDB, IDictDB &counterDB, IDictDB &dictDB, IDictDB &sentDB, const std::string &Name)
        : Dictionary(dictDB, sentDB), infoDB(infoDB), counterDB(counterDB), Name(Name)
    {
        historyFilename = Name + "_history";
    }
    
    void IncCounter(const std::string &word, counter_t type, unsigned long value = 1);
    WordInfo GetCounters(const std::string &word);
    
    // implementation for IDictionary
    WordInfo GetDesc(const std::string &word) override;
    WordInfo GetSentences(const std::string &word) override;
    void AddSentence(const std::string &word, const std::string &sent, const std::string &desc) override;
    
    void AppendHistory(const std::string &word);
};

#endif // _USERINFO_H_
