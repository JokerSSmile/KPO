#pragma once
#include "Shape.h"
#include "Point.h"

class CCircle : public IShape
{
public:
	CCircle(const CPoint& center, int radius);
	~CCircle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;

private:
	CPoint m_center;
	int m_radius;
};
