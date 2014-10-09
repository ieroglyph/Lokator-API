#pragma once

#include "IPoint.h"
#include "ILine.h"

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif


EXTERN_C LIBGEOMETRY_API geometry::IPoint* __stdcall CreatePoint();
EXTERN_C LIBGEOMETRY_API geometry::ILine* __stdcall CreateLine();