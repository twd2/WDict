#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include <string>
#include "UIImpl.h"

/// 未实现，GUI元件基类？
class Graphic
    : public UIImpl
{
public:
    bool Show() override;
private:
    Graphic() = delete;
};

#endif // _GRAPHIC_H_
