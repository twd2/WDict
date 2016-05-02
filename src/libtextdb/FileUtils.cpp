#include "FileUtils.h"

std::string FileUtils::ReadAllText(std::istream &is)
{
    std::string line;
    std::stringstream ss;
    
    while (std::getline(is, line))
    {
        ss << line << std::endl;
    }
    
    return ss.str();
}

bool FileUtils::Exists(const std::string &path)
{
    std::ifstream ifs(path, std::ios_base::in);
    
    bool succeeded = (bool)ifs;
    if (succeeded)
    {
        ifs.close();
    }
    
    return succeeded;
}