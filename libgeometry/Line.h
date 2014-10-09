#pragma once

#include "ILine.h"

namespace geometry
{
	class Line :
		public geometry::ILine
	{
		double _x;
		double _y;
		double _z;
		double _m;
		double _n;
		double _p;
	public:
		Line();
		Line(Line& l);
		Line(Line&& l);
		~Line();
		virtual double x();
		virtual ILine* x(double value);
		virtual double y();
		virtual ILine* y(double value);
		virtual double z();
		virtual ILine* z(double value);
		virtual double m();
		virtual ILine* m(double value);
		virtual double n();
		virtual ILine* n(double value);
		virtual double p();
		virtual ILine* p(double value);
		virtual void Release();
	};
}

