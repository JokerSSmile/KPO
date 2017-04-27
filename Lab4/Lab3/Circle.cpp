#include "stdafx.h"
#include "Circle.h"

const LongLongLong PI = LongLongLong("3");

CCircle::CCircle(const CPoint& center, const LongLongLong& radius)
	: m_center(center)
	, m_radius(radius)
{
}

LongLongLong CCircle::GetArea() const
{
	return PI * Pow(m_radius, 2);
}

LongLongLong CCircle::GetPerimeter() const
{
	return LongLongLong("2") * PI * m_radius;
}
