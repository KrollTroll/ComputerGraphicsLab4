#ifndef POINT_H
#define POINT_H

#include "shape.h"

class point : public shape{
public:
	point(float x, float y, int R, int G, int B);
	point(const point& from);
	~point();
};
#endif
