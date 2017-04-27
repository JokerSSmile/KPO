#pragma once
#include "Point.h"
#include "Shape.h"
#include "LineSegment.h"

class CTriangle : public IShape
{
public:
	CTriangle(const CPoint& p1, const CPoint& p2, const CPoint& p3);
	~CTriangle() = default;

	LongLongLong GetArea() const override;
	LongLongLong GetPerimeter() const override;

private:
	CLineSegment m_side1;
	CLineSegment m_side2;
	CLineSegment m_side3;
};

