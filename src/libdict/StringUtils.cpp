#include "StringUtils.h"

std::vector<std::string> StringUtils::GetWords(std::string text, bool unique)
{
    for (size_t i = 0; i < text.length(); ++i)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = text[i] - 'A' + 'a';
        }
        
        if (!(text[i] >= 'a' && text[i] <= 'z'))
        {
            text[i] = ' ';
        }
    }
    
    std::stringstream ss(text);
    std::vector<std::string> vec;
    std::string word;
    while (ss >> word)
    {
        vec.push_back(word);
    }
    
    if (unique)
    {
        std::sort(vec.begin(), vec.end());
        auto iter = std::unique(vec.begin(), vec.end());
        vec.resize(std::distance(vec.begin(), iter));
    }
    
    return vec;
}