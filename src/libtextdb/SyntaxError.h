#ifndef _SYNTAXERROR_H_
#define _SYNTAXERROR_H_

#include "StringUtils.h"
#include <string>
#include <cstddef>

using std::size_t;
using std::ptrdiff_t;

class SyntaxError
{
public:
    std::wstring what;
    ptrdiff_t LineNumber = 1, ColumnStart = -1, ColumnEnd = -1;

    SyntaxError();
    SyntaxError(std::wstring);
    SyntaxError(std::wstring, ptrdiff_t, ptrdiff_t);
    SyntaxError(std::wstring, ptrdiff_t, ptrdiff_t, ptrdiff_t);

    ~SyntaxError();
};

#endif // _SYNTAXERROR_H_