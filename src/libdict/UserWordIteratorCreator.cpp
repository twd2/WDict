#include "UserWordIteratorCreator.h"
#include "DefaultNewWordIteratorCreator.h"
#include "DefaultTestWordIteratorCreator.h"
#include "HardNewWordIteratorCreator.h"
#include "HardTestWordIteratorCreator.h"

std::shared_ptr<UserWordIteratorCreator> UserWordIteratorCreator::ByName(const std::string &name, std::default_random_engine &engine, UserInfo &user, IDictionary &dict)
{
    auto ptr = TryByName(name, engine, user, dict);
    if (ptr)
    {
        return ptr;
    }
    else
    {
        throw (std::string("UserWordIteratorCreator::ByName: Unsupported type name \"") + name + "\".");
    }
}

std::shared_ptr<UserWordIteratorCreator> UserWordIteratorCreator::TryByName(const std::string &name, std::default_random_engine &engine, UserInfo &user, IDictionary &dict)
{
    // TODO: more elegant
    if (name == "DefaultNew")
    {
        return std::make_shared<DefaultNewWordIteratorCreator>(engine, user, dict);
    }
    else if (name == "DefaultTest")
    {
        return std::make_shared<DefaultTestWordIteratorCreator>(engine, user, dict);
    }
    else if (name == "HardNew")
    {
        return std::make_shared<HardNewWordIteratorCreator>(engine, user, dict);
    }
    else if (name == "HardTest")
    {
        return std::make_shared<HardTestWordIteratorCreator>(engine, user, dict);
    }
    else
    {
        return nullptr;
    }
}
