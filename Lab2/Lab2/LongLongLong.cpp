#include "stdafx.h"
#include "LongLongLong.h"


LongLongLong::LongLongLong()
	: m_reversedValue()
{

}

LongLongLong::LongLongLong(const std::string& value)
	: m_reversedValue(StringToVector(value))
{

}

LongLongLong::LongLongLong(const std::vector<short>& value)
	: m_reversedValue(value)
{

}

std::vector<short> LongLongLong::StringToVector(const std::string& value)
{
	std::vector<short> vValue;

	try
	{
		for each (char num in value)
		{
			vValue.push_back(std::stoi(&num));
		}
		std::reverse(vValue.begin(), vValue.end());
	}
	catch (const std::invalid_argument&)
	{
		throw std::runtime_error("Invalid symbol in input");
	}

	return vValue;
}

const LongLongLong operator+(const LongLongLong& left, const LongLongLong& right) {
	
	int length;
	LongLongLong bigger;
	LongLongLong lower;
	if (right.m_reversedValue.size() > left.m_reversedValue.size())
	{
		bigger = right;
		lower = left;
	}
	else
	{
		bigger = left;
		lower = right;
	}


	length = bigger.m_reversedValue.size();
	lower.m_reversedValue.resize(length + 1);

	for (int i = 0; i < length; i++)
	{
		lower.m_reversedValue[i] += bigger.m_reversedValue[i];
		lower.m_reversedValue[i + 1] += (lower.m_reversedValue[i] / 10);
		lower.m_reversedValue[i] %= 10;
	}
	
	if (lower.m_reversedValue[length] == 0)
	{
		lower.m_reversedValue.pop_back();
	}

	return LongLongLong(lower);
}


const LongLongLong operator-(const LongLongLong& left, const LongLongLong& right) {

	LongLongLong bigger;
	LongLongLong lower;
	
	if (right.m_reversedValue.size() > left.m_reversedValue.size() && right.m_reversedValue.back() > left.m_reversedValue.back())
	{
		bigger = right;
		lower = left;
	}
	else
	{
		bigger = left;
		lower = right;
	}

	int carry = 0;
	for (size_t i = 0; i < lower.m_reversedValue.size() || carry; i++)
	{
		bigger.m_reversedValue[i] -= carry + (i < lower.m_reversedValue.size() ? lower.m_reversedValue[i] : 0);
		carry = bigger.m_reversedValue[i] < 0;
		if (carry)
		{
			bigger.m_reversedValue[i] += 1;
		}
	}

	while (bigger.m_reversedValue.size() > 1 && bigger.m_reversedValue.back() == 0)
	{
		bigger.m_reversedValue.pop_back();
	}

	return bigger;
}

/*
const LongLongLong operator*(const LongLongLong& left, const LongLongLong& right) {
	return LongLongLong(left.m_value * right.m_value);
}

const LongLongLong operator/(const LongLongLong& left, const LongLongLong& right) {
	return LongLongLong(left.m_value / right.m_value);
}
*/

std::ostream& operator<<(std::ostream& os, const LongLongLong& number)
{
	for (auto digit = number.m_reversedValue.rbegin(); digit != number.m_reversedValue.rend(); ++digit)
	{
		os << *digit;
	}

	return os;
}
