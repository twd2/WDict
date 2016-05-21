#include "QuestionBuilderConsole.h"

void QuestionBuilderConsole::BeginQuestion(std::string question)
{
    cout << question << endl;
    inSelect = false;
    select = nullptr;
    text = nullptr;
}
    
void QuestionBuilderConsole::BeginOption(char key, std::string option)
{
    if (!inSelect)
    {
        inSelect = true;
        select = make_shared<SelectConsole>(Root, "请作答(答案不区分大小写):");
        select->IgnoreCase = true;
    }
    select->Add(key, option);
}

void QuestionBuilderConsole::EndOption()
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