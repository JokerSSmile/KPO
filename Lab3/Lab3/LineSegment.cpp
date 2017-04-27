#include "stdafx.h"
#include "LineSegment.h"

CLineSegment::CLineSegment(const CPoint& p1, const CPoint& p2)
	: m_p1(p1)
	, m_p2(p2)
{
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return std::sqrt(std::pow((m_p1.GetX() - m_p2.GetX()), 2) + std::pow((m_p1.GetY() - m_p2.GetY()), 2));
}
