#ifndef _EVALUATESTRATEGY_H_
#define _EVALUATESTRATEGY_H_

#include "UserInfo.h"

// evaluate words by user's situation, basic interface
class EvaluateStrategy
{
public:
    virtual ~EvaluateStrategy() = default;
    virtual bool IsCommon(const std::string &word) = 0;
    virtual bool IsForgettable(const std::string &word) = 0;
    virtual bool IsKnown(const std::string &word) = 0;
    virtual bool IsLearned(const std::string &word) = 0;
};

#endif // _EVALUATESTRATEGY_H_
