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
}

void HtmlQuestionBuilder::EndTitle()
{
    outs << "</head>" << endl;
}
    
void HtmlQuestionBuilder::BeginBody()
{
    outs << "<body>" << endl;
    outs << "<form action=\".\" method=\"POST\">" << endl;
}
    
void HtmlQuestionBuilder::BeginQuestion(std::string question)
{
    outs << "<p>" << question << "</p>" << endl;
}
    
void HtmlQuestionBuilder::BeginSelect()
{
    outs << "<select name=\"opt\">" << endl;
}

void HtmlQuestionBuilder::Option(char key, std::string option)
{
    outs << "<option value=\"" << key << "\">" << key << ". " << option << "</option>" << endl;
}

void HtmlQuestionBuilder::EndSelect()
{
    outs << "</select>" << endl;
}
    
void HtmlQuestionBuilder::BeginTextInput()
{
    outs << "<input type=\"text\" value=\"\">" << endl;
}

void HtmlQuestionBuilder::EndTextInput()
{
    
}
    
void HtmlQuestionBuilder::EndQuestion()
{

}
    
void HtmlQuestionBuilder::EndBody()
{
    outs << "<input type=\"submit\" value=\"Submit\">" << endl;
    outs << "</form>" << endl;
    outs << "</body>" << endl;
}
    
void HtmlQuestionBuilder::End()
{
    outs << "</html>" << endl;
}