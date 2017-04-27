#pragma once
#include "ShapeCreator.h"
#include "Reactangle.h"
#include "Point.h"

class CCreateRectangle : public CShapeCreator
{
public:
	static CCreateRectangle& GetInstance();

	std::unique_ptr<IShape> CreateShape(const std::vector<int>& params) override;

private:
	CCreateRectangle();
	~CCreateRectangle();
	CCreateRectangle(CCreateRectangle const&) = delete;
	CCreateRectangle& operator= (CCreateRectangle const&) = delete;
};

