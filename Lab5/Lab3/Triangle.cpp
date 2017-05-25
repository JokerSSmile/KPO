#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(const CPoint& p1, const CPoint& p2, const CPoint& p3)
	: m_side1(p1, p2)
	, m_side2(p1, p3)
	, m_side3(p2, p3)
{
}

LongLongLong CTriangle::GetArea() const
{
	LongLongLong q = GetPerimeter();
	LongLongLong w = LongLongLong("2");
	LongLongLong p = q / w;
	auto p1 = m_side1.GetPerimeter();
	auto a = p - p1;
	auto b = p - m_side2.GetPerimeter();
	auto c = p - m_side3.GetPerimeter();
	auto d = p * (a)* (b)* (c);
	return Sqrt(d);
}

LongLongLong CTriangle::GetPerimeter() const
{
	return m_side1.GetPerimeter() + m_side2.GetPerimeter() + m_side3.GetPerimeter();
}

void CTriangle::Accept(CVisitor& visitor)
{
	visitor.Visit(this);
}
