#ifndef _DEFAULTEVALUATESTRATEGY_H_
#define _DEFAULTEVALUATESTRATEGY_H_

#include "EvaluateStrategy.h"
#include "Dictionary.h"
#include "WordInfo.h"
#include "UserInfo.h"

// evaluate words by user's situation
class DefaultEvaluateStrategy 
    : public EvaluateStrategy
{
protected:
    UserInfo &user;
    Dictionary &dict;
public:
    DefaultEvaluateStrategy(UserInfo &user, Dictionary &dict)
        : user(user), dict(dict)
    {
        
    }
    
    bool IsCommon(const std::string &word) override;
    bool IsForgettable(const std::string &word) override;
    bool IsKnown(const std::string &word) override;
};

#endif // _DEFAULTEVALUATESTRATEGY_H_
