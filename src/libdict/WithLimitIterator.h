#ifndef _WITHLIMITITERATOR_H_
#define _WITHLIMITITERATOR_H_

#include <memory>
#include "WordIterator.h"

/// 限制迭代器产生词的个数
class WithLimitIterator
    : public WordIterator
{
private:
    /// 原始迭代器
    std::shared_ptr<WordIterator> iter;
public:
    /// 已产生个数与总个数限制
    size_t Counter, Limit;
    /// 构造
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

    bool HasNext() override
    {
        return Counter < Limit && iter->HasNext();
    }
};

#endif // _WITHLIMITITERATOR_H_
