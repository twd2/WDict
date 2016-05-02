#include "Globals.h"

default_random_engine Globals::RandomEngine;

unique_ptr<TextDB> Globals::DictDB, Globals::SentDB, Globals::LevelDB,
                   Globals::UserInfoDB, Globals::UserCounterDB, Globals::UserDictDB, Globals::UserSentDB;
unique_ptr<Dictionary> Globals::Dict;
unique_ptr<UserInfo> Globals::CurrentUser;
unique_ptr<WordIteratorCreator> Globals::IterCreator;

void Globals::SwitchUser(const string &UserName)
{
    UserInfoDB = make_unique<TextDB>(UserName + "_info");
    UserCounterDB = make_unique<TextDB>(UserName + "_learn");
    UserDictDB = make_unique<TextDB>(UserName + "_dict");
    UserSentDB = make_unique<TextDB>(UserName + "_sentences");
    
    CurrentUser = make_unique<UserInfo>(*UserInfoDB, *UserCounterDB, *UserDictDB, *UserSentDB, UserName);
    
    CurrentUser->WordEvaluate = make_unique<DefaultEvaluateStrategy>(*CurrentUser, *Dict);
    
    IterCreator = make_unique<DefaultWordIteratorCreator>(RandomEngine, *CurrentUser, *Dict);
}

void Globals::Init()
{
    RandomEngine.seed(std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1));
    
    DictDB = make_unique<TextDB>("dict.txt");
    SentDB = make_unique<TextDB>("sentences.txt");
    LevelDB = make_unique<TextDB>("level.txt");
    
    Dict = make_unique<Dictionary>(*DictDB, *SentDB, *LevelDB);
    
    SwitchUser(DEFAULT_USERNAME);
}

void Globals::Open(const string &path)
{
    #ifdef _WIN32
    system((string("explorer \"") + path + "\"").c_str());
    #endif

    #ifdef __linux
    system((string("gnome-open \"") + path + "\"").c_str());
    #endif

    #if defined(__APPLE__) && defined(__MACH__)
    system((string("open \"") + path + "\"").c_str());
    #endif
}