#ifndef _UIIMPL_H_
#define _UIIMPL_H_

/// UI对象接口
class UIImpl
{
public:
	/// 默认析构
    virtual ~UIImpl() = default;
	/// 显示UI对象
    virtual bool Show() = 0;
};

#endif // _UIIMPL_H_