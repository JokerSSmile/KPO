#include "stdafx.h"
#include "CreateTriangle.h"

CCreateTriangle & CCreateTriangle::GetInstance()
{
	static CCreateTriangle instance;
	return instance;
}

std::unique_ptr<IShape> CCreateTriangle::CreateShape(const std::vector<int>& params)
{
	return std::make_unique<CTriangle>(CPoint(params[0], params[1]), CPoint(params[2], params[3]), CPoint(params[4], params[5]));
}

CCreateTriangle::CCreateTriangle() {}

CCreateTriangle::~CCreateTriangle() {}
