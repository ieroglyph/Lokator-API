#pragma once

#include "IPoint.h"

#define LIBGEOMETRYRESULT unsigned int

#ifdef LIBGEOMETRY_EXPORTS
#    define LIBGEOMETRY_API __declspec(dllexport) LIBGEOMETRYRESULT
#else
#    define LIBGEOMETRY_API __declspec(dllimport) LIBGEOMETRYRESULT
#endif

extern "C"
{
	LIBGEOMETRY_API CreatePoint(geometry::IPoint* p);
}

