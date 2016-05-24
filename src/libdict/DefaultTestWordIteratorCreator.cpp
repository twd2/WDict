#include "DefaultTestWordIteratorCreator.h"

std::shared_ptr<WordIterator> DefaultTestWordIteratorCreator::Create()
{
    auto ptr = std::make_shared<DiscreteWordIterator>(engine, dict);
    ptr->AddWeight(50, [&] (const std::string &word)
    {
        return user.WordEvaluator->IsLearned(word);
    });

    ptr->AddWeight(40, [&] (const std::string &word)
    {
        return user.WordEvaluator->IsLearned(word) && user.WordEvaluator->IsForgettable(word);
    });

    ptr->AddWeight(10, [&] (const std::string &word)
    {
        return !user.WordEvaluator->IsKnown(word);
    });

    return ptr;
}
