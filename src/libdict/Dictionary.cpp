#include "Dictionary.h"

int Dictionary::GetLevel(const std::string &word)
{
    auto iter = levelDB.find(word);
    
    if (iter == levelDB.end())
    {
        return -1;
    }
    
    auto &vec = iter->second;
    if (vec.size() == 0 || vec[0] == "")
    {
        return -1;
    }
    else
    {
        return DictStringUtils::FromString<int>(vec[0]);
    }
}

void Dictionary::AddDesc(const std::string &word, const std::string &desc)
{
    throw std::string("Dictionary is readonly.");
}

void Dictionary::AddSentence(const std::string &word, const std::string &sent, const std::string &desc)
{
    throw std::string("Dictionary is readonly.");
}

void Dictionary::DelDesc(const std::string &word, size_t id)
{
    throw std::string("Dictionary is readonly.");
}

void Dictionary::DelSentence(const std::string &word, size_t id)
{
    throw std::string("Dictionary is readonly.");
}
