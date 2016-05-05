#ifndef _TEXTDB_H_
#define _TEXTDB_H_

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "FileUtils.h"
#include "StringUtils.h"
#include "Token.h"
#include "Lexer.h"

typedef std::map<std::string, std::vector<std::string> > ITextDB;

class TextDB
    : public ITextDB
{
private:
    std::string fileName;
public:
    bool ReadOnly;
    TextDB(const std::string &fileName, bool ReadOnly = false);
    ~TextDB();
    void Sync();

private:
    void load();
    
    // avoid copy or assign
    TextDB(const TextDB&) = delete;
    TextDB &operator=(const TextDB&) = delete;
};

#endif // _TEXTDB_H_