#include "libgeometry.h"

#include "Point.h"

 #if !defined(_WIN64)
 // This pragma is required only for 32-bit builds. In a 64-bit environment,
 // C functions are not decorated.
 #pragma comment(linker, "/export:CreatePoint=_CreatePoint@0")
 #endif  // _WIN64

LIBGEOMETRY_API geometry::IPoint* __stdcall CreatePoint()
{
	geometry::IPoint* p = new geometry::Point();
	return p;
}