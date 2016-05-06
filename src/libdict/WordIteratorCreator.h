#ifndef _WORDITERATORCREATOR_H_
#define _WORDITERATORCREATOR_H_

#include "WordIterator.h"
#include <memory>

class WordIteratorCreator
{
public:
    virtual std::shared_ptr<WordIterator> Create() = 0;
};

#endif // _WORDITERATORCREATOR_H_
