#include "point.h"

using namespace std;

point::point(float x, float y, int R, int G, int B):shape(x,y,R,G,B){
	this->x = x;
	this->y = y;
	this->RED = R;
	this->GREEN = G;
	this->BLUE = B;
}

point::point(const point& from):shape(from){}

point::~point(){}

//TODO: Figure this out
void draw(GraphicsContext* GC){
	GC->setColor(0);
	GC->setPixel(this->x, this->y);
}

//no need to do in or out, they should be the same

//need to figure this out
void clone(const point& from){
}
