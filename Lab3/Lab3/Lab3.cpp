// Lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ShapePerformer.h"


int main()
{
	ShapePerformer parser("input.txt");
	parser.ParseFile();
}

