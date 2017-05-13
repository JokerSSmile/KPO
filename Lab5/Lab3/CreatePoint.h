#pragma once
#include "ShapeCreator.h"
#include "Point.h"

class CCreatePoint : public CShapeCreator
{
public:
	static CCreatePoint& GetInstance();

	std::unique_ptr<IShape> CreateShape(const std::vector<int>& params) override;

private:
	CCreatePoint();
	~CCreatePoint();
	CCreatePoint(CCreatePoint const&) = delete;
	CCreatePoint& operator= (CCreatePoint const&) = delete;
};

