#include "line.h"

using namespace std;

	/**
 	 * line consructor
	 * @param x  : start point x coordinate
	 * @param y  : start point y coordinate
	 * @param R  : line red color value
	 * @param G  : line green color value
	 * @param B  : line blue color value
	 * @param x2 : end point x coordinate
	 * @param y2 : end point y coordinate
	 */
	line::line(float x, float y, int R, int G, int B, float x2, float y2):shape(x,y,R,G,B){
		this->x2 = x2;
		this->y2 = y2;
	}

	/**
	 * copy constructor for a line
	 * @param from : line to copy from
	 */
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

	line& line::operator=(const line& from){
		this->shape::operator=(from);
		this->x2 = from.x2;
		this->y2 = from.y2;
		return *this;
	}

	line& line::clone(){
		return *(new line(x, y, RED, GREEN, BLUE, x2, y2));
	}

	std::ostream& line::out(std::ostream& os) const{
		os << "LINE:" << "\n";
		shape::out(os);
		os << "\tx2: " << x2;
		os << ", y2: " << y2 << "\n";
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const line& rhs){
		rhs.out(os);
		return os;
	}
