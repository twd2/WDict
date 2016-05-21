#ifndef _WORDITERATOR_H_
#define _WORDITERATOR_H_

#include <string>

class WordIterator
{
public:
    virtual ~WordIterator() = default;
    virtual std::string Next() = 0;
    virtual bool HasNext() = 0;
};

#endif // _WORDITERATOR_H_
