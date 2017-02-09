#pragma once
#include "Shape.h"
#include "Point.h"

class CReactangle : public IShape
{
public:
	CReactangle(const CPoint& leftUp, const CPoint& rightDown);
	~CReactangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;

private:
	CPoint m_leftUp;
	CPoint m_rightDown;
	int m_width;
	int m_height;
};
