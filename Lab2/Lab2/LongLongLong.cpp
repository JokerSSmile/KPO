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

LongLongLong::LongLongLong(const std::vector<int>& value)
	: m_reversedValue(value)
{

}

std::vector<int> LongLongLong::StringToVector(const std::string& value)
{
	std::vector<int> result;

	try
	{
		for (int i = (int)value.length(); i > 0; i -= 9)
		{
			if (i < 9)
			{
				result.push_back(atoi(value.substr(0, i).c_str()));
			}
			else
			{
				result.push_back(atoi(value.substr(i - 9, 9).c_str()));
			}
		}
	}
	catch (const std::invalid_argument&)
	{
		throw std::runtime_error("Invalid symbol in input");
	}

	return result;
}

int LongLongLong::NumberLength() const
{
	int length = 0;
	std::for_each(m_reversedValue.begin(), m_reversedValue.end(), [&length](int num) { length += std::to_string(num).length(); });
	return length;
}

int LongLongLong::VecSize() const
{
	return m_reversedValue.size();
}

const LongLongLong operator+(const LongLongLong& left, const LongLongLong& right) {

	LongLongLong result(left);

	int carry = 0;
	for (size_t i = 0; i < std::max(result.VecSize(), right.VecSize()) || carry; ++i) 
	{
		if (i == result.VecSize())
		{
			result.m_reversedValue.push_back(0);
		}
		result.m_reversedValue[i] += carry + (i < right.VecSize() ? right.m_reversedValue[i] : 0);
		carry = result.m_reversedValue[i] >= BASE;
		if (carry)
		{
			result.m_reversedValue[i] -= BASE;
		}
	}

	return result;
}


const LongLongLong operator-(const LongLongLong& left, const LongLongLong& right) {

	LongLongLong bigger;
	LongLongLong lower;
	
	if (right > left)
	{
		bigger = right;
		lower = left;
		bigger.isPositive = false;
	}
	else
	{
		bigger = left;
		lower = right;
	}

	int carry = 0;
	for (size_t i = 0; i < lower.VecSize() || carry; ++i) 
	{
		bigger.m_reversedValue[i] -= carry + (i < lower.NumberLength() ? lower.m_reversedValue[i] : 0);
		carry = bigger.m_reversedValue[i] < 0;
		if (carry)
		{
			bigger.m_reversedValue[i] += BASE;
		}
	}
	while (bigger.NumberLength() > 1 && bigger.m_reversedValue.back() == 0)
	{
		bigger.m_reversedValue.pop_back();
	}

	return bigger;
}


const LongLongLong operator*(const LongLongLong& left, const LongLongLong& right) {

	LongLongLong bigger;
	LongLongLong lower;
	LongLongLong result;

	if (right > left)
	{
		bigger = right;
		lower = left;
	}
	else
	{
		bigger = left;
		lower = right;
	}
	
	result.m_reversedValue.resize(bigger.VecSize() + lower.VecSize());
	for (size_t i = 0; i < left.VecSize(); ++i)
	{
		for (int j = 0, carry = 0; j < (int)right.VecSize() || carry; ++j)
		{
			long long cur = result.m_reversedValue[i + j] + left.m_reversedValue[i] * 1ll * (j < (int)right.VecSize() ? right.m_reversedValue[j] : 0) + carry;//
			result.m_reversedValue[i + j] = int(cur % BASE);
			carry = int(cur / BASE);
		}
	}
	while (result.VecSize() > 1 && result.m_reversedValue.back() == 0)
	{
		result.m_reversedValue.pop_back();
	}

	return result;
}


const LongLongLong operator/(const LongLongLong& left, const LongLongLong& right) {

// 	LongLongLong norm(std::to_string(BASE / (right.m_reversedValue.back() + 1)));
// 	LongLongLong a = left * norm;
// 	LongLongLong b = right * norm;
// 	LongLongLong q, r;
// 	q.m_reversedValue.resize(a.VecSize());
// 	for(long long i = a.VecSize() - 1; i >= 0; --i) {
// 	r *= BASE;
// 	r += a.a[i];
// 	long long s1 = sz(r.a) <= sz(b.a) ? 0 : r.a[sz(b.a)];
// 	long long s2 = sz(r.a) <= sz(b.a) - 1 ? 0 : r.a[sz(b.a) - 1];
// 	long long d = ((ll)base * s1 + s2) / b.a.back();
// 	r -= b * d;
// 	while(r < 0) {
// 	r += b;
// 	--d;
// 	}
// 	q.a[i] = d;
// 	}
// 	q.sign = left.sign * right.sign;
// 	r.sign = left.sign;
// 	q.trim();
// 	r.trim();
// 	return {q, r / norm};
}


bool const operator>(const LongLongLong & left, const LongLongLong & right)
{
	if (left.m_reversedValue.size() > right.m_reversedValue.size())
	{
		return true;
	}
	for (size_t i = 0; i < left.m_reversedValue.size(); i++)
	{
		if (right.m_reversedValue[i] > left.m_reversedValue[i])
		{
			return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const LongLongLong& number)
{
	for (auto value = number.m_reversedValue.rbegin(); value != number.m_reversedValue.rend(); value++)
	{
		os << *value;
	}

	return os;
}
