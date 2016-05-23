#ifndef _RETRIVECONSOLE_H_
#define _RETRIVECONSOLE_H_

#include <libui.h>
#include <iostream>
#include <memory>
#include "WordConsole.h"

using namespace std;

/// 查询界面
class RetriveConsole
    : public ConsoleComponent
{
protected:
	/// 查询框
    TextInputConsole txtWord;
public:
	/// 构造
    RetriveConsole(Console &Root);

    bool Show() override;
};

#endif // _RETRIVECONSOLE_H_
