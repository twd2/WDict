#ifndef _TEXTCONSOLE_H_
#define _TEXTCONSOLE_H_

#include <libdict.h>
#include <libui.h>
#include <libtextdb.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "WordConsole.h"
#include "EvaluateStrategy.h"

using namespace std;

/// 文本分析器界面
class TextConsole
    : public ConsoleComponent
{
protected:
	/// 文件名、单词输入框
    TextInputConsole txtFilename, txtWord;
	/// 文件名，单词
    string filename;
    vector<string> Words;
public:
	///构造
    TextConsole(Console &Root);

    bool Show() override;
};

#endif // _TEXTCONSOLE_H_
