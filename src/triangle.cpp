#include "triangle.h"

using namespace std;

triangle::triangle(float x, float y, int R, int G, int B, float x2, float y2, float x3, float y3):shape(x,y,R,G,B){
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
}

triangle::triangle(const triangle& from):shape(from){
	this->x2 = from.x2;
	this->y2 = from.x2;
	this->x3 = from.x3;
	this->y3 = from.x3;
}

triangle::~triangle(){
	//there is nothing to free right now
}

//TODO: Figure this out
void triangle::draw(GraphicsContext* GC){
	int color = (((this->RED << 8) + this->GREEN) << 8) + this->BLUE;
	GC->setColor(color);
	GC->drawLine(this->x,  this->y,  this->x2, this->y2);
	GC->drawLine(this->x2, this->y2, this->x3, this->y3);
	GC->drawLine(this->x3, this->y3, this->x,  this->y );
}

//no need to do in or out, they should be the same as shape

triangle& triangle::operator=(const triangle& from){
	this->shape::operator=(from);
	this->x2 = from.x2;
	this->y2 = from.y2;
	this->x3 = from.x3;
	this->y3 = from.y3;
	return *this;
}

std::ostream& triangle::out(std::ostream& os) const{
	os << "TRIANGLE:" << "\n";
	shape::out(os);
	os << "\tx2: " << x2;
	os << ", y2: " << y2 << "\n";
	os << "\tx3: " << x3;
	os << ", y3: " << y3 << "\n";
	return os;
}

std::ostream& operator<<(std::ostream& os, const triangle& rhs){
	rhs.out(os);
	return os;
}
