#pragma once

class LongLongLong
{
public:
	LongLongLong();
	LongLongLong(const std::vector<int>& numberVec);
	LongLongLong(const std::string& numberStr);
	~LongLongLong() = default;

	std::vector<int> GetNumber() const;
	void operator=(const LongLongLong& a);

	void SetSign(bool minus);
	bool GetSign() const;
	int GetDigit(int i) const;
	size_t GetSize() const;

private:
	void SkipZeros();

	std::vector<int> m_number;
	bool m_isMinus = false;
};

bool const operator>(const LongLongLong& left, const LongLongLong& right);
bool const operator>=(const LongLongLong& left, const LongLongLong& right);
bool const operator<(const LongLongLong& left, const LongLongLong& right);
bool const operator<=(const LongLongLong& left, const LongLongLong& right);
bool const operator==(const LongLongLong& left, const LongLongLong& right);

LongLongLong const operator*(const LongLongLong& left, const LongLongLong& right);
LongLongLong const operator+(const LongLongLong& left, const LongLongLong& right);
LongLongLong const operator-(const LongLongLong& left, const LongLongLong& right);
LongLongLong const operator/(const LongLongLong& left, const LongLongLong& right);
std::ostream& operator<<(std::ostream& os, const LongLongLong& number);

LongLongLong Abs(const LongLongLong& left);
LongLongLong Pow(const LongLongLong& left, int right);
LongLongLong Sqrt(const LongLongLong& left);
LongLongLong DivideByTwo(const LongLongLong& left);