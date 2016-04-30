#ifndef _USERINFO_H_
#define _USERINFO_H_

#include "types.h"
#include <memory>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include "StringUtils.h"
#include "Dictionary.h"

enum user_counter_t
{
    COUNTER_RETRIVE, // 查询次数
    COUNTER_LEARN, // 学习次数
    COUNTER_TEST, // 测试次数
    COUNTER_PASS, // 回答正确次数
    COUNTER_LEVEL, // 用户评级
    COUNTER_COUNT // 如上记录数(现在为5)
};

// 对基本词典接口扩展, 加入用户信息, 作为用户词典, 同时作为用户类
class UserInfo
    : public IDictionary
{
private:
    //     基本信息, 学习记录
    IDictDB &infoDB, &counterDB;
    std::string historyFilename;
public:
    std::string Name;
    
    UserInfo(IDictDB &infoDB, IDictDB &counterDB, IDictDB &dictDB, IDictDB &sentDB, const std::string &Name)
        : IDictionary(dictDB, sentDB), infoDB(infoDB), counterDB(counterDB), Name(Name)
    {
        historyFilename = Name + "_history";
    }
    
    void IncCounter(const std::string &word, user_counter_t type, unsigned long value = 1);
    void SetCounter(const std::string &word, user_counter_t type, unsigned long value);
    WordInfo GetCounters(const std::string &word);
    
    std::vector<std::string> GetHistory(size_t limit = -1);
    void AppendHistory(const std::string &word);
    
    template <typename T>
    T Get(const std::string &key, T def);
    
    template <typename T>
    void Set(const std::string &key, T value);
};

template <typename T>
T UserInfo::Get(const std::string &key, T def)
{
    auto &vec = infoDB[key];
    if (vec.size() == 0 || vec[0] == "")
    {
        Set(key, def);
        return def;
    }
    return StringUtils::FromString<T>(vec[0]);
}
    
template <typename T>
void UserInfo::Set(const std::string &key, T value)
{
    auto &vec = infoDB[key];
    if (vec.size() == 0)
    {
        vec.push_back("");
    }
    vec[0] = StringUtils::ToString(value);
}

#endif // _USERINFO_H_
