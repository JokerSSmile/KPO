// Lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ShapePerformer.h"
#include "LongLongLong.h"

int main()
{
	ShapePerformer parser("input.txt");
	parser.ParseFile();
	//std::cout << LongLongLong("22222222222222222222222222") / LongLongLong("10") << std::endl;
}

