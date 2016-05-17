#ifndef _UIIMPL_H_
#define _UIIMPL_H_

class UIImpl
{
public:
    virtual ~UIImpl() = default;
    virtual bool Show() = 0;
};

#endif // _UIIMPL_H_