#include "wdict.h"

int main(int argc, char **argv)
{
#ifdef _WIN32
    system("chcp 65001");
#endif
    
    try
    {
        // init globals
        Globals::Init();
        if (argc >= 2)
        {
            Globals::SwitchUser(argv[1]);
        }
        
        // init user interface
        auto controller = make_shared<Console>();
        controller->Goto(make_shared<WithTitleConsole>("WDict", make_shared<MainConsole>(*controller)));
        UI::Init(controller);
        UI::Start(); // blocked
        return 0;
    }
    catch (SyntaxError err)
    {
        cerr << err.what << endl;
    }
    catch (string err)
    {
        cerr << "Error: " << err << endl;
    }
    return 1;
}