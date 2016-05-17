#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include <string>
#include "UIImpl.h"

/// 图形用户界面 (暂未实现)
class Graphic
    : public UIImpl
{
public:
    bool Show() override;
private:
    Graphic() = delete;
};

#endif // _GRAPHIC_H_
