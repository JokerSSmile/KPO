#pragma once
#include "ShapeCreator.h"
#include "LineSegment.h"

class CCreateLineSegment : public CShapeCreator
{
public:
	static CCreateLineSegment& GetInstance();

	std::unique_ptr<IShape> CreateShape(const std::vector<int>& params) override;

private:
	CCreateLineSegment();
	~CCreateLineSegment();
	CCreateLineSegment(CCreateLineSegment const&) = delete;
	CCreateLineSegment& operator= (CCreateLineSegment const&) = delete;
};

