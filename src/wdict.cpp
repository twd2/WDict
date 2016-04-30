#include "wdict.h"

int main()
{
#ifdef _WIN32
    system("chcp 65001");
#endif
    
    try
    {
        /*auto cons = make_shared<Console>();
        cons->Goto(make_shared<WithTitleConsole>("WDict", make_shared<MainConsole>(*cons)));
        UI::Init(cons);
        UI::Start();
        return 0;*/
        
        TextDB db("dictcn_level_1_.txt");
        
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
    catch (string err)
    {
        cerr << "Error: " << err << endl;
    }
    return 0;
}