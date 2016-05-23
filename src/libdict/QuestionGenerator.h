#ifndef _QUESTIONGENERATOR_H_
#define _QUESTIONGENERATOR_H_

#include <memory>
#include <random>
#include <vector>
#include <functional>

#include "WordInfo.h"
#include "WordIterator.h"
#include "RandomWordIterator.h"
#include "IDictionary.h"
#include "IQuestionBuilder.h"

/// 问题生成器
class QuestionGenerator
{
protected:
	/// 错误答案生成器，随机数引擎，词典，正确答案生成器，试卷字符串生成器
    std::shared_ptr<WordIterator> wrongAnswerIter;
    std::default_random_engine &engine;
    IDictionary &dict;
    WordIterator &iter;
    IQuestionBuilder &qb;
private:
	/// 问题生成器，随机数区间
    std::vector<std::function<std::string (const std::string&)> > handlers;
    std::discrete_distribution<size_t> dd;

public:
	/// 构造
    QuestionGenerator(std::default_random_engine &engine, IDictionary &dict, WordIterator &iter, IQuestionBuilder &qb);

	/// 生成卷首，卷尾与中间部分
    void Begin();
    std::string GenerateOne(std::string &out_answer);
    void End();

protected:
	/// 生成判断，选择释义，选择单词，输入单词的问题
    std::string genTF(const std::string &word);
    std::string genSelDesc(const std::string &word);
    std::string genSelWord(const std::string &word);
    std::string genInputWord(const std::string &word);
};

#endif // _QUESTIONGENERATOR_H_
