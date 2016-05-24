#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <libtextdb.h>
#include <libdict.h>
#include <random>
#include <chrono>
#include <memory>

using namespace std;

#define DEFAULT_USERNAME "user"

/// 全局环境
class Globals
{
public:
    /// 随机数生成器
    static default_random_engine RandomEngine;
    ///词典，例句，难度，用户信息（设置，计数器，字典，例句）数据库
    static shared_ptr<TextDB> DictDB, SentDB, LevelDB,
                              UserConfigDB, UserCounterDB, UserDictDB, UserSentDB;
    /// 字典
    static shared_ptr<Dictionary> Dict;
    /// 当前用户
    static shared_ptr<UserInfo> CurrentUser;
    /// 新学与测试单词生成器
    static shared_ptr<WordIteratorCreator> NewWordIteratorCreator;
    static shared_ptr<WordIteratorCreator> TestWordIteratorCreator;

    /// 改变用户，初始化，在文件管理器打开
    static void SwitchUser(const string &UserName);
    static void Init();
    static void Open(const string &path);
};

/// unique_ptr生成器
template <typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args)
{
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif // _GLOBALS_H_
