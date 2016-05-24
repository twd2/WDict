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

/// 被代理的map<string,vector<string> >类
typedef std::map<std::string, std::vector<std::string> > ITextDB;

/// 文本数据库
class TextDB
    : public ITextDB
{
private:
    /// 对应的文件
    std::string fileName;
public:
    /// 是否只读
    bool ReadOnly;
    /// 从文件名构造
    TextDB(const std::string &fileName, bool ReadOnly = false);
    ~TextDB();

    /// 将数据输出至原文件（当非只读时）
    void Sync();

private:
    /// 从文件名加载
    void load();

    /// 避免拷贝
    TextDB(const TextDB&) = delete;
    TextDB &operator=(const TextDB&) = delete;
};

#endif // _TEXTDB_H_
