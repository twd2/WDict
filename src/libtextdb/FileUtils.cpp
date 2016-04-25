#include "FileUtils.h"

std::wstring FileUtils::ReadAllText(std::wistream& is)
{
    std::wstring line;
    std::wstringstream ss;
    
    while (std::getline(is, line))
    {
        ss << line << std::endl;
    }
    
    return ss.str();
}

bool FileUtils::Exists(const std::string &path)
{
    std::wifstream ifs(path, std::ios_base::in);
    
    bool succeeded = (bool)ifs;
    if (succeeded)
    {
        ifs.close();
    }
    
    return succeeded;
}