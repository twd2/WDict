#include "HardNewWordIteratorCreator.h"

std::shared_ptr<WordIterator> HardNewWordIteratorCreator::Create()
{
    auto ptr = std::make_shared<DiscreteWordIterator>(engine, dict);
    ptr->AddWeight(50, [&] (const std::string &word)
    {
        return !user.WordEvaluator->IsKnown(word);
    });

    ptr->AddWeight(20, [&] (const std::string &word)
    {
        return user.WordEvaluator->IsForgettable(word);
    });

    ptr->AddWeight(25, [&] (const std::string &word)
    {
        return !user.WordEvaluator->IsCommon(word);
    });

    ptr->AddWeight(5, [&] (const std::string &word)
    {
        return user.WordEvaluator->IsKnown(word);
    });

    return ptr;
}
