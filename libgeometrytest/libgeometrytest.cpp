// libgeometrytest.cpp : Defines the entry point for the console application.
//
#include "libgeometry.h"
#pragma comment(lib,"libgeometry.lib")

#include <windows.h>
#include <memory>
#include <functional>
#include <iostream>

typedef std::shared_ptr<geometry::IPoint> Point;

int main(int argc, char* argv[])
{
	Point p1(::CreatePoint(), std::mem_fn(&geometry::IPoint::Release));
	p1->x(12)->y(23)->z(34);

	std::cout << p1->x() << " " << p1->y() << " " << p1->z() << std::endl;
	system("pause");
	return 0;
}

