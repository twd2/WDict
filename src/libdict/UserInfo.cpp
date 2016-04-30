#include "UserInfo.h"

void UserInfo::IncCounter(const std::string &word, user_counter_t type, unsigned long value)
{
    WordInfo wi = GetCounters(word);
    SetCounter(word, type, wi.Counters[type] + value);
}

void UserInfo::SetCounter(const std::string &word, user_counter_t type, unsigned long value)
{
    auto &vec = counterDB[word];
    while (vec.size() < COUNTER_COUNT)
    {
        vec.push_back("0");
    }
    vec[type] = StringUtils::ToString(value);
}

WordInfo UserInfo::GetCounters(const std::string &word)
{
    WordInfo wi;
    wi.Word = word;
    
    auto iter = counterDB.find(word);
    
    if (iter == counterDB.end())
    {
        while (wi.Counters.size() < COUNTER_COUNT)
        {
            wi.Counters.push_back(0);
        }
        return wi;
    }
    
    auto &vec = iter->second;
    for (std::string c : vec)
    {
        wi.Counters.push_back(StringUtils::FromString<unsigned long>(c));
    }
    
    while (wi.Counters.size() < COUNTER_COUNT)
    {
        wi.Counters.push_back(0);
    }
    
    return wi;
}

std::vector<std::string> UserInfo::GetHistory(size_t limit)
{
    std::queue<std::string> Q;
    std::ifstream ifs(historyFilename, std::ios_base::in);
    std::string word;
    while (std::getline(ifs, word))
    {
        while (Q.size() >= limit)
        {
            Q.pop();
        }
        
        Q.push(word);
    }
    ifs.close();
    
    std::vector<std::string> history;
    while (!Q.empty())
    {
        history.push_back(Q.front());
        Q.pop();
    }
    return history;
}

void UserInfo::AppendHistory(const std::string &word)
{
    std::ofstream ofs(historyFilename, std::ios_base::app);
    ofs << word << std::endl;
    ofs.close();
    IncCounter(word, COUNTER_RETRIVE);
}