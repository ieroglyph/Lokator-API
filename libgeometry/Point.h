#pragma once

#include "IPoint.h"

namespace geometry
{
	class Point : public IPoint
	{
		double _x;
		double _y;
		double _z;
	public:
		Point();
		Point(Point& p);
		Point(Point&& p);
		Point(double x, double y, double z);
		~Point();
		virtual double x();
		virtual Point& x(double value);
		virtual double y();
		virtual Point& y(double value);
		virtual double z();
		virtual Point& z(double value);
	};
}
