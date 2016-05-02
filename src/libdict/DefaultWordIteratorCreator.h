#ifndef _DEFAULTWORDITERATORCREATOR_H_
#define _DEFAULTWORDITERATORCREATOR_H_

#include "WordIterator.h"
#include "WordIteratorCreator.h"
#include "DiscreteWordIterator.h"
#include "EvaluateStrategy.h"
#include "UserInfo.h"
#include "IDictionary.h"
#include <random>
#include <memory>

class DefaultWordIteratorCreator
    : public WordIteratorCreator
{
protected:
    std::default_random_engine &engine;
    UserInfo &user;
    IDictionary &dict;
public:
    DefaultWordIteratorCreator(std::default_random_engine &engine, UserInfo &user, IDictionary &dict)
        : engine(engine), user(user), dict(dict)
    {
        
    }
    
    std::shared_ptr<WordIterator> CreateNewWordsIterator() override;
    std::shared_ptr<WordIterator> CreateTestWordsIterator() override;
};

#endif // _DEFAULTWORDITERATORCREATOR_H_
