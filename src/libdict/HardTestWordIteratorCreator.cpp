#include "HardTestWordIteratorCreator.h"

std::shared_ptr<WordIterator> HardTestWordIteratorCreator::Create()
{
    auto ptr = std::make_shared<DiscreteWordIterator>(engine, dict);
    ptr->AddWeight(30, [&] (const std::string &word)
    {
        return user.WordEvaluator->IsLearned(word);
    });
    
    ptr->AddWeight(40, [&] (const std::string &word)
    {
        return user.WordEvaluator->IsForgettable(word);
    });
    
    ptr->AddWeight(30, [&] (const std::string &word)
    {
        return !user.WordEvaluator->IsKnown(word);
    });
    
    return ptr;
}
