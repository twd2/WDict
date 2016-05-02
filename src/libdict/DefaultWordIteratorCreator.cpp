#include "DefaultWordIteratorCreator.h"

std::shared_ptr<WordIterator> DefaultWordIteratorCreator::CreateNewWordsIterator()
{
    auto ptr = std::make_shared<DiscreteWordIterator>(engine, dict);
    ptr->AddWeight(50, [&] (std::string word)
    {
        return !user.WordEvaluate->IsKnown(word) && user.WordEvaluate->IsCommon(word);
    });
    
    ptr->AddWeight(20, [&] (std::string word)
    {
        return user.WordEvaluate->IsForgettable(word) && user.WordEvaluate->IsCommon(word);
    });
    
    ptr->AddWeight(20, [&] (std::string word)
    {
        return !user.WordEvaluate->IsCommon(word);
    });
    
    ptr->AddWeight(10, [&] (std::string word)
    {
        return user.WordEvaluate->IsKnown(word);
    });
    
    return ptr;
}

std::shared_ptr<WordIterator> DefaultWordIteratorCreator::CreateTestWordsIterator()
{
    auto ptr = std::make_shared<DiscreteWordIterator>(engine, dict);
    ptr->AddWeight(50, [&] (std::string word)
    {
        return user.WordEvaluate->IsKnown(word);
    });
    
    ptr->AddWeight(40, [&] (std::string word)
    {
        return user.WordEvaluate->IsKnown(word) && user.WordEvaluate->IsForgettable(word);
    });
    
    ptr->AddWeight(10, [&] (std::string word)
    {
        return !user.WordEvaluate->IsKnown(word);
    });
    
    return ptr;
}