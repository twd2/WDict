#ifndef _TEXTDB_H_
#define _TEXTDB_H_

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "FileUtils.h"
#include "StringUtils.h"
#include "Token.h"
#include "Lexer.h"

typedef std::map<std::string, std::vector<std::string> > TextDBCollection;

class TextDB : public TextDBCollection
{
private:
    std::string fileName;
public:
    TextDB(const std::string&);
    ~TextDB();
    void Sync();

private:
    void load();
};

#endif // _TEXTDB_H_