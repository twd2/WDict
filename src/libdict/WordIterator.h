#ifndef _WORDITERATOR_H_
#define _WORDITERATOR_H_

#include <string>

class WordIterator
{
public:
    virtual std::string Next() = 0;
    virtual bool HaveNext() = 0;
};

#endif // _WORDITERATOR_H_
