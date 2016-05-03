#include "wdict.h"

int main(int argc, char **argv)
{
    try
    {
        #ifdef DEBUG
        cout << "Loading databases..." << endl;
        // TODO: show ADs.
        #endif
        
        // init globals
        Globals::Init();
        if (argc >= 2)
        {
            Globals::SwitchUser(argv[1]);
        }
        
        // init user interface
        auto controller = make_shared<Console>(); // create a controller
        controller->Goto(make_shared<MainConsole>(*controller)); // goto MainConsole activity
        UI::Init(controller); // init UI
        UI::Start(); // ui loop, blocked
        
        #ifdef DEBUG
        cout << "Persistencing databases..." << endl;
        #endif
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