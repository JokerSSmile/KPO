#pragma once
#include "Circle.h"
#include "Reactangle.h"
#include "Triangle.h"

class CVisitor
{
public:
	virtual void Visit(CCircle* circle) = 0;
	virtual void Visit(CRectangle* rectangle) = 0;
	virtual void Visit(CTriangle* triangle) = 0;
};