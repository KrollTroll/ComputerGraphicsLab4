#ifndef SHAPE_H
#define SHAPE_H


#include "matrix.h"
#include "gcontext.h"

class shape{

public:

	/**
	 * Generic Consructor
	 * @param R : RED color data
	 * @param G : GREEN color data
	 * @param B : BLUE color data
	 */
	shape(float x, float y, int R, int G, int B);

	shape(const shape& from);

	/**
	 * Need a virtual destructor
	 */
	virtual ~shape();

	virtual shape& operator=(const shape& rhs);

	/**
	 * draw the shape
	 */
	virtual void draw(GraphicsContext* GC) = 0;

	/**
	 * print the shape out to a terminal
	 */
	virtual std::ostream& out(std::ostream& os) const = 0;

	/**
	 * read the shape in from a file
	 */
	//virtual std::istream& in(std::istream& file) const = 0;

	/**
	 * clone the shape onto another
	 */
	virtual shape& clone() = 0;

protected:
	float x;
	float y;
	//color variables
	int RED;
	int GREEN;
	int BLUE;
};

/**
 * This is a global operator for output
 * @param os  : target output stream
 * @param rhs : shape to output
 * @return    : the same output stream
 */
std::ostream& operator<<(std::ostream& os, const shape& rhs);

#endif
