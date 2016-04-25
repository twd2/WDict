#include "SyntaxError.h"

SyntaxError::SyntaxError()
{
    
}

SyntaxError::SyntaxError(std::wstring what) : what(what)
{
    
}

SyntaxError::SyntaxError(std::wstring what, ptrdiff_t LineNumber, ptrdiff_t ColumnStart)
    : what(what), LineNumber(LineNumber), ColumnStart(ColumnStart)
{
    if (LineNumber < 0 || ColumnStart < 0) return;
    this->what = L"Line " + StringUtils::ToString(LineNumber) + L", Col " + StringUtils::ToString(ColumnStart) + L": " + this->what;
}

SyntaxError::SyntaxError(std::wstring what, ptrdiff_t LineNumber, ptrdiff_t ColumnStart, ptrdiff_t ColumnEnd)
    : what(what), LineNumber(LineNumber), ColumnStart(ColumnStart), ColumnEnd(ColumnEnd)
{
    if (LineNumber < 0 || ColumnStart < 0) return;
    if (ColumnStart != ColumnEnd)
    {
        this->what = L"Line " + StringUtils::ToString(LineNumber) + L", Col " + StringUtils::ToString(ColumnStart) + L"~" + StringUtils::ToString(ColumnEnd) + L": " + this->what;
    }
    else
    {
        this->what = L"Line " + StringUtils::ToString(LineNumber) + L", Col " + StringUtils::ToString(ColumnStart) + L": " + this->what;
    }
}

SyntaxError::~SyntaxError()
{
    
}
