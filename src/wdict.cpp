#include "wdict.h"

int main()
{
#ifdef _WIN32
    system("chcp 65001");
#endif
    
    cout << "setlocale " << setlocale(LC_ALL, "") << endl;
    
    try
    {
        TextDB db("dict.txt");
        
        wstring s;
        
        wcout << L"您好" << endl;
        
        while (getline(wcin, s))
        {
            wcout << s << endl;
            wcout << s.length() << L" " << sizeof(wchar_t) << endl;
            if (s == L"") 
            {
                break;
            }
            if (db[s].size() > 0)
            {
                for (auto &desc: db[s])
                {
                    wcout << L"\t" << desc << endl;
                }
            }
            else
            {
                wcout << L"No description found." << endl;
            }
        }
    }
    catch (SyntaxError err)
    {
        wcerr << err.what << endl;
    }
    return 0;
}