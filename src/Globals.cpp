#include "Globals.h"

default_random_engine Globals::RandomEngine;

shared_ptr<TextDB> Globals::DictDB, Globals::SentDB, Globals::LevelDB,
                   Globals::UserConfigDB, Globals::UserCounterDB, Globals::UserDictDB, Globals::UserSentDB;
shared_ptr<Dictionary> Globals::Dict;
shared_ptr<UserInfo> Globals::CurrentUser;
shared_ptr<WordIteratorCreator> Globals::NewWordIteratorCreator;
shared_ptr<WordIteratorCreator> Globals::TestWordIteratorCreator;

bool Globals::CheckName(const string &Name)
{
    for (const auto &ch : Name)
    {
        if (!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z') &&
            !(ch >= '0' && ch <= '9') && ch != '_')
        {
            return false;
        }
    }
    return true;
}

void Globals::SwitchUser(const string &UserName)
{
    if (!CheckName(UserName))
    {
        throw string("Bad user name.");
    }
    
    UserConfigDB = make_shared<TextDB>(UserName + "_config");
    UserCounterDB = make_shared<TextDB>(UserName + "_learn");
    UserDictDB = make_shared<TextDB>(UserName + "_dict");
    UserSentDB = make_shared<TextDB>(UserName + "_sentences");
    CurrentUser = make_shared<UserInfo>(UserName, *UserConfigDB, *UserCounterDB, *UserDictDB, *UserSentDB, UserName + "_history");

    DictDB = make_shared<TextDB>(CurrentUser->Get<string>("DictDB", "dict.txt"), true);
    SentDB = make_shared<TextDB>(CurrentUser->Get<string>("SentDB", "sentences.txt"), true);
    LevelDB = make_shared<TextDB>(CurrentUser->Get<string>("LevelDB", "level.txt"), true);
    Dict = make_shared<Dictionary>(*DictDB, *SentDB, *LevelDB);

    CurrentUser->WordEvaluator = make_shared<DefaultEvaluateStrategy>(*CurrentUser, *Dict);

    NewWordIteratorCreator = UserWordIteratorCreator::TryByName(CurrentUser->Get<string>("NewWordStrategy", "DefaultNew"),
                                                                RandomEngine, *CurrentUser, *Dict);
    if (!NewWordIteratorCreator)
    {
        NewWordIteratorCreator = UserWordIteratorCreator::ByName("DefaultNew", RandomEngine, *CurrentUser, *Dict);
        CurrentUser->Set<string>("NewWordStrategy", "DefaultNew"); 
    }

    TestWordIteratorCreator = UserWordIteratorCreator::TryByName(CurrentUser->Get<string>("TestWordStrategy", "DefaultTest"),
                                                                 RandomEngine, *CurrentUser, *Dict);
    if (!TestWordIteratorCreator)
    {
        TestWordIteratorCreator = UserWordIteratorCreator::ByName("DefaultTest", RandomEngine, *CurrentUser, *Dict);
        CurrentUser->Set<string>("TestWordStrategy", "DefaultTest"); 
    }
}

void Globals::Init()
{
    RandomEngine.seed(std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1));
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
