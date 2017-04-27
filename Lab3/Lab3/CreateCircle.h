#pragma once
#include "ShapeCreator.h"
#include "Circle.h"
#include "CreatePoint.h"

class CCreateCircle : public CShapeCreator
{
public:
	static CCreateCircle& GetInstance();

	std::unique_ptr<IShape> CreateShape(const std::vector<int>& params) override;

private:
	CCreateCircle();
	~CCreateCircle();
	CCreateCircle(CCreateCircle const&) = delete;
	CCreateCircle& operator= (CCreateCircle const&) = delete;
};

