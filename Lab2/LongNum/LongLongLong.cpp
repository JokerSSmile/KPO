#include "stdafx.h"
#include "LongLongLong.h"

LongLongLong::LongLongLong()
{
}

LongLongLong::LongLongLong(const std::string& numberStr)
{
	if (numberStr[0] == '-')
	{
		m_isMinus = true;
	}
	else
	{
		m_number.push_back(int(numberStr[0]) - int('0'));
	}

	for (size_t i = 1; i < numberStr.length(); ++i)
	{
		m_number.push_back(int(numberStr[i]) - int('0'));
	}
	if (m_number.size() != 1)
	{
		SkipZeros();
	}
}

LongLongLong::LongLongLong(const std::vector<int>& numberVec)
{
	for (auto it : numberVec)
	{
		m_number.push_back(it);
	}
	if (m_number.size() != 1)
	{
		SkipZeros();
	}
}

void LongLongLong::SetSign(bool minus)
{
	m_isMinus = minus;
}

bool LongLongLong::GetSign() const
{
	return m_isMinus;
}


int LongLongLong::GetDigit(int i) const
{
	return m_number[i];
}

size_t LongLongLong::GetSize() const
{
	return m_number.size();
}

std::vector<int> LongLongLong::GetNumber() const
{
	return m_number;
}

void LongLongLong::operator=(const LongLongLong& right)
{
	m_isMinus = right.GetSign();
	m_number.clear();
	for (size_t i = 0; i < right.GetSize(); i++)
	{
		m_number.push_back(right.GetDigit(i));
	}
}

void LongLongLong::SkipZeros()
{
	bool zer = true;
	for (size_t i = 0; i < m_number.size(); i++)
	{
		if (zer && (m_number[i] == 0))
		{
			m_number.erase(m_number.begin());
			i--;
		}
		else
		{
			zer = false;
		}
	}
}

bool const operator>(const LongLongLong& left, const LongLongLong& right)
{
	if (left.GetSize() > right.GetSize())
	{
		return true;
	}
	else if (left.GetSize() < right.GetSize())
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < left.GetSize(); i++)
		{
			if (left.GetDigit(i) > right.GetDigit(i))
			{
				return true;
			}
			else if (left.GetDigit(i) < right.GetDigit(i))
			{
				return false;
			}
		}
	}
	return false;
}

bool const operator>=(const LongLongLong& left, const LongLongLong& right)
{
	if (left.GetSize() > right.GetSize())
	{
		return true;
	}
	else if (left.GetSize() < right.GetSize())
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < left.GetSize(); i++)
		{
			if (left.GetDigit(i) > right.GetDigit(i))
			{
				return true;
			}
			else if (left.GetDigit(i) < right.GetDigit(i))
			{
				return false;
			}
		}
	}
	return true;
}

bool const operator<(const LongLongLong& left, const LongLongLong& right)
{
	return (!(left >= right));
}

bool const operator<=(const LongLongLong& left, const LongLongLong& right)
{
	return ((left < right) || (!(left > right) && !(left < right)));
}

bool const operator==(const LongLongLong& left, const LongLongLong& right)
{
	return (!(left > right) && !(left < right));
}

LongLongLong const operator*(const LongLongLong& left, const LongLongLong& right)
{
	std::vector<int> tempNum;
	tempNum.push_back(0);
	LongLongLong result(tempNum);

	int rightSize = right.GetSize() - 1;
	int leftSize = left.GetSize() - 1;

	int number = 0;
	int addNumber = 0;
	std::vector<int> longNum;
	for (int i = leftSize; i >= 0; i--)
	{
		bool large = false;
		longNum.clear();
		for (int j = rightSize; j >= 0; j--)
		{
			number = number / 10 + left.GetDigit(i) * right.GetDigit(j);
			large = false;
			if (number > 9)
			{
				large = true;
			}
			longNum.insert(longNum.begin(), number % 10);
		}
		if (large)
		{
			longNum.insert(longNum.begin(), number / 10);
		}

		for (int numZero = 0; numZero < leftSize - i; numZero++)
		{
			longNum.push_back(0);
		}

		LongLongLong addLongNum(longNum);
		result = result + addLongNum;
		number = 0;
	}

	return result;
}

