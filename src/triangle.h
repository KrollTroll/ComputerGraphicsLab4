#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class triangle : public shape{
public:
	triangle(float x, float y, int R, int G, int B, float x2, float y2, float x3, float y3);
	triangle(const triangle& from);
	~triangle();
	void draw(GraphicsContext* GC);

	float x2;
	float y2;
	float x3;
	float y3;
};
#endif
