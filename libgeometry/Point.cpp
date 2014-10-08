#include "Point.h"

namespace geometry
{
	Point::Point() :
		_x(0), _y(0), _z(0)
	{
	}

	Point::Point(double x, double y, double z) :
		_x(x), _y(y), _z(z)
	{
	}

	Point::Point(Point& p) :
		_x(p._x), _y(p._y), _z(p._z)
	{

	}

	Point::Point(Point&& p) :
		_x(p._x), _y(p._y), _z(p._z)
	{

	}
	Point::~Point()
	{
	}

	double Point::x()
	{
		return _x;
	}

	IPoint* Point::x(double value)
	{
		_x = value;
		return this;
	}

	double Point::y()
	{
		return _y;
	}

	IPoint* Point::y(double value)
	{
		_y = value;
		return this;
	}

	double Point::z()
	{
		return _z;
	}

	IPoint* Point::z(double value)
	{
		_z = value;
		return this;
	}

	void Point::Release()
	{
		delete this;
	}
}
