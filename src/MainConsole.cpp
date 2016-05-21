#include "MainConsole.h"

MainConsole::MainConsole(Console &Root)
    : ConsoleComponent(Root), btnRetrive(Root, '1', "单词查询"), btnText(Root, '2', "分析文本"), btnLearn(Root, '3', "学习"),
                              btnTestAsLearn(Root, '4', "以考代学"), btnTest(Root, '5', "测验"), 
                              btnAbout(Root, 'a', "关于"), btnHackMe(Root, 'h', "HackMe"), btnExit(Root, 'x', "退出")
{
#define ONCLICK(name) BUTTON_ONCLICK(MainConsole, name)
    ONCLICK(Retrive);
    ONCLICK(Text);
    ONCLICK(Learn);
    ONCLICK(TestAsLearn);
    ONCLICK(Test);
    ONCLICK(About);
    ONCLICK(HackMe);
    ONCLICK(Exit);
#undef ONCLICK
}

bool MainConsole::Show()
{
    WithTitleConsole(Root, "词典").Show();
    
    outs << Globals::CurrentUser->Name << ", 欢迎您!" << endl;
    outs << string(80, '-') << endl;
    
    outs << "欢迎使用词典, 您可以输入对应字符来进入相应功能:" << endl;
    
    ShowSubComponents();
    DoButtons();

    return true;
}

void MainConsole::Retrive()
{
    Root.Goto(make_shared<RetriveConsole>(Root));
}

void MainConsole::Text()
{
    Root.Goto(make_shared<TextConsole>(Root));
}

void MainConsole::Learn()
{
    Root.Goto(make_shared<LearnConsole>(Root, Globals::CurrentUser->Get("NewWordLimit", 20L)));
}

void MainConsole::TestAsLearn()
{
    Root.Goto(make_shared<TestConsole>(Root, *Globals::NewWordIteratorCreator, Globals::CurrentUser->Get("NewWordLimit", 20L), "以考代学"));
}

void MainConsole::Test()
{
    Root.Goto(make_shared<TestConsole>(Root, *Globals::TestWordIteratorCreator, Globals::CurrentUser->Get("TestWordLimit", 20L), "测验"));
}

void MainConsole::About()
{
    outs << "一个背单词程序。" << endl;
    ConfirmConsole cc(Root, "Fork me on GitHub?", true);
    cc.Show();
    if (cc.Value)
    {
        Globals::Open("https://github.com/twd2/WDict");
    }
}

void MainConsole::HackMe()
{
    string cmdarg;
    outs << ">";
    while (getline(ins, cmdarg))
    {
        if (cmdarg == "")
        {
            break;
        }
        
        string cmd = "", arg = "";
        
        size_t index = cmdarg.find(' ');
        if (index == string::npos)
        {
            cmd = cmdarg;
        }
        else
        {
            cmd = cmdarg.substr(0, index);
            arg = cmdarg.substr(index + 1);
        }
        
        if (cmd == "genhtml")
        {
            ofstream outf(arg, ios_base::out);
            HtmlQuestionBuilder html(outf);
            auto iter = make_shared<WithLimitIterator>(Globals::CurrentUser->Get("TestWordLimit", 20L), Globals::TestWordIteratorCreator->Create());
            QuestionGenerator gen(Globals::RandomEngine, *Globals::Dict, *iter, html);
            
            vector<string> answers;
            string answer;
            html.Begin();
            html.BeginTitle("清华大学本科生试题专用纸"); html.EndTitle();
            html.BeginBody();
            while (gen.GenerateOne(answer) != "")
            {
                answers.push_back(answer);
            }
            html.EndBody();
            html.End();
            for (auto &ans : answers)
            {
                outf << ans << " ";
            }
            outf << endl;
            outf.close();
        }
        else if (cmd == "exit")
        {
            return;
        }
        
        outs << ">";
    }
}

void MainConsole::Exit()
{
    ConfirmConsole cc(Root, "您确定要退出吗?", true);
    cc.Show();
    if (cc.Value)
    {
        Root.Goto(nullptr);
    }
}