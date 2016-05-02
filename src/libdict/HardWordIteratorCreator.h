#ifndef _HARDWORDITERATORCREATOR_H_
#define _HARDWORDITERATORCREATOR_H_

#include "WordIterator.h"
#include "WordIteratorCreator.h"
#include "DefaultWordIteratorCreator.h"
#include "DiscreteWordIterator.h"
#include "EvaluateStrategy.h"
#include "UserInfo.h"
#include "IDictionary.h"
#include <random>
#include <memory>

class HardWordIteratorCreator
    : public DefaultWordIteratorCreator
{
public:
    std::shared_ptr<WordIterator> CreateNewWordsIterator() override;
    std::shared_ptr<WordIterator> CreateTestWordsIterator() override;
};

#endif // _HARDWORDITERATORCREATOR_H_
