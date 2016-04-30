#include "Dictionary.h"

int Dictionary::GetLevel(const std::string &word)
{
    auto &vec = levelDB[word];
    if (vec.size() == 0 || vec[0] == "")
    {
        return -1;
    }
    else
    {
        return StringUtils::FromString<int>(vec[0]);
    }
}