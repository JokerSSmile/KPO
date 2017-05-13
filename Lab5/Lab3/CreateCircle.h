#pragma once
#include "ShapeCreator.h"
#include "Circle.h"

class CCreateCircle : public CShapeCreator
{
public:
	static CCreateCircle& GetInstance();

	std::unique_ptr<IShape> CreateShape(const std::vector<LongLongLong>& params) override;

private:
	CCreateCircle();
	~CCreateCircle();
	CCreateCircle(CCreateCircle const&) = delete;
	CCreateCircle& operator= (CCreateCircle const&) = delete;
};

