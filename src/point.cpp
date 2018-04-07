#include "point.h"

using namespace std;

point::point(float x, float y, int R, int G, int B):shape(x,y,R,G,B){}

point::point(const point& from):shape(from){}

point::~point(){
	//there is nothing to free right now
}

//TODO: Figure this out
void point::draw(GraphicsContext* GC){
	int color = (((this->RED << 8) + this->GREEN) << 8) + this->BLUE;
	GC->setColor(color);
	GC->setPixel(this->x, this->y);
}

//no need to do in or out, they should be the same as shape

//need to figure this out
void clone(const point& from){}
