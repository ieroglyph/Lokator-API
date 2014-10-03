#pragma once

namespace geometry
{
	class IPoint
	{
	public:
		virtual double x() = 0;
		virtual IPoint& x(double value) = 0;
		virtual double y() = 0;
		virtual IPoint& y(double value) = 0;
		virtual double z() = 0;
		virtual IPoint& z(double value) = 0;
	};
}