#include "QuestionBuilderConsole.h"

void QuestionBuilderConsole::BeginQuestion(std::string question)
{
    this->question = question;
    inSelect = false;
    select = nullptr;
    text = nullptr;
}

void QuestionBuilderConsole::BeginSelect()
{
    select = make_shared<SelectConsole>(Root, "请作答(单选, 答案不区分大小写):");
    select->IgnoreCase = true;
}
    
void QuestionBuilderConsole::Option(char key, std::string option)
{
    select->Add(key, option);
}

void QuestionBuilderConsole::EndSelect()
{
    select->Add('E', "放弃");
    select->Add('Q', "返回");
}
    
void QuestionBuilderConsole::BeginTextInput()
{
    text = make_shared<TextInputConsole>(Root, "请作答(请小写, 输入空行放弃):", TEXTINPUT_LINE);
}

void QuestionBuilderConsole::EndTextInput()
{
    
}
    
void QuestionBuilderConsole::EndQuestion()
{
    if (inSelect)
    {
        inSelect = false;
    }
}

bool QuestionBuilderConsole::Show()
{
    if (select && text)
    {
        throw string("both select and text");
    }
    
    if (!select && !text)
    {
        throw string("neither select nor text");
    }
    
    outs << question << endl;
    if (select)
    {
        select->Show();
        UserAnswer = select->Value;
    }
    else if (text)
    {
        text->Show();
        UserAnswer = text->Value;
    }
    return true;
}

answer_t QuestionBuilderConsole::CheckAnswer(const string &realAnswer)
{
    if (select)
    {
        if (select->SelectedIndexes.size() != 1 || select->Selected('E'))
        {
            return ANSWER_ABANDONED;
        }
        else if (select->Selected('Q'))
        {
            return ANSWER_BACK;
        }
        
        if (SelectConsole::ToLower(select->Value[0]) == SelectConsole::ToLower(realAnswer[0]))
        {
            return ANSWER_CORRECT;
        }
        else
        {
            return ANSWER_WRONG;
        }
    }
    else if (text)
    {
        if (text->Value == "")
        {
            return ANSWER_ABANDONED;
        }
        
        if (text->Value == realAnswer)
        {
            return ANSWER_CORRECT;
        }
        else
        {
            return ANSWER_WRONG;
        }
    }
}