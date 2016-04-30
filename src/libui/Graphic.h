#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include <string>
#include "UIImpl.h"

class Graphic
    : public UIImpl
{
public:
    bool Show() override;
};

#endif // _GRAPHIC_H_