LongLongLong const operator+(const LongLongLong& left, const LongLongLong& right)
{
	std::vector<int> result;
	int rightSize = right.GetSize() - 1;
	int leftSize = left.GetSize() - 1;

	int number = 0;
	int addNumber = 0;
	for (int i = std::max(leftSize, rightSize); i >= 0; i--)
	{
		if (leftSize >= 0 && rightSize >= 0)
		{
			number = addNumber + left.GetDigit(leftSize) + right.GetDigit(rightSize);
		}
		else if (rightSize >= 0)
		{
			number = addNumber + right.GetDigit(rightSize);
		}
		else if (leftSize >= 0)
		{
			number = addNumber + left.GetDigit(leftSize);
		}
		--leftSize;
		--rightSize;

		addNumber = number / 10;
		number = number % 10;

		result.insert(result.begin(), number);
		number = 0;
	}

	if (addNumber != 0)
	{
		result.insert(result.begin(), addNumber);
	}
	LongLongLong res(result);
	return res;
}

LongLongLong const operator-(const LongLongLong& left, const LongLongLong& right)
{
	LongLongLong tempLeft = left;
	LongLongLong tempRight = right;

	if (right > left)
	{
		tempLeft = right;
		tempRight = left;
	}
	std::vector<int> result;
	result.resize(tempLeft.GetSize());
	int rightSize = tempRight.GetSize() - 1;
	int leftSize = tempLeft.GetSize() - 1;


	for (size_t it = 0; it < tempLeft.GetNumber().size(); it++)
	{
		result[it] = tempLeft.GetNumber()[it];
	}
	while (rightSize >= 0)
	{
		int localCountA = leftSize - 1;
		if (result[leftSize] >= tempRight.GetDigit(rightSize))
		{
			result[leftSize] = result[leftSize] - tempRight.GetDigit(rightSize);
		}
		else
		{
			while (result[localCountA] == 0)
			{
				--localCountA;
			}
			if (result[localCountA] != 1)
			{
				result[localCountA] -= 1;
				int lCountA = localCountA + 1;
				while (tempLeft.GetDigit(lCountA) == 0)
				{
					result[lCountA] = 9;
					++lCountA;
				}
				result[leftSize] = result[leftSize] + 10 - tempRight.GetDigit(rightSize);
			}
			else
			{
				result[localCountA] = 0;
				while (localCountA != leftSize - 1)
				{
					++localCountA;
					result[leftSize] = 9;
				}
				result[leftSize] = result[leftSize] + 10 - tempRight.GetDigit(rightSize);
			}
		}
		--leftSize;
		--rightSize;
	}
	LongLongLong res(result);
	res.SetSign(left < right);
	return res;
}

LongLongLong const operator/(const LongLongLong& left, const LongLongLong& right)
{
	if (right.GetSize() == 1 && right.GetDigit(0) == 0)
	{
		throw std::logic_error("");
	}
	std::vector<int> result;
	if ((right.GetSize() == 1 && right.GetDigit(0) == 0) || left.GetSize() == 0)
	{
		result.clear();
	}
	else if (left == right)
	{
		result.push_back(1);
	}
	else if (left < right)
	{
		result.push_back(0);
	}
	else
	{
		int countB = right.GetSize() - 1;
		int countA = left.GetSize() - 1;
		int countNum = 0;

		std::vector<int> longNum;
		for (int i = 0; i <= countB; i++)
		{
			countNum++;
			longNum.push_back(left.GetDigit(i));
		}
		LongLongLong fNum(longNum);;


		if (fNum < right)
		{
			countNum++;
			longNum.push_back(left.GetDigit(countNum - 1));
		}

		fNum = LongLongLong(longNum);
		LongLongLong rNum = fNum - right;
		int num = 2;
		while (num < 10 && !rNum.GetSign())
		{
			std::vector<int> muv = { num };
			LongLongLong muvNum(muv);
			rNum = fNum - right * muvNum;
			num++;
		}
		if (rNum.GetSign())
		{
			num -= 2;
			std::vector<int> muv = { num };
			LongLongLong muvNum(muv);
			rNum = fNum - right * muvNum;
		}

		if (num == 10)
		{
			num--;
		}
		std::vector<int> modNum;

		for (int i = 0; i < rNum.GetSize(); i++)
		{
			modNum.push_back(rNum.GetDigit(i));
		}
		for (int i = countNum; i <= countA; i++)
		{
			modNum.push_back(left.GetDigit(i));
		}
		LongLongLong longMod(modNum);

		result.push_back(num);

		if (rNum.GetSize() == 0)
		{
			if (right.GetSize() > 1)
			{
				result.push_back(0);
			}
		}

		LongLongLong resDiv = longMod / right;
		if (resDiv.GetDigit(0) != 0)
		{
			for (int i = 0; i < resDiv.GetSize(); i++)
			{
				result.push_back(resDiv.GetDigit(i));
			}
		}
	}
	LongLongLong res(result);
	return res;
}

std::ostream & operator<<(std::ostream& os, const LongLongLong& left)
{
	if (left.GetSign())
	{
		os << "-";
	}
	for (auto it : left.GetNumber())
	{
		os << it;
	}

	return os;
}