#ifndef _QUESTIONBUILDERCONSOLE_H_
#define _QUESTIONBUILDERCONSOLE_H_

#include <memory>
#include <string>
#include <iostream>

#include <libui.h>
#include <libdict.h>

using namespace std;

/// 答案状态
enum answer_t
{
    ANSWER_CORRECT,/// 正确
    ANSWER_WRONG,/// 错误
    ANSWER_ABANDONED,/// 放弃
    ANSWER_BACK,/// 返回
    ANSWER_COUNT/// 预留
};

/// 问题界面
class QuestionBuilderConsole
    : public ConsoleComponent, public IQuestionBuilder
{
private:
	/// 是否是选择，选择子界面，输入子界面，问题串
    bool inSelect = false;
    shared_ptr<SelectConsole> select;
    shared_ptr<TextInputConsole> text;
    string question = "";
public:
	/// 回答
    string UserAnswer;
    ///构造
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
	/// 检查答案
    answer_t CheckAnswer(const string &realAnswer);
};

#endif // _QUESTIONBUILDERCONSOLE_H_
