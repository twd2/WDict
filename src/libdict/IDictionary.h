#ifndef _IDICTIONARY_H_
#define _IDICTIONARY_H_

#include <string>
#include <vector>
#include <functional>
#include "types.h"
#include "DictStringUtils.h"
#include "WordInfo.h"

/// 字典接口
class IDictionary
{
protected:
    /// 词语，例句数据库，单词表
    IDictDB &dictDB, &sentDB;
    std::vector<std::string> words;
public:
    /// 构造，析构
    IDictionary(IDictDB &dictDB, IDictDB &sentDB);
    virtual ~IDictionary() = default;

    /// 单词量
    size_t Size()
    {
        return words.size();
    }

    /// 单词索引器
    std::string operator[](size_t index)
    {
        return words[index];
    }

    /// 获取相似单词
    std::vector<std::string> GetRelated(const std::string &word, size_t limit = 50)
    {
        return GetRelated(word, std::function<size_t (const std::string&, const std::string&)>([] (const std::string &input, const std::string &temp) {
            return DictStringUtils::Distance(input, temp);
        }), limit);
    }
    /// 按照相似度比较函数pred（返回值越小越相似）获取相似单词
    std::vector<std::string> GetRelated(const std::string &word, std::function<size_t (const std::string&, const std::string&)> pred, size_t limit = 50);

    /// 获取单词信息，增删解释与例句
    virtual WordInfo GetWord(const std::string &word);
    virtual void AddDesc(const std::string &word, const std::string &desc);
    virtual void AddSentence(const std::string &word, const std::string &sent, const std::string &desc);
    virtual void DelDesc(const std::string &word, size_t id);
    virtual void DelSentence(const std::string &word, size_t id);
private:
    /// 重置单词缓存
    void refreshWordsCache();
};

#endif // _IDICTIONARY_H_
