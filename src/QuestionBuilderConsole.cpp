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
    select = make_shared<SelectConsole>(Root, "请作答(答案不区分大小写):");
    select->IgnoreCase = true;
}
    
void QuestionBuilderConsole::Option(char key, std::string option)
{
    select->Add(key, option);
}

void QuestionBuilderConsole::EndSelect()
{
    
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