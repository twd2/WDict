#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include "types.h"
#include <memory>
#include <string>
#include <vector>
#include "IDictionary.h"
#include "StringUtils.h"

// 对基本词典接口扩展, 加入等级信息, 作为全局词典
class Dictionary
    : public IDictionary
{
private:
    //      等级
    IDictDB &levelDB;
    
public:
    Dictionary(IDictDB &dictDB, IDictDB &sentDB, IDictDB &levelDB)
        : IDictionary(dictDB, sentDB), levelDB(dictDB)
    {

    }

    int GetLevel(const std::string &word);
};

#endif // _DICTIONARY_H_
