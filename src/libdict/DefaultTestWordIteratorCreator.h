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

class DefaultTestWordIteratorCreator
    : public UserWordIteratorCreator
{
public:
    DefaultTestWordIteratorCreator(std::default_random_engine &engine, UserInfo &user, IDictionary &dict)
        : UserWordIteratorCreator(engine, user, dict)
    {
        
    }
    
    std::shared_ptr<WordIterator> Create() override;
};

#endif // _DEFAULTTESTWORDITERATORCREATOR_H_
