#include "TestConsole.h"

TestConsole::TestConsole(Console &Root, size_t Limit)
    : ConsoleComponent(Root), btnBack(Root, 'b', "返回"), Limit(Limit)
{
    btnBack.OnClick = bind(&TestConsole::Back, this);
    Add(btnBack);
    
    initIter();
}

void TestConsole::initIter()
{
    iter = make_shared<WithLimitIterator>(Limit, Globals::IterCreator->CreateTestWordsIterator());
    word = iter->Next();
}

bool TestConsole::Show()
{
    if (word != "")
    {
        answer_t pass = CheckAnswer(word);
        if (pass == ANSWER_BACK)
        {
            Back();
            return true;
        }
        
        Globals::CurrentUser->IncCounter(word, COUNTER_TEST);
        if (pass == ANSWER_CORRECT)
        {
            Globals::CurrentUser->IncCounter(word, COUNTER_PASS);
        }
        Globals::UserCounterDB->Sync();
        
        word = iter->Next();
    }
    else
    {
        cout << "本次测试完成!" << endl;
        ConfirmConsole cc(Root, "再来一轮?", false);
        cc.Show();
        if (cc.Value)
        {
            initIter();
        }
        else
        {
            Back();
        }
    }
    return true;
}

void TestConsole::Back()
{
    Root.Back();
}

answer_t TestConsole::CheckAnswer(const std::string &word)
{
    cout << "请选择" << word << "的解释:" << endl;
    SelectConsole sc(Root, "请作答:");
    sc.IgnoreCase = true;
    sc.Add('E', "不会");
    sc.Add('Q', "停止考试");
    sc.Show();
    
    if (sc.Selected('E'))
    {
        return ANSWER_WRONG;
    }
    
    if (sc.Selected('Q'))
    {
        return ANSWER_BACK;
    }
}