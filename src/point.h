#ifndef POINT_H
#define POINT_H

#include "shape.h"

class point : public shape{
public:

	/**
	 * Constructor for a point object
	 * @param x : x coordinate of point
	 * @param y : y coordinate of point
	 * @param R : red color value for point
	 * @param G : green color value for point
	 * @param B : blue color value for point
	 */
	point(float x, float y, int R, int G, int B);

	/**
	 * copy constructor for point
	 * @param from : object to copy
	 */
	point(const point& from);

	/**
	 * destructor - doesn't do much
	 */
	~point();

	/**
	 * draws the point
	 * @param GC : graphicscontext interface to draw to
	 */
	void draw(GraphicsContext* GC);

	/**
	 * assignment operator
	 * @param from : object to assign from
	 * @return     : address of newly assigned object
	 */
	point& operator=(const point& from);

	point& clone();

	/**
	 * outputs data from point to an os stream
	 * @param os : os stream to output to
	 * @return   : address of that same stream
	 */
	std::ostream& out(std::ostream& os) const;
};

/**
 * over-written global operator to print point data
 * @param os  : os stream to print to
 * @param rhs : point to output
 * @return    : adress of the same os stream
 */
std::ostream& operator<<(std::ostream& os, const point& rhs);

#endif
