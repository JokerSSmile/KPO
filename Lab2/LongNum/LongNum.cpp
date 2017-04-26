#include "stdafx.h"
#include "LongLongLong.h"

std::string GetResult(const std::string& first, const std::string& op, const std::string& second)
{
	LongLongLong result;
	if (op == "-")
	{
		result = LongLongLong(first) - LongLongLong(second);
	}
	else if (op == "+")
	{
		result = LongLongLong(first) + LongLongLong(second);
	}
	else if (op == "*")
	{
		result = LongLongLong(first) * LongLongLong(second);
	}
	else if (op == "/")
	{
		result = LongLongLong(first) / LongLongLong(second);
	}
	std::stringstream os;
	std::vector<int> number = result.GetNumber();
	std::copy(number.begin(), number.end(), std::ostream_iterator<int>(os, ""));

	return os.str();
}

void PerformWithFile(const std::string& filename)
{
	std::ifstream fin(filename);
	std::ofstream fout("output.txt");

	while (!fin.eof())
	{
		std::string first;
		std::string op;
		std::string second;
		fin >> first;
		fin >> op;
		fin >> second;
		std::string result = GetResult(first, op, second);
		fout << first << " " << op << " " << second << " = " << result << std::endl;
	}
}

int main()
{
	PerformWithFile("input.txt");
    return 0;
}

