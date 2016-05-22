#include "HtmlQuestionBuilder.h"

void HtmlQuestionBuilder::Begin()
{
    outs << "<!DOCTYPE html>" << endl;
    outs << "<html>" << endl;
}
    
void HtmlQuestionBuilder::BeginTitle(std::string title)
{
    outs << "<head>" << endl
         << "<title>" << title << "</title>" << endl;
    this->title = title;
}

void HtmlQuestionBuilder::EndTitle()
{
    outs << "</head>" << endl;
}
    
void HtmlQuestionBuilder::BeginBody()
{
    outs << "<body>" << endl;
    if (title != "")
    {
        outs << "<h1>" << title << "</h1><hr />" << endl;
    }
    outs << "<form action=\"?\" method=\"POST\">" << endl;
}
    
void HtmlQuestionBuilder::BeginQuestion(std::string question)
{
    ++questionId;
    outs << "<p>" << questionId << ". " << question << "</p>" << endl;
}
    
void HtmlQuestionBuilder::BeginSelect()
{
    
}

void HtmlQuestionBuilder::Option(char key, std::string option)
{
    outs << "<label><input name=\"Q" << questionId << "\" type=\"radio\" value=\"" << key << "\" />" << key << ". " << option << "</label>" << endl;
}

void HtmlQuestionBuilder::EndSelect()
{
    
}
    
void HtmlQuestionBuilder::BeginTextInput()
{
    outs << "<input name=\"Q" << questionId << "\" type=\"text\" value=\"\">" << endl;
}

void HtmlQuestionBuilder::EndTextInput()
{
    
}
    
void HtmlQuestionBuilder::EndQuestion()
{

}
    
void HtmlQuestionBuilder::EndBody()
{
    outs << "<p><input type=\"submit\" value=\"提交\"></p>" << endl;
    outs << "</form>" << endl;
    outs << "</body>" << endl;
}
    
void HtmlQuestionBuilder::End()
{
    outs << "</html>" << endl;
}