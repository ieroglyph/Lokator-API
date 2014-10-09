#pragma once

#include "IPoint.h"

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif


EXTERN_C LIBGEOMETRY_API geometry::IPoint* __stdcall CreatePoint();