#include "Globals.h"

unique_ptr<TextDB> Globals::DictDB, Globals::SentDB, Globals::LevelDB,
                   Globals::UserInfoDB, Globals::UserCounterDB, Globals::UserDictDB, Globals::UserSentDB;
unique_ptr<Dictionary> Globals::Dict;
unique_ptr<UserInfo> Globals::CurrentUser;

void Globals::SwitchUser(const string &UserName)
{
    UserInfoDB = make_unique<TextDB>(UserName + "_info");
    UserCounterDB = make_unique<TextDB>(UserName + "_learn");
    UserDictDB = make_unique<TextDB>(UserName + "_dict");
    UserSentDB = make_unique<TextDB>(UserName + "_sentences");
    CurrentUser = make_unique<UserInfo>(*UserInfoDB, *UserCounterDB, *UserDictDB, *UserSentDB, UserName);
    CurrentUser->WordEvaluate = make_unique<DefaultEvaluateStrategy>(*CurrentUser, *Dict);
}

void Globals::Init()
{
    DictDB = make_unique<TextDB>("dict.txt");
    SentDB = make_unique<TextDB>("sentences.txt");
    LevelDB = make_unique<TextDB>("level.txt");
    Dict = make_unique<Dictionary>(*DictDB, *SentDB, *LevelDB);
    SwitchUser("default");
}