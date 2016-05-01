#ifndef _EVALUATESTRATEGY_H_
#define _EVALUATESTRATEGY_H_

#include "UserInfo.h"

// 根据用户情况对单词进行难度评估
class EvaluateStrategy
{
protected:
    UserInfo &user;
public:
    EvaluateStrategy(UserInfo &user)
        : user(user)
    {
        
    }
    
    virtual bool IsCommon(const std::string &word) = 0; // 是常见词
    virtual bool IsForgettable(const std::string &word) = 0; // 是易忘词
    virtual bool IsKnown(const std::string &word) = 0; // 是熟词
};

#endif // _EVALUATESTRATEGY_H_
