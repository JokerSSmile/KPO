#pragma once
#include "Shape.h"
#include "Visitor.h"

class CPoint : public IShape
{
public:
	CPoint(const LongLongLong& x, const LongLongLong& y);
	~CPoint() = default;

	LongLongLong GetX() const;
	LongLongLong GetY() const;

	LongLongLong GetPerimeter() const override;
	LongLongLong GetArea() const override;
	void Accept(CVisitor& visitor) override;

private:
	LongLongLong m_x;
	LongLongLong m_y;
};

