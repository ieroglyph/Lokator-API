#pragma once

#include "Interface.h"

namespace geometry
{
	class ILine : public Interface
	{
	public:
		virtual double x() = 0;
		virtual ILine* x(double value) = 0;
		virtual double y() = 0;
		virtual ILine* y(double value) = 0;
		virtual double z() = 0;
		virtual ILine* z(double value) = 0;
		virtual double m() = 0;
		virtual ILine* m(double value) = 0;
		virtual double n() = 0;
		virtual ILine* n(double value) = 0;
		virtual double p() = 0;
		virtual ILine* p(double value) = 0;
	};
}