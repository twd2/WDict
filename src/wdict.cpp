#include "wdict.h"

int main()
{
#ifdef _WIN32
    system("chcp 65001");
#endif
    try
    {
        TextDB db("dict.txt");
        
        string s;
        
        while (getline(cin, s))
        {
            cout << s.length() << endl;
            if (s == "") 
            {
                break;
            }
            for (auto &desc: db[s])
            {
                cout << "\t" << desc << endl;
            }
        }
    }
    catch (SyntaxError err)
    {
        cerr << err.what << endl;
    }
    return 0;
}