#ifndef _HTMLQUESTIONBUILDER_H_
#define _HTMLQUESTIONBUILDER_H_

#include <libdict.h>
#include <string>
#include <iostream>

using namespace std;

class HtmlQuestionBuilder
    : IQuestionBuilder
{
private:
    ostream &outs;
    bool inSelect = false;
public:
    HtmlQuestionBuilder(ostream &outs)
        : outs(outs)
    {
        
    }

    void Begin() override;
    
    void BeginTitle(std::string title) override;
    void EndTitle() override;
    
    void BeginBody() override;
    
    void BeginQuestion(std::string question) override;
    
    void BeginOption(char key, std::string option) override;
    void EndOption() override;
    
    void BeginTextInput() override;
    void EndTextInput() override;
    
    void EndQuestion() override;
    
    void EndBody() override;
    
    void End() override;
};

#endif // _HTMLQUESTIONBUILDER_H_
