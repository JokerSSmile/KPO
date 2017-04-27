#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(int x, int y)
	: m_x(x)
	, m_y(y)
{
}

int CPoint::GetX() const
{
	return m_x;
}

int CPoint::GetY() const
{
	return m_y;
}

double CPoint::GetPerimeter() const
{
	return 0.0;
}

double CPoint::GetArea() const
{
	return 0.0;
}
