#pragma once

class CPoint
{
public:
	CPoint(int x, int y);
	~CPoint() = default;

	int GetX() const;
	int GetY() const;

private:
	int m_x;
	int m_y;
};

