#include "wdict.h"

int main(int argc, char **argv)
{
    try
    {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
        cout << string(9, '\n');
        cout << "                   __        __  ____    _          _                        \n"
                "                   \\ \\      / / |  _ \\  (_)   ___  | |_                      \n"
                "                    \\ \\ /\\ / /  | | | | | |  / __| | __|                     \n"
                "                     \\ V  V /   | |_| | | | | (__  | |_                      \n" 
                "                      \\_/\\_/    |____/  |_|  \\___|  \\__|                     \n" 
                "                                   Loading...                               " << endl;
        // cout << "                              广告位招租 QQ: ?????????                         " << endl; 
        // TODO: show ADs.
        
        // init globals
        Globals::Init();
        if (argc >= 2)
        {
            Globals::SwitchUser(argv[1]);
        }
        else
        {
            Globals::SwitchUser(DEFAULT_USERNAME);
        }
        
        // init user interface
        auto controller = make_shared<Console>(cin, cout); // create a controller
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
        cerr << "SyntaxError: " << err.what << endl;
        cerr << "可能是由于词库或配置错误。" << endl;
    }
    catch (string err)
    {
        cerr << "Error: " << err << endl;
        cerr << "可能是由于配置错误。" << endl;
    }
    return 1;
}