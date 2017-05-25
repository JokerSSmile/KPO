#pragma once
#include "LongLongLong.h"


class CTriangle;
class CRectangle;
class CCircle;
class CPoint;
class CLineSegment;

class CVisitor
{
public:
	virtual void Visit(CCircle* circle) = 0;
	virtual void Visit(CRectangle* rectangle) = 0;
	virtual void Visit(CTriangle* triangle) = 0;
	virtual void Visit(CPoint* triangle) = 0;
	virtual void Visit(CLineSegment* triangle) = 0;
};

class ShapeInfoVisitor : public CVisitor
{
public:
	ShapeInfoVisitor() = default;
	~ShapeInfoVisitor() = default;

	void Visit(CCircle* circle);
	void Visit(CRectangle* rectangle);
	void Visit(CTriangle* triangle);
	void Visit(CPoint * point);
	void Visit(CLineSegment * point);
};



class IShape
{
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual LongLongLong GetPerimeter() const = 0;
	virtual LongLongLong GetArea() const = 0;
	virtual void Accept(CVisitor& visitor) = 0;
};
