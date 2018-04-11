#include "point.h"

using namespace std;

/**
 * Point constructor
 * @param x : point x coordinate
 * @param y : point y coordinate
 * @param R : point red color value
 * @param G : point green color value
 * @param B : point blue color value
 */
point::point(float x, float y, int R, int G, int B):shape(x,y,R,G,B){}

/**
 * copy constructor
 * @param from : point to cpoy data from
 */
point::point(const point& from):shape(from){}

/**
 * destructor - doesn't do much
 */
point::~point(){}

/**
 * draws the shape to the appropriate graphicscontext interface
 * @param GC : target graphicscontext interface
 */
void point::draw(GraphicsContext* GC){
	int color = (((this->RED << 8) + this->GREEN) << 8) + this->BLUE;
	GC->setColor(color);
	GC->setPixel(this->x, this->y);
}

/**
 * Assignment operator
 * @param from : object to assign from
 * @return     : address of newly assigned object
 */
point& point::operator=(const point& from){
	this->shape::operator =(from);
	return *this;
}

/**
 * prints point data to an output stream
 * @param os : target output stream
 * @return   : adress of same output stream
 */
std::ostream& point::out(std::ostream& os) const{
	os << "POINT: " << "\n";
	shape::out(os);
	return os;
}

/**
 * over-written global operator to print point data
 * @param os  : target output stream
 * @param rhs : point to output
 * @return    : adress of the same output stream
 */
std::ostream& operator<<(std::ostream& os, const point& rhs){
	rhs.out(os);
	return(os);
}
