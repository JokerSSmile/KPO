#pragma once
#include "Visitor.h"

class ShapeInfoVisitor : public CVisitor
{
public:
	ShapeInfoVisitor() = default;
	~ShapeInfoVisitor() = default;

	void Visit(CCircle* circle);
	void Visit(CRectangle* rectangle);
	void Visit(CTriangle* triangle);
};

