#include "IDictionary.h"


WordInfo IDictionary::GetDesc(const std::string &word)
{
    WordInfo wi;
    wi.Word = word;
    wi.Desc = dictDB[word];
}

WordInfo IDictionary::GetSentences(const std::string &word)
{
    WordInfo wi;
    wi.Word = word;
    
}

void IDictionary::AddSentence(const std::string &word, const std::string &sent, const std::string &desc)
{
    
}