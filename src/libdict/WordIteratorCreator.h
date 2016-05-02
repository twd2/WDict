#ifndef _WORDITERATORCREATOR_H_
#define _WORDITERATORCREATOR_H_

#include "WordIterator.h"
#include <memory>

class WordIteratorCreator
{
public:
    virtual std::shared_ptr<WordIterator> CreateNewWordsIterator() = 0;
    virtual std::shared_ptr<WordIterator> CreateTestWordsIterator() = 0;
};

#endif // _WORDITERATORCREATOR_H_
