#include "TextDB.h"


TextDB::TextDB(const std::string &fileName)
    : fileName(fileName)
{
    load();
}

void TextDB::load()
{
    std::wifstream ifs(fileName, std::ios_base::in);
    std::wstring txt = FileUtils::ReadAllText(ifs);
    Lexer lex(txt);
    auto tokens = lex.Do();
    
    std::vector<std::wstring> vecbuff;
    std::wstring strbuff;
    for (Token token : tokens)
    {
        if (token.Type == TOKENTYPE_VALUE)
        {
            strbuff += StringUtils::Unescape(token.Value);
        }
        else if (token.Type == TOKENTYPE_SEPARATOR)
        {
            vecbuff.push_back(strbuff);
            strbuff = L"";
        }
        else if (token.Type == TOKENTYPE_NEWLINE)
        {
            if (strbuff != L"")
            {
                vecbuff.push_back(strbuff);
                strbuff = L"";
            }
            
            if (vecbuff.size() > 0)
            {
                std::vector<std::wstring> &val = this->operator[](vecbuff[0]);
                val.insert(val.begin(), vecbuff.begin() + 1, vecbuff.end());
                vecbuff.clear();
            }
        }
    }
    
    if (strbuff != L"")
    {
        vecbuff.push_back(strbuff);
        strbuff = L"";
    }
    
    if (vecbuff.size() > 0)
    {
        std::vector<std::wstring> &val = this->operator[](vecbuff[0]);
        val.insert(val.begin(), vecbuff.begin() + 1, vecbuff.end());
        vecbuff.clear();
    }
    ifs.close();
}

void TextDB::Sync()
{
    std::wofstream ofs(fileName, std::ios_base::out);
    for (TextDBCollection::iterator iter = begin(); iter != end(); ++iter)
    {
        ofs << StringUtils::Escape(iter->first);
        std::vector<std::wstring> &val = iter->second;
        if (val.size() > 0)
        {
            ofs << L", ";
            for (std::vector<std::wstring>::iterator valiter = val.begin(); valiter != val.end(); ++valiter)
            {
                ofs << StringUtils::Escape(*valiter);
                if (valiter != val.end() - 1)
                {
                    ofs << L", ";
                }
            }
        }
        ofs << std::endl;
    }
    ofs.close();
}

TextDB::~TextDB()
{
    Sync();
}