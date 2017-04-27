#include "stdafx.h"
#include "LineSegment.h"

CLineSegment::CLineSegment(const CPoint& p1, const CPoint& p2)
	: m_p1(p1)
	, m_p2(p2)
{
}

LongLongLong CLineSegment::GetArea() const
{
	return 0;
}

LongLongLong CLineSegment::GetPerimeter() const
{
	return Sqrt(Pow((m_p1.GetX() - m_p2.GetX()), 2) + Pow((m_p1.GetY() - m_p2.GetY()), 2));
}
