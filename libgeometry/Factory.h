#pragma once
#include "IFactory.h"

namespace geometry
{
	class Factory :
		public geometry::IFactory
	{
	public:
		Factory();
		~Factory();

		virtual IPoint* Point();
		virtual ILine* Line();
		virtual ILine* LineBy2Points(IPoint* p1, IPoint* p2);
		virtual void Release();
	};
}