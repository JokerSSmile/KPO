#include "stdafx.h"
#include "ShapeInfoVisitor.h"

void ShapeInfoVisitor::Visit(CCircle* circle)
{
	std::cout << "CIRCLE: S=" << circle->GetArea() << " P=" << circle->GetPerimeter() << std::endl;
}

void ShapeInfoVisitor::Visit(CRectangle* rectangle)
{
	std::cout << "RECTANGLE: S=" << rectangle->GetArea() << " P=" << rectangle->GetPerimeter() << std::endl;
}

void ShapeInfoVisitor::Visit(CTriangle* triangle)
{
	std::cout << "TRIANGLE: S=" << triangle->GetArea() << " P=" << triangle->GetPerimeter() << std::endl;
}
