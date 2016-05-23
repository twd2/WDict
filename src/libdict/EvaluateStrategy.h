#ifndef _EVALUATESTRATEGY_H_
#define _EVALUATESTRATEGY_H_

#include "UserInfo.h"

/// 单词难度评估接口
class EvaluateStrategy
{
public:
	/// 析构
    virtual ~EvaluateStrategy() = default;
	/// 是否常见、易忘、已知、学会
    virtual bool IsCommon(const std::string &word) = 0;
    virtual bool IsForgettable(const std::string &word) = 0;
    virtual bool IsKnown(const std::string &word) = 0;
    virtual bool IsLearned(const std::string &word) = 0;
};

#endif // _EVALUATESTRATEGY_H_
