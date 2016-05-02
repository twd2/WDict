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
    std::string what;
    ptrdiff_t LineNumber = 1, ColumnStart = -1, ColumnEnd = -1;

    SyntaxError();
    SyntaxError(std::string what);
    SyntaxError(std::string what, ptrdiff_t LineNumber, ptrdiff_t ColumnStart);
    SyntaxError(std::string what, ptrdiff_t LineNumber, ptrdiff_t ColumnStart, ptrdiff_t ColumnEnd);

    ~SyntaxError();
};

#endif // _SYNTAXERROR_H_