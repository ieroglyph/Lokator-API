#include "geometry.h"

#include "Point.h"

LIBGEOMETRY_API CreatePoint(geometry::IPoint* p)
{
	p = new geometry::Point();
	return 0;
}
