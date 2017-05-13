#include "stdafx.h"
#include "CreateTriangle.h"

CCreateTriangle & CCreateTriangle::GetInstance()
{
	static CCreateTriangle instance;
	return instance;
}

std::unique_ptr<IShape> CCreateTriangle::CreateShape(const std::vector<LongLongLong>& params)
{
	return std::make_unique<CTriangle>(CPoint(params[0].GetNumber(), params[1].GetNumber()), CPoint(params[2].GetNumber(), params[3].GetNumber()), CPoint(params[4].GetNumber(), params[5].GetNumber()));
}

CCreateTriangle::CCreateTriangle() {}

CCreateTriangle::~CCreateTriangle() {}
