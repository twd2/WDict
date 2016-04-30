#include "Globals.h"

unique_ptr<TextDB> Globals::DictDB, Globals::SentDB,
                   Globals::UserInfoDB, Globals::UserCounterDB, Globals::UserDictDB, Globals::UserSentDB;
unique_ptr<UserInfo> Globals::CurrentUser;

void Globals::SwitchUser(const string &UserName)
{
    UserInfoDB = make_unique<TextDB>(UserName + "_info");
    UserCounterDB = make_unique<TextDB>(UserName + "_counter");
    UserDictDB = make_unique<TextDB>(UserName + "_dict");
    UserSentDB = make_unique<TextDB>(UserName + "_sentances");
    CurrentUser = make_unique<UserInfo>(*UserInfoDB, *UserCounterDB, *UserDictDB, *UserSentDB, UserName);
}

void Globals::Init()
{
    DictDB = make_unique<TextDB>("dict.txt");
    SentDB = make_unique<TextDB>("sentances.txt");
    SwitchUser("default");
}