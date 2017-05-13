#pragma once
#include "Circle.h"
#include "ShapeCreator.h"
#include "Triangle.h"

class CCreateTriangle : public CShapeCreator
{
public:
	static CCreateTriangle& GetInstance();

	std::unique_ptr<IShape> CreateShape(const std::vector<LongLongLong>& params) override;

private:
	CCreateTriangle();
	~CCreateTriangle();
	CCreateTriangle(CCreateTriangle const&) = delete;
	CCreateTriangle& operator= (CCreateTriangle const&) = delete;
};

