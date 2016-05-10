#include "DictStringUtils.h"

std::vector<std::string> DictStringUtils::GetWords(std::string text, bool unique)
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

size_t DictStringUtils::Distance(const std::string &a, const std::string &b)
{
    size_t d[a.length() + 1][b.length() + 1];
    for (size_t i = 0; i <= a.length(); ++i)
    {
        d[i][0] = i;
    }
    for (size_t i = 0; i <= b.length(); ++i)
    {
        d[0][i] = i;
    }
    
    for (size_t i = 1; i <= a.length(); ++i)
    {
        for (size_t j = 1; j <= b.length(); ++j)
        {
            int cost = 0;
            if (a[i - 1] != b[j - 1])
            {
                cost = 1;
            }
            
            d[i][j] = std::min(std::min(d[i - 1][j] + 1, // delete
                                        d[i][j - 1] + 1), // insert
                                        d[i - 1][j - 1] + cost); // replace
        }
    }
    
    return d[a.length()][b.length()];
}