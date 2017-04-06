#pragma once

const int BASE = 1000000000;

class LongLongLong
{
public:
	LongLongLong();
	LongLongLong(const std::string& value);
	LongLongLong(const std::vector<int>& value);
	~LongLongLong() = default;

	int NumberLength() const;
	int VecSize() const;

	friend const LongLongLong operator+(const LongLongLong& left, const LongLongLong& right);
	friend const LongLongLong operator-(const LongLongLong& left, const LongLongLong& right);
	friend const LongLongLong operator*(const LongLongLong& left, const LongLongLong& right);
	friend const LongLongLong operator/(const LongLongLong& left, const LongLongLong& right);
	friend const bool operator>(const LongLongLong& left, const LongLongLong& right);
	friend std::ostream& operator<<(std::ostream& os, const LongLongLong& number);

private:
	std::vector<int> StringToVector(const std::string& value);

public:
	bool isPositive = true;

private:
	std::vector<int> m_reversedValue;
};

