#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include "types.h"
#include <memory>
#include <string>
#include <vector>
#include "IDictionary.h"
#include "DictStringUtils.h"

/// 词典实现，包含单词难度信息
class Dictionary
    : public IDictionary
{
private:
    /// 单词难度
    IDictDB &levelDB;

public:
	/// 构造
    Dictionary(IDictDB &dictDB, IDictDB &sentDB, IDictDB &levelDB)
        : IDictionary(dictDB, sentDB), levelDB(levelDB)
    {

    }

	/// 获取单词难度
    int GetLevel(const std::string &word);

	/// 避免词典信息修改
    void AddDesc(const std::string &word, const std::string &desc) override;
    void AddSentence(const std::string &word, const std::string &sent, const std::string &desc) override;
    void DelDesc(const std::string &word, size_t id) override;
    void DelSentence(const std::string &word, size_t id) override;
};

#endif // _DICTIONARY_H_
