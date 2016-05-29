#ifndef _USERWORDITERATORCREATOR_H_
#define _USERWORDITERATORCREATOR_H_

#include "WordIterator.h"
#include "WordIteratorCreator.h"
#include "DiscreteWordIterator.h"
#include "EvaluateStrategy.h"
#include "UserInfo.h"
#include "IDictionary.h"
#include <random>
#include <memory>

// 使用用户数据创建迭代器
class UserWordIteratorCreator
    : public WordIteratorCreator
{
protected:
    /// 随机数生成器，用户，词典
    std::default_random_engine &engine;
    UserInfo &user;
    IDictionary &dict;
public:
    /// 构造
    UserWordIteratorCreator(std::default_random_engine &engine, UserInfo &user, IDictionary &dict)
        : engine(engine), user(user), dict(dict)
    {

    }

    /// 迭代器创建接口
    std::shared_ptr<WordIterator> Create() override = 0;

    /// 按名称创建Creator
    static std::shared_ptr<UserWordIteratorCreator> ByName(const std::string &name, std::default_random_engine &engine, UserInfo &user, IDictionary &dict);
    /// 尝试按名称创建Creator
    static std::shared_ptr<UserWordIteratorCreator> TryByName(const std::string &name, std::default_random_engine &engine, UserInfo &user, IDictionary &dict);
};

#endif // _USERWORDITERATORCREATOR_H_
