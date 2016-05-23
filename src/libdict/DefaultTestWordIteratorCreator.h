#ifndef _DEFAULTTESTWORDITERATORCREATOR_H_
#define _DEFAULTTESTWORDITERATORCREATOR_H_

#include "WordIterator.h"
#include "WordIteratorCreator.h"
#include "UserWordIteratorCreator.h"
#include "DiscreteWordIterator.h"
#include "EvaluateStrategy.h"
#include "UserInfo.h"
#include "IDictionary.h"
#include <random>
#include <memory>

/// 生成测试用单词迭代器
class DefaultTestWordIteratorCreator
    : public UserWordIteratorCreator
{
public:
    using UserWordIteratorCreator::UserWordIteratorCreator;

    std::shared_ptr<WordIterator> Create() override;
};

#endif // _DEFAULTTESTWORDITERATORCREATOR_H_
