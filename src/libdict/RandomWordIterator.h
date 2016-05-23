#ifndef _RANDOMWORDITERATOR_H_
#define _RANDOMWORDITERATOR_H_

#include "IDictionary.h"
#include "WordIterator.h"
#include <memory>
#include <string>
#include <random>
#include <functional>

/// 随机抽取符合条件的单词
class RandomWordIterator
    : public WordIterator
{
private:
	/// 词典大小缓存
    size_t lastSize = -1;
protected:
	/// 单词条件，随机数生成器，词典，随机数区间
    std::function<bool (const std::string&)> pred;
    std::default_random_engine &engine;
    IDictionary &dict;
    std::unique_ptr<std::uniform_int_distribution<size_t> > dist;
public:
	/// 构造
    RandomWordIterator(std::default_random_engine &engine, IDictionary &dict)
        : engine(engine), dict(dict)
    {
        initRandom();
        pred = [] (std::string w) { return true; };
    }

    RandomWordIterator(std::default_random_engine &engine, IDictionary &dict, std::function<bool (const std::string&)> pred)
        : pred(pred), engine(engine), dict(dict)
    {
        initRandom();
    }

    std::string Next() override;
    bool HasNext() override;

private:
	/// 初始化随机数生成器
    void initRandom();
};

#endif // _RANDOMWORDITERATOR_H_
