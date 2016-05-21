#ifndef _QUESTIONBUILDERCONSOLE_H_
#define _QUESTIONBUILDERCONSOLE_H_

#include <memory>
#include <string>
#include <iostream>

#include <libui.h>
#include <libdict.h>

using namespace std;

enum answer_t
{
    ANSWER_CORRECT,
    ANSWER_WRONG,
    ANSWER_ABANDONED,
    ANSWER_BACK,
    ANSWER_COUNT
};

class QuestionBuilderConsole
    : public ConsoleComponent, public IQuestionBuilder
{
private:
    bool inSelect = false;
    shared_ptr<SelectConsole> select;
    shared_ptr<TextInputConsole> text;
    string question = "";
public:
    string UserAnswer;
    QuestionBuilderConsole(Console &Root)
        : ConsoleComponent(Root)
    {
        
    }

    void BeginQuestion(std::string question) override;
    
    void BeginSelect() override;
    void Option(char key, std::string option) override;
    void EndSelect() override;
    
    void BeginTextInput() override;
    void EndTextInput() override;
    
    void EndQuestion() override;
    
    bool Show() override;
    answer_t CheckAnswer(const string &realAnswer);
};

#endif // _QUESTIONBUILDERCONSOLE_H_
