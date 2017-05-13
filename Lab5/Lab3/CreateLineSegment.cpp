#include "stdafx.h"
#include "CreateLineSegment.h"

CCreateLineSegment & CCreateLineSegment::GetInstance()
{
	static CCreateLineSegment instance;
	return instance;
}

std::unique_ptr<IShape> CCreateLineSegment::CreateShape(const std::vector<int>& params)
{
	return std::make_unique<CLineSegment>(CPoint(params[0], params[1]), CPoint(params[2], params[3]));
}

CCreateLineSegment::CCreateLineSegment() {}

CCreateLineSegment::~CCreateLineSegment() {}
