#include "wdict.h"

int main()
{
#ifdef _WIN32
    system("chcp 65001");
#endif
    
    try
    {
        shared_ptr<Console> cons(new Console());
        cons->Goto(shared_ptr<ConsoleComponent>(new WithTitleConsole("WDict", shared_ptr<ConsoleComponent>(new MainConsole(*cons)))));
        UI::Init(cons);
        UI::Start();
        return 0;
        
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
    catch (string err)
    {
        cerr << "Error: " << err << endl;
    }
    return 0;
}