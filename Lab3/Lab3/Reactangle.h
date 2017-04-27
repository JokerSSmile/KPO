#pragma once
#include "Shape.h"
#include "Point.h"

class CRectangle : public IShape
{
public:
	CRectangle(const CPoint& leftUp, const CPoint& rightDown);
	~CRectangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;

private:
	CPoint m_leftUp;
	CPoint m_rightDown;
	int m_width;
	int m_height;
};
