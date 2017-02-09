#include "stdafx.h"
#include "FileParser.h"
#include "Reactangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Point.h"

CFileParser::CFileParser(const std::string & fileName)
	:m_fileName(fileName)
{

}

void CFileParser::Parse()
{
	std::ifstream inFile(m_fileName);
	for (std::string line; std::getline(inFile, line);)
	{
		ParseLine(line);
	}
}

void CFileParser::ParseLine(const std::string& line)
{
	std::stringstream stream(line);
	std::vector<std::string> splittedString
	{
		std::istream_iterator<std::string>(stream),{}
	};
	std::string figureType = splittedString[0];

	if (figureType == "RECTANGLE")
	{
		m_shapes.push_back(std::make_shared<CReactangle>(
			CPoint(std::stoi(splittedString[1]), std::stoi(splittedString[2])),
			CPoint(std::stoi(splittedString[3]), std::stoi(splittedString[4]))
			));
	}
	else if (figureType == "TRIANGLE")
	{
		m_shapes.push_back(std::make_shared<CTriangle>(
			CPoint(std::stoi(splittedString[1]), std::stoi(splittedString[2])),
			CPoint(std::stoi(splittedString[3]), std::stoi(splittedString[4])),
			CPoint(std::stoi(splittedString[5]), std::stoi(splittedString[6])))
			);
	}
	else if (figureType == "CIRCLE")
	{
		m_shapes.push_back(std::make_shared<CCircle>(
			CPoint(std::stoi(splittedString[1]), std::stoi(splittedString[2])),
			std::stoi(splittedString[3]))
			);
	}
}

void CFileParser::OutputInfo() const
{
	for (auto shape : m_shapes)
	{
		std::cout << "Area: " << shape->GetArea() << "\n" << "Perimeter: " << shape->GetPerimeter() << std::endl;
		std::cout << std::endl;
	}
}
