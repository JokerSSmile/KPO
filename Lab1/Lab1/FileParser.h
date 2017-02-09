#pragma once
#include "Shape.h"

class CFileParser
{
public:
	CFileParser(const std::string& fileName);
	~CFileParser() = default;

	void Parse();
	void ParseLine(const std::string& line);
	void OutputInfo() const;

private:
	std::string m_fileName;
	std::vector<std::shared_ptr<IShape>> m_shapes;
};

