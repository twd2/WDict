#ifndef _IQUESTIONBUILDER_H_
#define _IQUESTIONBUILDER_H_

#include <string>

/// 试卷字符串生成器
class IQuestionBuilder
{
public:
    virtual ~IQuestionBuilder() = default;

	/// 预处理
    virtual void Begin() { }

	/// 标题
    virtual void BeginTitle(std::string title) { }
    virtual void EndTitle() { }

	/// 预处理内容
    virtual void BeginBody() { }

	/// 预处理问题
    virtual void BeginQuestion(std::string question) { }

	/// 预处理选项，打印选项，结束选项
    virtual void BeginSelect() { }
    virtual void Option(char key, std::string option) { }
    virtual void EndSelect() { }

	/// 文本框
    virtual void BeginTextInput() { }
    virtual void EndTextInput() { }

	/// 结束问题
    virtual void EndQuestion() { }

	/// 结束内容
    virtual void EndBody() { }

	/// 结束
    virtual void End() { }
};

#endif // _IQUESTIONBUILDER_H_
