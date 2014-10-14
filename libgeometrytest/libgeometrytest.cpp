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

auto megadeleter = [](){

};

typedef std::shared_ptr<geometry::IFactory> Factory;
#define FactoryC(name,ctor) Factory name(ctor, &::Kill)
typedef std::shared_ptr<geometry::IPoint> Point;
#define PointC(name,ctor) Point name(ctor, &::Kill)
typedef std::shared_ptr<geometry::ILine> Line;
#define LineC(name,ctor) Line name(ctor, &::Kill)

int main(int argc, char* argv[])
{
	Test::Silent = true;
	Test::PauseAfterTest = false;
	Test(
		"Creating factory",
		[]()
	{
		FactoryC(F, ::GetFactory());
		TestAssert(F.get() != nullptr);

		return true;
	});

	Test(
		"Creating point, filling with values",
		[]()
	{
		FactoryC(F, ::GetFactory());
		PointC(p, F->Point());
		TestAssert((p.get() != nullptr));
		p->x(12)->y(23)->z(34);
		TestAssert((p->x() == 12));
		TestAssert((p->y() == 23));
		TestAssert((p->z() == 34));

		return true;
	});

	Test(
		"Creating line from nothing",
		[]()
	{
		FactoryC(F, ::GetFactory());
		LineC(l, F->Line());
		TestAssert((l.get() != nullptr));
		TestAssert((l->x() == 0));
		TestAssert((l->y() == 0));
		TestAssert((l->z() == 0));
		TestAssert((l->m() == 1));
		TestAssert((l->n() == 0));
		TestAssert((l->p() == 0));
		
		return true;
	});

	Test(
		"Creating line from two points",
		[]()
	{
		FactoryC(F, ::GetFactory());
		PointC(p1, F->Point());
		PointC(p2, F->Point());
		TestAssert((p1.get() != nullptr));
		TestAssert((p2.get() != nullptr));
		p1->x(12)->y(23)->z(34);
		p2->x(21)->y(32)->z(43);
		LineC(l, F->LineBy2Points(p1.get(), p2.get()));
		TestAssert((l.get() != nullptr));
		TestAssert((l->x() == 12));
		TestAssert((l->y() == 23));
		TestAssert((l->z() == 34));
		TestAssert((l->m() == 9));
		TestAssert((l->n() == 9));
		TestAssert((l->p() == 9));

		return true;
	});

	Test(
		"Creating line from two matching points",
		[]()
	{
		FactoryC(F, ::GetFactory());
		PointC(p1, F->Point());
		PointC(p2, F->Point());
		TestAssert((p1.get() != nullptr));
		TestAssert((p2.get() != nullptr));
		p1->x(12)->y(23)->z(34);
		p2->x(12)->y(23)->z(34);
		LineC(l, F->LineBy2Points(p1.get(), p2.get()));
		TestAssert((l==nullptr));

		return true;
	});

	Test::Report();
	system("pause");
	return 0;
}

