#include "libgeometry.h"

#include "Factory.h"

 #if !defined(_WIN64)
 // This pragma is required only for 32-bit builds. In a 64-bit environment,
 // C functions are not decorated.
#pragma comment(linker, "/export:GetFactory=_GetFactory@0")
 #endif  // _WIN64

//#if !defined(_WIN64)
//#pragma comment(linker, "/export:Kill=_Kill@0")
//#endif  // _WIN64

LIBGEOMETRY_API geometry::IFactory* __stdcall GetFactory()
{
	return new geometry::Factory();
}


LIBGEOMETRY_API int __stdcall Kill(geometry::Interface* him)
{
	if (him != nullptr)
	{
		delete him;
	}
	return 0;
}