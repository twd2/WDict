#ifndef _BUTTONCONSOLE_H_
#define _BUTTONCONSOLE_H_

#include "ConsoleComponent.h"
#include "Console.h"
#include <string>
#include <functional>

/// 按钮元件
/// 形如[X]，输入字母X时应当执行事件监听函数
/// 事件监听函数实际上是手动触发的
class ButtonConsole
    : public ConsoleComponent
{
public:
    /// 事件监听函数
    std::function<void ()> OnClick;
    /// 对应的字符
    char Key;
    /// 标题
    std::string Title;

    /// 构造
    ButtonConsole(Console &Root, char key, const std::string &title)
        : ConsoleComponent(Root), Key(key), Title(title)
    {

    }

    /// 显示
    bool Show() override;
};

/// 宏定义，将某类的一个函数作为事件监听函数绑定至一个按钮上
#define BUTTON_ONCLICK(cls, name) do \
{ \
btn##name.OnClick = bind(&cls::name, this); \
Add(btn##name); \
} while (false)

#endif // _BUTTONCONSOLE_H_
