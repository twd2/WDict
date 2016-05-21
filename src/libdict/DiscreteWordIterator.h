#ifndef _DISCRETEWORDITERATOR_H_
#define _DISCRETEWORDITERATOR_H_

#include "IDictionary.h"
#include "WordIterator.h"
#include "RandomWordIterator.h"
#include <memory>
#include <string>
#include <random>
#include <functional>

// randomly pick a word that satisfies a pred which is randomly chosen
class DiscreteWordIterator
    : public WordIterator
{
protected:
    std::vector<size_t> weights;
    std::vector<std::function<bool (const std::string&)> > preds;
    std::default_random_engine &engine;
    IDictionary &dict;
    std::unique_ptr<std::discrete_distribution<size_t> > dist = nullptr;
private:
    std::vector<std::unique_ptr<RandomWordIterator> > iters;
public:
    DiscreteWordIterator(std::default_random_engine &engine, IDictionary &dict)
        : engine(engine), dict(dict)
    {
        
    }
    
    void AddWeight(size_t weight, std::function<bool (const std::string&)> pred);
    void DelWeight(size_t index);
    std::string Next() override;
    bool HasNext() override;
    
private:
    void initRandom();
};

#endif // _DISCRETEWORDITERATOR_H_
