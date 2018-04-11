/*
 * shape.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: ckroll
 */

#include "shape.h"
#include "matrix.h"

/**
 * Generic constructor
 * TODO: Error Checking?
 * @param ORG : origin point matrix
 * @param R   : RED data
 * @param G   : GREEN data
 * @param B   : BLUE data
 */
shape::shape(float x, float y, int R, int G, int B):x(x), y(y), RED(R),GREEN(G),BLUE(B){
}

/**
 * Copy constructor
 * @param from : shape to copy information over from
 */
shape::shape(const shape& from):x(from.x),y(from.y),RED(from.RED),GREEN(from.GREEN),BLUE(from.BLUE){

}

/**
 * Destructor - does nothing
 * 	Ensures that things work down the line
 * 	Nothing to do here
 */
shape::~shape(){}

/**
 * Assignment operator
 * @param rhs
 * @return
 */
shape& shape::operator=(const shape& rhs){
	x = rhs.x;
	y = rhs.y;
	RED = rhs.RED;
	GREEN = rhs.GREEN;
	BLUE = rhs.BLUE;
	return *this;
}

std::ostream& shape::out(std::ostream& os) const{
	os << "\tx: " << x;
	os << ", y: " << y << "\n";
	os << "\tR: " << RED << "\n";
	os << "\tG: " << GREEN << "\n";
	os << "\tB: " << BLUE << "\n";
	return os;
};

std::ostream& operator<<(std::ostream& os, const shape& rhs){
	rhs.out(os);
	return os;
}





