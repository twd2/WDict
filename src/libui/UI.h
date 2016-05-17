#ifndef _UI_H_
#define _UI_H_

#include "UIImpl.h"
#include <memory>
#include <iostream>

/// UI相关工具
class UI
{
private:
	/// 当前使用的UIImpl
    static std::shared_ptr<UIImpl> ui;

public:
    // static interfaces
	/// 用UIImpl初始化
    static void Init(std::shared_ptr<UIImpl> ui);
    /// 开始显示UIImpl
	static void Start();
};

#endif // _UI_H_