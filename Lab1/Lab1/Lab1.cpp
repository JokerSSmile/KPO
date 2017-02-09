#include "stdafx.h"
#include "Reactangle.h"
#include "Circle.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "FileParser.h"

using namespace std;

int main()
{
	CFileParser parser("input.txt");
	parser.Parse();
	parser.OutputInfo();

    return 0;
}
