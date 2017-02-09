#include "stdafx.h"
#include "Reactangle.h"

CReactangle::CReactangle(const CPoint& leftUp, const CPoint& rightDown)
	: m_leftUp(leftUp)
	, m_rightDown(rightDown)
{
	m_width = std::abs(m_rightDown.GetX() - m_leftUp.GetX());
	m_height = std::abs(m_leftUp.GetY() - m_rightDown.GetY());
}

double CReactangle::GetArea() const
{
	return m_width * m_height;
}

double CReactangle::GetPerimeter() const
{
	return m_width * 2 + m_height * 2;
}
