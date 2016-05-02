#include "LearnConsole.h"

LearnConsole::LearnConsole(Console &Root, size_t Limit)
    : ConsoleComponent(Root), btnGot(Root, '0', "学会了"), btnWord(Root, '1', "深入学习"), btnBack(Root, 'b', "结束学习"), Limit(Limit)
{
    btnGot.OnClick = bind(&LearnConsole::Got, this);
    Add(btnGot);
    
    btnWord.OnClick = bind(&LearnConsole::Word, this);
    Add(btnWord);
    
    btnBack.OnClick = bind(&LearnConsole::Back, this);
    Add(btnBack);
    
    initIter();
}

void LearnConsole::initIter()
{
    iter = make_shared<WithLimitIterator>(Limit, Globals::IterCreator->CreateNewWordsIterator());
    word = iter->Next();
}

bool LearnConsole::Show()
{
    if (word != "")
    {
        cout << word << "    ";
        
        if (Globals::CurrentUser->WordEvaluate->IsKnown(word))
        {
            cout << "*复习*    ";
        }
        
        cout << endl;
        WordConsole::PrintWord("系统", Globals::Dict->GetWord(word));
        WordConsole::PrintWord("您添加的", Globals::CurrentUser->GetWord(word));
        ShowSubComponents();
        DoButtons();
    }
    else
    {
        cout << "本次学习任务完成!" << endl;
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

void LearnConsole::Got()
{
    Globals::CurrentUser->IncCounter(word, COUNTER_LEARN);
    Globals::UserCounterDB->Sync();
    word = iter->Next();
}

void LearnConsole::Word()
{
    Root.Goto(make_shared<WithTitleConsole>(word, make_shared<WordConsole>(Root, word)));
}

void LearnConsole::Back()
{
    Root.Back();
}