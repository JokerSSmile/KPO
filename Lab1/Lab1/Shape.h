#pragma once

class IShape
{
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual double GetPerimeter() const = 0;
	virtual double GetArea() const = 0;
};
