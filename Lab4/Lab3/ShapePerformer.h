#pragma once
#include "Shape.h"
#include "Reactangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Point.h"
#include "CreateCircle.h"
#include "CreateRectangle.h"
#include "CreateTriangle.h"

class ShapePerformer
{
public:
	ShapePerformer(const std::string& fileName);
	~ShapePerformer() = default;

	void ParseFile();
	void ParseLine(const std::string& line);
	void OutputInfo(const std::unique_ptr<IShape>& shape, const std::string& shapeType);

private:
	std::string m_fileName;
	std::ofstream m_fout;
};

