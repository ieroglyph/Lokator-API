#include "Line.h"

namespace geometry
{


	Line::Line() :
		_x(0), _y(0), _z(0), _m(1), _n(0), _p(0)
	{

	}

	Line::Line(Line& l) :
		_x(l._x), _y(l._y), _z(l._z), _m(l._m), _n(l._n), _p(l._p)
	{

	}

	Line::Line(Line&& l) :
		_x(l._x), _y(l._y), _z(l._z), _m(l._m), _n(l._n), _p(l._p)
	{

	}

	Line::~Line()
	{

	}

	void Line::Release()
	{
		delete this;
	}

#define ImplGet(name) double Line::name() \
	{ \
	return this->_##name; \
	} 

#define ImplSet(name) ILine* Line::name(double value) \
	{ \
	this->_##name = value; \
	return this; \
	} 
#define ImplGetSet(name) ImplGet(name); \
	ImplSet(name);

	ImplGetSet(x);
	ImplGetSet(y);
	ImplGetSet(z);
	ImplGetSet(m);
	ImplGetSet(n);
	ImplGetSet(p);

}