#include "DefaultNewWordIteratorCreator.h"

std::shared_ptr<WordIterator> DefaultNewWordIteratorCreator::Create()
{
    auto ptr = std::make_shared<DiscreteWordIterator>(engine, dict);
    ptr->AddWeight(50, [&] (const std::string &word)
    {
        return !user.WordEvaluator->IsKnown(word) && user.WordEvaluator->IsCommon(word);
    });
    
    ptr->AddWeight(20, [&] (const std::string &word)
    {
        return user.WordEvaluator->IsForgettable(word) && user.WordEvaluator->IsCommon(word);
    });
    
    ptr->AddWeight(20, [&] (const std::string &word)
    {
        return !user.WordEvaluator->IsCommon(word);
    });
    
    ptr->AddWeight(10, [&] (const std::string &word)
    {
        return user.WordEvaluator->IsKnown(word);
    });
    
    return ptr;
}
