#pragma once
#include "Interface.h"
#include "IPoint.h"
#include "ILine.h"

namespace geometry
{
	class IFactory :
		public geometry::Interface
	{
	public:
		virtual IPoint* Point() = 0;
		virtual ILine* Line() = 0;
		virtual ILine* LineBy2Points(IPoint* p1, IPoint* p2) = 0;
	};
}
