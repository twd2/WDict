#ifndef _FILEUTILS_H_
#define _FILEUTILS_H_

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

class FileUtils
{
public:
    static std::string ReadAllText(std::istream&);
    static bool Exists(const std::string&);
};

#endif // _FILEUTILS_H_