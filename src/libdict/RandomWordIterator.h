#ifndef _RANDOMWORDITERATOR_H_
#define _RANDOMWORDITERATOR_H_

#include "IDictionary.h"
#include "WordIterator.h"
#include <memory>
#include <string>
#include <random>
#include <functional>

class RandomWordIterator
    : public WordIterator
{
private:
    size_t lastSize = -1;
protected:
    std::function<bool (const std::string&)> pred;
    std::default_random_engine &engine;
    IDictionary &dict;
    std::unique_ptr<std::uniform_int_distribution<size_t> > dist;
public:
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
    void initRandom();
};

#endif // _RANDOMWORDITERATOR_H_
