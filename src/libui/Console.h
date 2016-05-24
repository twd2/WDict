#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <stack>
#include <cstdlib>
#include <iostream>
#include <memory>
#include "UIImpl.h"

/// 控制台页面/元件
class ConsoleComponent;

/// 控制台对象
class Console
    : public UIImpl
{
protected:
    /// 使用的输入与输出流
    std::istream &ins;
    std::ostream &outs;
public:
    /// 页面栈
    std::stack<std::shared_ptr<ConsoleComponent> > Activities;

    /// 用输入与输出流构造
    Console(std::istream &ins, std::ostream &outs)
        : ins(ins), outs(outs)
    {

    }

    /// 显示
    bool Show() override;
    /// 清空
    void Clear();
    /// 跳转至页面
    void Goto(std::shared_ptr<ConsoleComponent> act);
    /// 返回上一个页面
    void Back();
    /// 忽略输入流中的一串换行符
    void IgnoreLeftNewline();

    friend class ConsoleComponent;
};

#endif // _CONSOLE_H_
