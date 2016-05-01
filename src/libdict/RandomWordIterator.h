#ifndef _RANDOMWORDITERATOR_H_
#define _RANDOMWORDITERATOR_H_

#include "IDictionary.h"
#include "WordIterator.h"
#include <ctime>
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
    std::function<bool (std::string)> pred;
    IDictionary &dict;
    std::random_device dev;
    std::unique_ptr<std::uniform_int_distribution<size_t> > dist;
public:
    RandomWordIterator(IDictionary &dict)
        : dict(dict)
    {
        initRandom();
        pred = [] (std::string w) { return true; };
    }
    
    RandomWordIterator(IDictionary &dict, std::function<bool (std::string)> pred)
        : pred(pred), dict(dict)
    {
        initRandom();
    }

    std::string Next() override;
    bool HaveNext() override
    {
        return true;
    }
    
private:
    void initRandom();
};

#endif // _RANDOMWORDITERATOR_H_
