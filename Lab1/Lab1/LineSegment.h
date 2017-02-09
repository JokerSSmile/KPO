#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(const CPoint& p1, const CPoint& p2);
	~CLineSegment() = default;

	double GetArea() const override;
	double GetPerimeter() const override;

private:
	CPoint m_p1;
	CPoint m_p2;
};