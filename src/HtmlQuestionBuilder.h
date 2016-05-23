#ifndef _HTMLQUESTIONBUILDER_H_
#define _HTMLQUESTIONBUILDER_H_

#include <libdict.h>
#include <string>
#include <iostream>

using namespace std;

/// HTML试卷生成器
class HtmlQuestionBuilder
    : public IQuestionBuilder
{
private:
	/// 输出流，标题，问题Id
    ostream &outs;
    string title = "";
    size_t questionId = 0;
public:
	/// 构造
    HtmlQuestionBuilder(ostream &outs)
        : outs(outs)
    {

    }

    void Begin() override;

    void BeginTitle(std::string title) override;
    void EndTitle() override;

    void BeginBody() override;

    void BeginQuestion(std::string question) override;

    void BeginSelect() override;
    void Option(char key, std::string option) override;
    void EndSelect() override;

    void BeginTextInput() override;
    void EndTextInput() override;

    void EndQuestion() override;

    void EndBody() override;

    void End() override;
};

#endif // _HTMLQUESTIONBUILDER_H_
