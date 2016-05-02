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
    wrongAnswerIter = make_shared<RandomWordIterator>(Globals::RandomEngine, *Globals::Dict, [this] (const string &w)
    {
        return w != this->word;
    });
}

bool TestConsole::Show()
{
    if (word != "")
    {
        answer_t ans = CheckAnswer(word);
        if (ans == ANSWER_BACK)
        {
            Back();
            return true;
        }
        
        Globals::CurrentUser->IncCounter(word, COUNTER_TEST);
        if (ans == ANSWER_CORRECT)
        {
            Globals::CurrentUser->IncCounter(word, COUNTER_PASS);
        }
        Globals::UserCounterDB->Sync();
        
        if (ans == ANSWER_WRONG)
        {
            cout << "回答错误 :(" << endl;
            ConfirmConsole cc(Root, "查看单词解释?", true);
            cc.Show();
            if (cc.Value)
            {
                Globals::CurrentUser->IncCounter(word, COUNTER_LEARN);
                Globals::UserCounterDB->Sync();
                Root.Goto(make_shared<WithTitleConsole>(word, make_shared<WordConsole>(Root, word)));
            }
        }
        
        word = iter->Next();
        wrongAnswerIter = make_shared<RandomWordIterator>(Globals::RandomEngine, *Globals::Dict, [this] (const string &w)
        {
            return w != this->word;
        });
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

answer_t TestConsole::CheckAnswer(const string &word)
{
    vector<function<answer_t (const string&)> > handlers {
        bind(&TestConsole::CheckAnswerTF, this, placeholders::_1),
        bind(&TestConsole::CheckAnswerSelDesc, this, placeholders::_1),
        bind(&TestConsole::CheckAnswerSelWord, this, placeholders::_1)
    };
    
    discrete_distribution<size_t> dd {0, 1, 0};
    
    return handlers[dd(Globals::RandomEngine)](word);
}

answer_t TestConsole::CheckAnswerTF(const string &word)
{
    uniform_int_distribution<size_t> answerDist(0, 1);
    bool correctAnswer = answerDist(Globals::RandomEngine);
    
    cout << "请判断:" << endl;
    if (correctAnswer)
    {
        WordInfo wi = Globals::Dict->GetWord(word);
        uniform_int_distribution<size_t> dist(0, wi.Desc.size() - 1);
        cout << word << ": "<< wi.Desc[dist(Globals::RandomEngine)] << endl;
    }
    else
    {
        WordInfo wi = Globals::Dict->GetWord(wrongAnswerIter->Next());
        uniform_int_distribution<size_t> dist(0, wi.Desc.size() - 1);
        cout << word << ": "<< wi.Desc[dist(Globals::RandomEngine)] << endl;
    }
    SelectConsole sc(Root, "请作答:");
    sc.IgnoreCase = true;
    sc.Add('T', "正确");
    sc.Add('F', "错误");
    sc.Add('E', "不会");
    sc.Add('Q', "停止测验");
    sc.Show();
    
    if ((sc.Selected('T') && sc.Selected('F')) || sc.Selected('E'))
    {
        return ANSWER_WRONG;
    }
    
    if (sc.Selected('Q'))
    {
        return ANSWER_BACK;
    }
    
    if ((sc.Selected('T') && correctAnswer) || (sc.Selected('F') && !correctAnswer))
    {
        return ANSWER_CORRECT;
    }
    
    return ANSWER_WRONG;
}

answer_t TestConsole::CheckAnswerSelDesc(const string &word)
{
    const size_t count = 4;
    
    uniform_int_distribution<size_t> answerDist(0, count - 1);
    size_t correctAnswer = answerDist(Globals::RandomEngine);
    
    WordInfo wi = Globals::Dict->GetWord(word);
    uniform_int_distribution<size_t> dist(0, wi.Desc.size() - 1);
    string desc = wi.Desc[dist(Globals::RandomEngine)];
    
    cout << word << "有哪个意思?" << endl;
    
    cout << correctAnswer << endl;
    
    SelectConsole sc(Root, "请作答:");
    sc.IgnoreCase = true;

    for (size_t i = 0; i < count; ++i)
    {
        if (i == correctAnswer)
        {
            sc.Add('A' + i, desc);
        }
        else
        {
            WordInfo wwi = Globals::Dict->GetWord(wrongAnswerIter->Next());
            uniform_int_distribution<size_t> dist(0, wwi.Desc.size() - 1);
            sc.Add('A' + i, wwi.Desc[dist(Globals::RandomEngine)]);
        }
    }
    
    sc.Add('E', "不会");
    sc.Add('Q', "停止测验");
    sc.Show();
    
    if (sc.SelectedIndexes.size() == 0 || sc.Selected('E'))
    {
        return ANSWER_WRONG;
    }
    
    if (sc.Selected('Q'))
    {
        return ANSWER_BACK;
    }
    
    if (sc.SelectedIndexes.size() == 1 && sc.SelectedIndexes[0] == correctAnswer)
    {
        return ANSWER_CORRECT;
    }
    
    return ANSWER_WRONG;
}

answer_t TestConsole::CheckAnswerSelWord(const string &word)
{
    const size_t count = 4;
    
    uniform_int_distribution<size_t> answerDist(0, count - 1);
    size_t correctAnswer = answerDist(Globals::RandomEngine);
    
    WordInfo wi = Globals::Dict->GetWord(word);
    uniform_int_distribution<size_t> dist(0, wi.Desc.size() - 1);
    
    cout << "哪一个单词有\"" << wi.Desc[dist(Globals::RandomEngine)] << "\"的意思?" << endl;
    
    cout << correctAnswer << endl;
    
    SelectConsole sc(Root, "请作答:");
    sc.IgnoreCase = true;

    for (size_t i = 0; i < count; ++i)
    {
        if (i == correctAnswer)
        {
            sc.Add('A' + i, word);
        }
        else
        {
            sc.Add('A' + i, wrongAnswerIter->Next());
        }
    }
    
    sc.Add('E', "不会");
    sc.Add('Q', "停止测验");
    sc.Show();
    
    if (sc.SelectedIndexes.size() == 0 || sc.Selected('E'))
    {
        return ANSWER_WRONG;
    }
    
    if (sc.Selected('Q'))
    {
        return ANSWER_BACK;
    }
    
    if (sc.SelectedIndexes.size() == 1 && sc.SelectedIndexes[0] == correctAnswer)
    {
        return ANSWER_CORRECT;
    }
    
    return ANSWER_WRONG;
}