#pragma once
#include "Shape.h"
#include "Point.h"

class CRectangle : public IShape
{
public:
	CRectangle(const CPoint& leftUp, const CPoint& rightDown);
	~CRectangle() = default;

	LongLongLong GetArea() const override;
	LongLongLong GetPerimeter() const override;

private:
	CPoint m_leftUp;
	CPoint m_rightDown;
	LongLongLong m_width;
	LongLongLong m_height;
};
