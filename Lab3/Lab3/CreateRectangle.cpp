#include "stdafx.h"
#include "CreateRectangle.h"

CCreateRectangle & CCreateRectangle::GetInstance()
{
	static CCreateRectangle instance;
	return instance;
}

std::unique_ptr<IShape> CCreateRectangle::CreateShape(const std::vector<int>& params)
{
	return std::make_unique<CRectangle>(CPoint(params[0], params[1]), CPoint(params[2], params[3]));
}

CCreateRectangle::CCreateRectangle() {}

CCreateRectangle::~CCreateRectangle() {}
