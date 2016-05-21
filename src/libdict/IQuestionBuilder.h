#ifndef _IQUESTIONBUILDER_H_
#define _IQUESTIONBUILDER_H_

#include <string>

class IQuestionBuilder
{
public:
    virtual ~IQuestionBuilder() = default;
    
    virtual void Begin() { }
    
    virtual void BeginTitle(std::string title) { }
    virtual void EndTitle() { }
    
    virtual void BeginBody() { }
    
    virtual void BeginQuestion(std::string question) { }
    
    virtual void BeginSelect() { }
    virtual void Option(char key, std::string option) { }
    virtual void EndSelect() { }
    
    virtual void BeginTextInput() { }
    virtual void EndTextInput() { }
    
    virtual void EndQuestion() { }
    
    virtual void EndBody() { }
    
    virtual void End() { }
};

#endif // _IQUESTIONBUILDER_H_
