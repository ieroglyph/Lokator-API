#pragma once

#ifdef LIBGEOMETRY_EXPORTS
#    define LIBGEOMETRY_API __declspec(dllexport)
#else
#    define LIBGEOMETRY_API __declspec(dllimport)
#endif

namespace geometry
{
	class Interface
	{
	public:
		virtual void Release() = 0;
	};
}
