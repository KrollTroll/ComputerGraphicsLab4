#ifndef LINE_H
#define LINE_H

#include "shape.h"

class line : public shape{
public:
	line(float x, float y, int R, int G, int B, float x2, float y2);
	line(const line& from);
	~line();
	void draw(GraphicsContext* GC);
	line& operator=(const line& from);
	std::ostream& out(std::ostream& os) const;

protected:
	float x2;
	float y2;
};

std::ostream& operator<<(std::ostream& os, const line& rhs);

#endif
