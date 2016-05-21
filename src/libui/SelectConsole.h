#ifndef _SELECTCONSOLE_H_
#define _SELECTCONSOLE_H_

#include "ConsoleComponent.h"
#include "Console.h"
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

/// 多项选择元件
/// 形如
/// (T)Blue
/// (W)Purple
/// (D)Cray
/// Color
/// 显示后可获取已选项
class SelectConsole
    : public ConsoleComponent
{
public:
	/// 是否忽略大小写
    bool IgnoreCase = false;
	/// 选项与描述文字
    std::vector<std::pair<char, std::string> > Choices;
    /// 用户输入原文
    std::string Value;
    /// 已选项的序号
	std::vector<size_t> SelectedIndexes;
    /// 提示信息
	std::string Message;

	/// 构造
    SelectConsole(Console &Root, const std::string &message)
        : ConsoleComponent(Root), Message(message)
    {

    }

	/// 添加选项
    void Add(char ch, const std::string &title)
    {
        Choices.push_back(std::make_pair(ch, title));
    }

	/// 选项
    bool Show() override;

	/// 判断某一项（用序号或选项字符指明）是否被选中
    bool Selected(char ch);
    bool Selected(size_t index);

private:
	/// 变为小写
    static char toLower(char ch);
};

#endif // _SELECTCONSOLE_H_
