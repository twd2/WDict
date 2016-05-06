#ifndef _USERWORDITERATORCREATOR_H_
#define _USERWORDITERATORCREATOR_H_

#include "WordIterator.h"
#include "WordIteratorCreator.h"
#include "DiscreteWordIterator.h"
#include "EvaluateStrategy.h"
#include "UserInfo.h"
#include "IDictionary.h"
#include <random>
#include <memory>

class UserWordIteratorCreator
    : public WordIteratorCreator
{
protected:
    std::default_random_engine &engine;
    UserInfo &user;
    IDictionary &dict;
public:
    UserWordIteratorCreator(std::default_random_engine &engine, UserInfo &user, IDictionary &dict)
        : engine(engine), user(user), dict(dict)
    {
        
    }
    
    std::shared_ptr<WordIterator> Create() override = 0;
};

#endif // _USERWORDITERATORCREATOR_H_
