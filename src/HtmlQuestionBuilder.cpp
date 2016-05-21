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
    inSelect = false;
}
    
void HtmlQuestionBuilder::BeginOption(char key, std::string option)
{
    if (!inSelect)
    {
        outs << "<select name=\"opt\">" << endl;
        inSelect = true;
    }
    outs << "<option value=\"" << key << "\">" << key << ". " << option << "</option>" << endl;
}

void HtmlQuestionBuilder::EndOption()
{
    
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
    if (inSelect)
    {
        outs << "</select>" << endl;
        inSelect = false;
    }
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