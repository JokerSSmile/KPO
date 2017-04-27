#include "stdafx.h"
#include "CreateRectangle.h"

CCreateRectangle & CCreateRectangle::GetInstance()
{
	static CCreateRectangle instance;
	return instance;
}

std::unique_ptr<IShape> CCreateRectangle::CreateShape(const std::vector<LongLongLong>& params)
{
	return std::make_unique<CRectangle>(CPoint(params[0].GetNumber(), params[1].GetNumber()), CPoint(params[2].GetNumber(), params[3].GetNumber()));
}

CCreateRectangle::CCreateRectangle() {}

CCreateRectangle::~CCreateRectangle() {}
