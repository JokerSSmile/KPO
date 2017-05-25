#include "stdafx.h"
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Reactangle.h"

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

void ShapeInfoVisitor::Visit(CPoint* point)
{
	std::cout << "Point" << std::endl;
}

void ShapeInfoVisitor::Visit(CLineSegment* point)
{
	std::cout << "Line" << std::endl;
}