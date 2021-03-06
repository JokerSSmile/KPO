#pragma once
#include "Shape.h"

class CShapeCreator
{
public:
	virtual std::unique_ptr<IShape> CreateShape(const std::vector<LongLongLong>& params) = 0;

protected:
	CShapeCreator() = default;
	~CShapeCreator() = default;
};

