#pragma once
class LongLongLong
{
public:
	LongLongLong();
	LongLongLong(const std::string& value);
	LongLongLong(const std::vector<short>& value);
	~LongLongLong() = default;

	friend const LongLongLong operator+(const LongLongLong& left, const LongLongLong& right);
	friend const LongLongLong operator-(const LongLongLong& left, const LongLongLong& right);
	friend const LongLongLong operator*(const LongLongLong& left, const LongLongLong& right);
	friend const LongLongLong operator/(const LongLongLong& left, const LongLongLong& right);
	friend std::ostream& operator<<(std::ostream& os, const LongLongLong& number);

private:
	std::vector<short> StringToVector(const std::string& value);

private:
	std::vector<short> m_reversedValue;
	bool isPositive = true;
};
