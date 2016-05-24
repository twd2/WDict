#ifndef _FILEUTILS_H_
#define _FILEUTILS_H_

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

/// 文件处理工具
class FileUtils
{
public:
    /// 读取文件的全部内容
    static std::string ReadAllText(std::istream &is);
    /// 检测文件是否存在
    static bool Exists(const std::string &path);
};

#endif // _FILEUTILS_H_
