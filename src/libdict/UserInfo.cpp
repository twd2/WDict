#include "UserInfo.h"

void UserInfo::IncCounter(const std::string &word, user_counter_t type, ptrdiff_t value)
{
    std::vector<ptrdiff_t> counters = GetCounters(word);
    SetCounter(word, type, counters[type] + value);
}

void UserInfo::SetCounter(const std::string &word, user_counter_t type, ptrdiff_t value)
{
    auto &vec = counterDB[word];
    while (vec.size() < COUNTER_COUNT)
    {
        vec.push_back("0");
    }
    vec[type] = DictStringUtils::ToString(value);
}

std::vector<ptrdiff_t> UserInfo::GetCounters(const std::string &word)
{
    std::vector<ptrdiff_t> counters;

    auto iter = counterDB.find(word);

    if (iter == counterDB.end())
    {
        while (counters.size() < COUNTER_COUNT)
        {
            counters.push_back(0);
        }
        return counters;
    }

    auto &vec = iter->second;
    for (std::string c : vec)
    {
        counters.push_back(DictStringUtils::FromString<ptrdiff_t>(c));
    }

    while (counters.size() < COUNTER_COUNT)
    {
        counters.push_back(0);
    }

    return counters;
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
