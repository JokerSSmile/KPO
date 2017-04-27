#include "stdafx.h"
#include "Reactangle.h"

CRectangle::CRectangle(const CPoint& leftUp, const CPoint& rightDown)
	: m_leftUp(leftUp)
	, m_rightDown(rightDown)
{
	m_width = std::abs(m_rightDown.GetX() - m_leftUp.GetX());
	m_height = std::abs(m_leftUp.GetY() - m_rightDown.GetY());
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return m_width * 2 + m_height * 2;
}
