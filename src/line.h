#ifndef LINE_H
#define LINE_H

#include "shape.h"

class line : public shape{
public:
	line(float x, float y, int R, int G, int B, float x2, float y2,);
	line(const line& from);
	~line();
	line& operator=(const line& rhs);
};
#endif
