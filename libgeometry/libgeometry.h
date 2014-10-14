#pragma once

#include "IFactory.h"

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif


EXTERN_C LIBGEOMETRY_API geometry::IFactory* __stdcall GetFactory();
EXTERN_C LIBGEOMETRY_API int __stdcall Kill(geometry::Interface* him);