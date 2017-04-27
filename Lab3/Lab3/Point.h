#pragma once
#include "Shape.h"

class CPoint : public IShape
{
public:
	CPoint(int x, int y);
	~CPoint() = default;

	int GetX() const;
	int GetY() const;

	double GetPerimeter() const override;
	double GetArea() const override;

private:
	int m_x;
	int m_y;
};

