#ifndef _WITHLIMITITERATOR_H_
#define _WITHLIMITITERATOR_H_

#include <memory>
#include "WordIterator.h"

class WithLimitIterator
    : public WordIterator
{
private:
    std::shared_ptr<WordIterator> iter;
public:
    size_t Counter, Limit;
    WithLimitIterator(size_t limit, std::shared_ptr<WordIterator> iter)
        : iter(iter), Counter(0), Limit(limit)
    {
        
    }
    
    std::string Next() override
    {
        if (Counter >= Limit)
        {
            return "";
        }
        
        ++Counter;
        return iter->Next();
    }
    
    bool HaveNext() override
    {
        return Counter < Limit && iter->HaveNext();
    }
};

#endif // _WITHLIMITITERATOR_H_
