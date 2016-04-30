#ifndef _DEFAULTEVALUATESTRATEGY_H_
#define _DEFAULTEVALUATESTRATEGY_H_

#include "EvaluateStrategy.h"
#include "Dictionary.h"
#include "WordInfo.h"
#include "UserInfo.h"

// 根据用户情况对单词难度评估
class DefaultEvaluateStrategy 
    : public EvaluateStrategy
{
protected:
    Dictionary &dict;
public:
    DefaultEvaluateStrategy(UserInfo &user, Dictionary &dict)
        : EvaluateStrategy(user), dict(dict)
    {
        
    }
    
    bool IsCommon(const std::string &word) override;
    bool IsForgettable(const std::string &word) override;
    bool IsKnown(const std::string &word) override;
};

#endif // _DEFAULTEVALUATESTRATEGY_H_
