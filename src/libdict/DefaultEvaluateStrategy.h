#ifndef _DEFAULTEVALUATESTRATEGY_H_
#define _DEFAULTEVALUATESTRATEGY_H_

#include "EvaluateStrategy.h"
#include "Dictionary.h"
#include "WordInfo.h"
#include "UserInfo.h"

/// 默认评估函数
class DefaultEvaluateStrategy
    : public EvaluateStrategy
{
protected:
    /// 关联用户与词典
    UserInfo &user;
    Dictionary &dict;
public:
    /// 构造
    DefaultEvaluateStrategy(UserInfo &user, Dictionary &dict)
        : user(user), dict(dict)
    {

    }

    bool IsCommon(const std::string &word) override;
    bool IsForgettable(const std::string &word) override;
    bool IsKnown(const std::string &word) override;
    bool IsLearned(const std::string &word) override;
};

#endif // _DEFAULTEVALUATESTRATEGY_H_
