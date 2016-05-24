#include "LearnConsole.h"

LearnConsole::LearnConsole(Console &Root, size_t Limit)
    : ConsoleComponent(Root), btnGot(Root, '1', "学会了"), btnWord(Root, '2', "深入学习"), btnBack(Root, 'b', "结束学习"), Limit(Limit)
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
    iter = make_shared<WithLimitIterator>(Limit, Globals::NewWordIteratorCreator->Create());
    word = iter->Next();
}

bool LearnConsole::Show()
{
    WithTitleConsole(Root, "学习").Show();
    
    if (word != "")
    {
        outs << word << "    ";
        
        if (Globals::CurrentUser->WordEvaluator->IsKnown(word))
        {
            outs << "*复习*    ";
        }
        
        outs << endl;
        WordConsole::PrintWord(outs, "系统", Globals::Dict->GetWord(word));
        WordConsole::PrintWord(outs, "您添加的", Globals::CurrentUser->GetWord(word));
        ShowSubComponents();
        DoButtons();
    }
    else
    {
        outs << "本次学习任务完成!" << endl;
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
    Root.Goto(make_shared<WordConsole>(Root, word));
}

void LearnConsole::Back()
{
    Root.Back();
}
