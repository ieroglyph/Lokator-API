#pragma once

#include "Interface.h"
#include "IPoint.h"

namespace geometry
{
	class ISegment
	{
	public:
		virtual void GetPoint1(IPoint* point) = 0;
		virtual void SetPoint1(IPoint* point) = 0;
		virtual void GetPoint2(IPoint* point) = 0;
		virtual void SetPoint2(IPoint* point) = 0;
		virtual void GetDimensions(IPoint* point) = 0;
	};
}