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
		virtual IPoint* x(double value);
		virtual double y();
		virtual IPoint* y(double value);
		virtual double z();
		virtual IPoint* z(double value);
		virtual void Release();
	};
}