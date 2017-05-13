#include "stdafx.h"
#include "CreatePoint.h"

CCreatePoint & CCreatePoint::GetInstance()
{
	static CCreatePoint instance;
	return instance;
}

std::unique_ptr<IShape> CCreatePoint::CreateShape(const std::vector<int>& params)
{
	return std::make_unique<CPoint>(params[0], params[1]);
}

CCreatePoint::CCreatePoint() {}

CCreatePoint::~CCreatePoint() {}