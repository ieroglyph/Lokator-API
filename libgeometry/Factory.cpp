#include "Factory.h"
#include "Point.h"
#include "Line.h"

namespace geometry
{
	Factory::Factory()
	{

	}

	Factory::~Factory()
	{

	}

	void Factory::Release()
	{
		delete this;
	}

	IPoint* Factory::Point()
	{
		
		IPoint* p = new geometry::Point();
		return p;
	}

	ILine* Factory::Line()
	{
		ILine* l = new geometry::Line();
		return l;
	}

	ILine* Factory::LineBy2Points(IPoint* p1, IPoint* p2)
	{
		ILine* l = new geometry::Line();
		l
			->x(p1->x())
			->y(p1->y())
			->z(p1->z());
		l
			->m(p2->x() - p1->x())
			->n(p2->y() - p1->y())
			->p(p2->z() - p1->z());
		return l;
	}

}

