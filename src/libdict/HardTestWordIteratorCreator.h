#ifndef _HARDTESTWORDITERATORCREATOR_H_
#define _HARDTESTWORDITERATORCREATOR_H_

#include "WordIterator.h"
#include "WordIteratorCreator.h"
#include "UserWordIteratorCreator.h"
#include "DiscreteWordIterator.h"
#include "EvaluateStrategy.h"
#include "UserInfo.h"
#include "IDictionary.h"
#include <random>
#include <memory>

/// 生成更具挑战性测试用单词迭代器
class HardTestWordIteratorCreator
    : public UserWordIteratorCreator
{
public:
    using UserWordIteratorCreator::UserWordIteratorCreator;

    std::shared_ptr<WordIterator> Create() override;
};

#endif // _HARDTESTWORDITERATORCREATOR_H_
