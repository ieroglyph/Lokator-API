// libgeometrytest.cpp : Defines the entry point for the console application.
//
#include "libgeometry.h"
#pragma comment(lib,"libgeometry.lib")

#include <windows.h>
#include <memory>
#include <functional>
#include <iostream>

typedef std::shared_ptr<geometry::IFactory> Factory;
typedef std::shared_ptr<geometry::IPoint> Point;
typedef std::shared_ptr<geometry::ILine> Line;

int main(int argc, char* argv[])
{
	Factory F(::GetFactory(), std::mem_fn(&geometry::IFactory::Release));
	Point p1(F->Point(), std::mem_fn(&geometry::IPoint::Release));
	Point p2(F->Point(), std::mem_fn(&geometry::IPoint::Release));
	p1
		->x(12)
		->y(23)
		->z(34);
	p2
		->x(21)
		->y(32)
		->z(43);
	std::cout << 
		p1->x() << " " << 
		p1->y() << " " << 
		p1->z() << std::endl;
	std::cout << 
		p2->x() << " " << 
		p2->y() << " " << 
		p2->z() << std::endl;
	Line l1(F->Line(), std::mem_fn(&geometry::ILine::Release));
	Line l2(F->LineBy2Points(p1.get(), p2.get()), std::mem_fn(&geometry::ILine::Release));
	std::cout <<
		l1->x() << " " <<
		l1->y() << " " <<
		l1->z() << " " <<
		l1->m() << " " <<
		l1->n() << " " <<
		l1->p() << std::endl;
	std::cout <<
		l2->x() << " " <<
		l2->y() << " " <<
		l2->z() << " " <<
		l2->m() << " " <<
		l2->n() << " " <<
		l2->p() << std::endl;
	system("pause");
	return 0;
}

