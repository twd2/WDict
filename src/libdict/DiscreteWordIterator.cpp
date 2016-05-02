#include "DiscreteWordIterator.h"

void DiscreteWordIterator::AddWeight(size_t weight, std::function<bool (std::string)> pred)
{
    weights.push_back(weight);
    preds.push_back(pred);
    dist = nullptr;
}

void DiscreteWordIterator::DelWeight(size_t index)
{
    if (index < weights.size())
    {
        weights.erase(weights.begin() + index);
        preds.erase(preds.begin() + index);
        dist = nullptr;
    }
}

std::string DiscreteWordIterator::Next()
{
    if (!HaveNext())
    {
        return "";
    }
    
    initRandom();
    std::string word;
    do
    {
        word = iters[(*dist)(engine)]->Next();
    }
    while (word == "");
    
    return word;
}

bool DiscreteWordIterator::HaveNext()
{
    bool found = false;
    
    initRandom();
    for (auto &iter : iters)
    {
        if (iter->HaveNext())
        {
            found = true;
            break;
        }
    }

    return found;
}

void DiscreteWordIterator::initRandom()
{
    if (!dist)
    {
        dist = std::unique_ptr<std::discrete_distribution<size_t> >(new std::discrete_distribution<size_t>(weights.begin(), weights.end()));
        iters.clear();
        for (size_t i = 0; i < weights.size(); ++i)
        {
            iters.push_back(std::unique_ptr<RandomWordIterator>(new RandomWordIterator(engine, dict, preds[i])));
        }
    }
}