#ifndef _DISCRETEWORDITERATOR_H_
#define _DISCRETEWORDITERATOR_H_

#include "IDictionary.h"
#include "WordIterator.h"
#include "RandomWordIterator.h"
#include <memory>
#include <string>
#include <random>
#include <functional>

/// 随机抽取单词，根据多个条件
class DiscreteWordIterator
    : public WordIterator
{
protected:
	/// 条件权重，条件，随机数生成器，字典，随机区间
    std::vector<size_t> weights;
    std::vector<std::function<bool (const std::string&)> > preds;
    std::default_random_engine &engine;
    IDictionary &dict;
    std::unique_ptr<std::discrete_distribution<size_t> > dist = nullptr;
private:
	/// 各条件对应的RandomWordIterator
    std::vector<std::unique_ptr<RandomWordIterator> > iters;
public:
	/// 构造
    DiscreteWordIterator(std::default_random_engine &engine, IDictionary &dict)
        : engine(engine), dict(dict)
    {

    }

	/// 为各条件设定权重
    void AddWeight(size_t weight, std::function<bool (const std::string&)> pred);
    void DelWeight(size_t index);

    std::string Next() override;
    bool HasNext() override;

private:
	/// 初始化随机数生成器
    void initRandom();
};

#endif // _DISCRETEWORDITERATOR_H_
