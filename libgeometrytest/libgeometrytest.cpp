// libgeometrytest.cpp : Defines the entry point for the console application.
//
#include "libgeometry.h"
#pragma comment(lib,"libgeometry.lib")

#include <windows.h>
#include <memory>
#include <functional>
#include <iostream>
#include <string>

#include "Test.h"

typedef std::shared_ptr<geometry::IFactory> Factory;
#define FactoryC(name,ctor) Factory name(ctor, std::mem_fn(&geometry::IFactory::Release))
typedef std::shared_ptr<geometry::IPoint> Point;
#define PointC(name,ctor) Point name(ctor, std::mem_fn(&geometry::IPoint::Release))
typedef std::shared_ptr<geometry::ILine> Line;
#define LineC(name,ctor) Line name(ctor, std::mem_fn(&geometry::ILine::Release))

std::string testname;
unsigned int testn = 0;
bool teststate;

#define TEST_BEGIN(name) testname = name; \
	std::cout << "Running test " << testn << ": " << testname << std::endl;
#define TEST_END()

int main(int argc, char* argv[])
{

	Test(
		"Creating factory",
		[]()
	{
		FactoryC(F, ::GetFactory());
		return (F.get() != nullptr);
	});

	Test(
		"Creating point, filling with values",
		[]()
	{
		FactoryC(F, ::GetFactory());
		PointC(p, F->Point());
		p->x(12)->y(23)->z(34);
		return ((p->x()==12)&&(p->y()==23)&&(p->z()==34));
	});

	Test(
		"Creating line from nothing",
		[]()
	{
		FactoryC(F, ::GetFactory());
		LineC(l, F->Line());
		return ((l->x() == 0) && (l->y() == 0) && (l->m() == 1));
	});

	Test(
		"Creating line from two points",
		[]()
	{
		FactoryC(F, ::GetFactory());
		PointC(p1, F->Point());
		PointC(p2, F->Point());
		p1->x(12)->y(23)->z(34);
		p2->x(21)->y(32)->z(43);
		LineC(l, F->LineBy2Points(p1.get(),p2.get()));
		return ((l->x() == 12) && (l->z() == 34) && (l->m() == 9));
	});

	Test::Report();
	system("pause");
	return 0;
}

