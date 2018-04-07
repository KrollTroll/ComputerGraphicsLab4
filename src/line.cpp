#include "line.h"

using namespace std;

line::line(float x, float y, int R, int G, int B, float x2, float y2):shape(x,y,R,G,B){
	this->x2 = x2;
	this->y2 = y2;
}

line::line(const line& from):shape(from){
	this->x2 = from.x2;
	this->y2 = from.x2;
}

line::~line(){
	//there is nothing to free right now
}

//TODO: Figure this out
void line::draw(GraphicsContext* GC){
	int color = (((this->RED << 8) + this->GREEN) << 8) + this->BLUE;
	GC->setColor(color);
	GC->drawLine(this->x, this->y, this->x2, this->y2);
}

//no need to do in or out, they should be the same as shape

//need to figure this out
void clone(const line& from){}
