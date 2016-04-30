#include "IDictionary.h"


WordInfo IDictionary::GetWord(const std::string &word)
{
    WordInfo wi;
    wi.Word = word;
    
    {
        auto iter = dictDB.find(word);
        if (iter != dictDB.end())
        {
            wi.Desc = iter->second;
        }
    }
    
    {
        auto iter = sentDB.find(word);
        if (iter != sentDB.end())
        {
            auto &vec = iter->second;
            for (size_t i = 0; i < vec.size() - 1; i += 2)
            {
                wi.Sentances.push_back(make_pair(vec[i], vec[i + 1]));
            }
        }
    }
    
    return wi;  
}

void IDictionary::AddDesc(const std::string &word, const std::string &desc)
{
    dictDB[word].push_back(desc); 
}

void IDictionary::AddSentence(const std::string &word, const std::string &sent, const std::string &desc)
{
    sentDB[word].push_back(sent);
    sentDB[word].push_back(desc);
}