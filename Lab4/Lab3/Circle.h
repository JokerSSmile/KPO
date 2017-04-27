#pragma once
#include "Shape.h"
#include "Point.h"

class CCircle : public IShape
{
public:
	CCircle(const CPoint& center, const LongLongLong& radius);
	~CCircle() = default;

	LongLongLong GetArea() const override;
	LongLongLong GetPerimeter() const override;

private:
	CPoint m_center;
	LongLongLong m_radius;
};
