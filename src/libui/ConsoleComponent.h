#ifndef _CONSOLE_COMPONENT_H_
#define _CONSOLE_COMPONENT_H_

#include <vector>
#include <memory>
#include "Console.h"

/// 控制台页面/元件
class ConsoleComponent
{
protected:
	/// 使用的输入流与输出流
    std::istream &ins;
    std::ostream &outs;
public:
	/// 包含在页面/元件中的其他页面/元件
    std::vector<ConsoleComponent*> Components;
    /// 使用的控制台
	Console &Root;

	/// 使用控制台构造
    ConsoleComponent(Console &Root)
        : ins(Root.ins), outs(Root.outs), Root(Root)
    {

    }
	/// 默认析构
    virtual ~ConsoleComponent() = default;

	/// 添加子页面/元件
    void Add(ConsoleComponent &comp);
	/// 显示所有子页面/元件
    void ShowSubComponents();
	/// 显示自身
    virtual bool Show() = 0;
	/// 按输入执行内容
    virtual void DoButtons();
	/// 按参数执行内容
    virtual void DoButtons(char key);
};

#endif // _CONSOLE_COMPONENT_H_