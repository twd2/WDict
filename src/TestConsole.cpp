#include "TestConsole.h"

TestConsole::TestConsole(Console &Root, WordIteratorCreator &iterCreator, size_t limit, const string &title)
    : ConsoleComponent(Root), questionBuilder(Root), iterCreator(iterCreator), Limit(limit), Title(title)
{
    initIter();
}

void TestConsole::initIter()
{
    iter = make_shared<WithLimitIterator>(Limit, iterCreator.Create());
    questionGenerator = make_shared<QuestionGenerator>(Globals::RandomEngine, *Globals::Dict, *iter, questionBuilder);
    if ((word = questionGenerator->GenerateOne(answer)) == "")
    {
        throw string("Question generating failed!");
    }
}

bool TestConsole::Show()
{
    WithTitleConsole(Root, Title).Show();
    
    if (word != "")
    {
        questionBuilder.Show();
        answer_t userAnswer = questionBuilder.CheckAnswer(answer);
        
        auto showAnswer = [&] ()
        {
            outs << "答案: ";
            if (answer == "T")
            {
                outs << "正确";
            }
            else if (answer == "F")
            {
                outs << "错误";
            }
            else
            {
                outs << answer;
            }
            outs << "。" << endl;
        };

        if (userAnswer == ANSWER_BACK)
        {
            ConfirmConsole cc(Root, "确定要返回吗?", false);
            cc.Show();
            if (cc.Value)
            {
                Root.Back();
            }
            return true;
        }
        
        ++Counters[userAnswer];
        Globals::CurrentUser->IncCounter(word, COUNTER_TEST);
        if (userAnswer == ANSWER_CORRECT)
        {
            Globals::CurrentUser->IncCounter(word, COUNTER_PASS);
        }
        else
        {
            IncorrectWords.push_back(word);
        }
        Globals::UserCounterDB->Sync();
        
        if (userAnswer == ANSWER_WRONG || userAnswer == ANSWER_ABANDONED)
        {
            if (userAnswer == ANSWER_ABANDONED)
            {
                outs << "已放弃。" << endl;
            }
            else // userAnswer == ANSWER_WRONG
            {
                outs << "回答错误。" << endl;
            }
            showAnswer();
            ConfirmConsole cc(Root, "查看单词解释?", true);
            cc.Show();
            if (cc.Value)
            {
                Globals::CurrentUser->IncCounter(word, COUNTER_LEARN);
                Globals::UserCounterDB->Sync();
                Root.Goto(make_shared<WordConsole>(Root, word));
            }
        }
        
        word = questionGenerator->GenerateOne(answer);
    }
    else
    {
        outs << "本次测验完成!" << endl;
        
        outs << string(36, ' ') << "测验结果" << endl;
        outs << string(80, '-') << endl;
        outs << "正确: \t" << Counters[ANSWER_CORRECT] << endl;
        outs << "错误: \t" << Counters[ANSWER_WRONG] << endl;
        outs << "放弃: \t" << Counters[ANSWER_ABANDONED] << endl;
        size_t total = 0;
        for (size_t i = 0; i < (size_t)(ANSWER_COUNT); ++i)
        {
            total += Counters[i];
        }
        outs << "      \t" << total << endl;
        if (IncorrectWords.size() > 0)
        {
            outs << "请落实: ";
            for (string w : IncorrectWords)
            {
                outs << w << " ";
            }
            outs << endl;
        }
        ConfirmConsole cc(Root, "再来一轮?", false);
        cc.Show();
        if (cc.Value)
        {
            initIter();
        }
        else
        {
            Root.Back();
        }
    }
    return true;
}