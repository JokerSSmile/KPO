#include "stdafx.h"
#include "CreateCircle.h"

CCreateCircle & CCreateCircle::GetInstance()
{
	static CCreateCircle instance;
	return instance;
}

std::unique_ptr<IShape> CCreateCircle::CreateShape(const std::vector<int>& params)
{
	return std::make_unique<CCircle>(CPoint(params[0], params[1]), params[2]);
}

CCreateCircle::CCreateCircle() {}

CCreateCircle::~CCreateCircle() {}

