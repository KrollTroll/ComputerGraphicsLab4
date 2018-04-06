#ifndef SHAPE_H
#define SHAPE_H


#include "matrix.h"

class shape{

public:

	/**
	 * Generic Consructot
	 * @param ORG : origin point in matrix form
	 * @param R : RED color data
	 * @param G : GREEN color data
	 * @param B : BLUE color data
	 */
	shape(matrix ORG, int R, int G, int B);

	shape(const shape& from);

	/**
	 * Need a virtual destructor
	 */
	virtual ~shape();

	virtual shape& operator=(const shape& rhs);

	/**
	 * draw the shape
	 */
	virtual void draw() = 0;

	/**
	 * print the shape out to a terminal
	 */
	virtual std::ostream& out(std::ostream& os) const = 0;

	/**
	 * read the shape in from a file
	 */
	virtual std::istream& in(std::istream& file) const = 0;

	/**
	 * clone the shape onto another
	 */
	virtual void clone() = 0;

private:
	//color variables
	int RED;
	int GREEN;
	int BLUE;
	//matrix to hold point
	matrix ORIGIN;
};

#endif
