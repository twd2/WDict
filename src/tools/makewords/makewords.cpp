#include "makewords.h"

int main()
{
    try
    {
        TextDB db("dict.txt");
        wifstream ifs("../../../res/1w9.txt", ios_base::in);
        wstring s;
        while (getline(ifs, s))
        {
            wstringstream ss;
            size_t index = s.find(L'|');
            wstring word = s.substr(0, index);
            wstring desc = s.substr(index + 1);
            wcout << word << endl;
            auto &vec = db[word];
            for (size_t i = 0; i < desc.length(); ++i)
            {
                if (i > 0 && (desc[i] >= L'a' && desc[i] <= L'z') && !(desc[i - 1] >= L'a' && desc[i - 1] <= L'z'))
                {
                    if (ss.str() != L"")
                    {
                        vec.push_back(ss.str());
                    }
                    ss.str(L"");
                }
                ss << desc[i];
            }
            if (ss.str() != L"")
            {
                vec.push_back(ss.str());
            }
        }
    }
    catch (SyntaxError err)
    {
        wcerr << err.what << endl;
    }
    return 0;
}