#include "stdafx.h"
#include "Reactangle.h"

CRectangle::CRectangle(const CPoint& leftUp, const CPoint& rightDown)
	: m_leftUp(leftUp)
	, m_rightDown(rightDown)
{
	m_width = Abs(m_rightDown.GetX() - m_leftUp.GetX());
	m_height = Abs(m_leftUp.GetY() - m_rightDown.GetY());
}

LongLongLong CRectangle::GetArea() const
{
	return m_width * m_height;
}

LongLongLong CRectangle::GetPerimeter() const
{
	return m_width * LongLongLong("2") + m_height * LongLongLong("2");
}

void CRectangle::Accept(CVisitor& visitor)
{
	visitor.Visit(this);
}
