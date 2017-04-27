#include "stdafx.h"
#include "ShapePerformer.h"

ShapePerformer::ShapePerformer(const std::string & fileName)
	: m_fileName(fileName)
	, m_fout("output.txt")
{
}

void ShapePerformer::ParseFile()
{
	std::ifstream inFile(m_fileName);
	for (std::string line; std::getline(inFile, line);)
	{
		ParseLine(line);
	}
}

void ShapePerformer::ParseLine(const std::string& line)
{
	std::unique_ptr<IShape> shape = nullptr;
	std::stringstream stream(line);
	std::vector<std::string> splittedString
	{
		std::istream_iterator<std::string>(stream),{}
	};
	std::string figureType = splittedString[0];
	std::vector<LongLongLong> params(splittedString.size() - 1);
	std::copy(splittedString.begin() + 1, splittedString.end(), params.begin());

	if (figureType == "RECTANGLE")
	{
		shape = CCreateRectangle::GetInstance().CreateShape(params);
	}
	else if (figureType == "TRIANGLE")
	{
		shape = CCreateTriangle::GetInstance().CreateShape(params);
	}
	else if (figureType == "CIRCLE")
	{
		shape = CCreateCircle::GetInstance().CreateShape(params);
	}
	OutputInfo(shape, figureType);
}

void ShapePerformer::OutputInfo(const std::unique_ptr<IShape>& shape, const std::string& shapeType)
{
	m_fout << shapeType << ": P=" << shape->GetPerimeter() << " S=" << shape->GetArea() << std::endl;
}
