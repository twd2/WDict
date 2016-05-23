#ifndef _WORDINFO_H_
#define _WORDINFO_H_

#include <string>
#include <vector>

/// 单词信息
class WordInfo
{
public:
	/// 词，释义，例句
    std::string Word;
    std::vector<std::string> Desc;
    std::vector<std::pair<std::string, std::string> > Sentences;
};

#endif // _WORDINFO_H_
