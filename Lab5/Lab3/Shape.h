#pragma once
#include "LongLongLong.h"
#include "Visitor.h"

class IShape
{
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual LongLongLong GetPerimeter() const = 0;
	virtual LongLongLong GetArea() const = 0;
	virtual void Accept(CVisitor& visitor) = 0;
};
