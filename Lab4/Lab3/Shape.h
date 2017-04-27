#pragma once
#include "LongLongLong.h"

class IShape
{
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual LongLongLong GetPerimeter() const = 0;
	virtual LongLongLong GetArea() const = 0;
};
