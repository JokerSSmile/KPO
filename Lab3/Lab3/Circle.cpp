#include "stdafx.h"
#include "Circle.h"

const double PI = std::atan(1.0) * 4;

CCircle::CCircle(const CPoint& center, int radius)
	: m_center(center)
	, m_radius(radius)
{
}

double CCircle::GetArea() const
{
	return PI * std::pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * PI * m_radius;
}
