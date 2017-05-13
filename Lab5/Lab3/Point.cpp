#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(const LongLongLong& x, const LongLongLong& y)
	: m_x(x)
	, m_y(y)
{
}

LongLongLong CPoint::GetX() const
{
	return m_x;
}

LongLongLong CPoint::GetY() const
{
	return m_y;
}

LongLongLong CPoint::GetPerimeter() const
{
	return LongLongLong("0");
}

LongLongLong CPoint::GetArea() const
{
	return LongLongLong("0");
}