#ifndef _WITHTITLECONSOLE_H_
#define _WITHTITLECONSOLE_H_

#include <iostream>
#include <string>
#include <memory>
#include "ConsoleComponent.h"
#include "Console.h"
#include <cstdlib>

/// 带标题页面

class WithTitleConsole
    : public ConsoleComponent
{
private:
	/// 标题
    std::string title;
    /// 内部元件
	std::shared_ptr<ConsoleComponent> comp;
public:
	/// 无内容页面构造
    WithTitleConsole(Console &Root, const std::string &title)
        : ConsoleComponent(Root), title(title), comp(nullptr)
    {

    }

	/// 有内容页面构造
    WithTitleConsole(const std::string &title, std::shared_ptr<ConsoleComponent> comp)
        : ConsoleComponent(comp->Root), title(title), comp(comp)
    {

    }
	/// 显示页面
    bool Show() override;
};

#endif // _WITHTITLECONSOLE_H_