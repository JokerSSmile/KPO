#include "stdafx.h"
#include "CreateCircle.h"

CCreateCircle & CCreateCircle::GetInstance()
{
	static CCreateCircle instance;
	return instance;
}

std::unique_ptr<IShape> CCreateCircle::CreateShape(const std::vector<LongLongLong>& params)
{
	return std::make_unique<CCircle>(CPoint(params[0].GetNumber(), params[1].GetNumber()), params[2].GetNumber());
}

CCreateCircle::CCreateCircle() {}

CCreateCircle::~CCreateCircle() {}