#ifndef _QUESTIONBUILDERCONSOLE_H_
#define _QUESTIONBUILDERCONSOLE_H_

#include <memory>
#include <string>
#include <iostream>

#include <libui.h>
#include <libdict.h>

using namespace std;

class QuestionBuilderConsole
    : public ConsoleComponent, public IQuestionBuilder
{
private:
    bool inSelect = false;
    shared_ptr<SelectConsole> select;
    shared_ptr<TextInputConsole> text;
public:
    string UserAnswer;
    QuestionBuilderConsole(Console &Root)
        : ConsoleComponent(Root)
    {
        
    }

    void BeginQuestion(std::string question) override;
    
    void BeginOption(char key, std::string option) override;
    void EndOption() override;
    
    void BeginTextInput() override;
    void EndTextInput() override;
    
    void EndQuestion() override;
    
    bool Show() override;
};

#endif // _QUESTIONBUILDERCONSOLE_H_
