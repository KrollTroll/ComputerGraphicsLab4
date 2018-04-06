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
shape::shape(matrix ORG, int R, int G, int B):RED(R),GREEN(G),BLUE(B),ORIGIN(ORG){

	//consider adding getters to determine matrix size
}

/**
 * Copy constructor
 * @param from : shape to copy information over from
 */
shape::shape(const shape& from):RED(from.RED),GREEN(from.GREEN),BLUE(from.BLUE),ORIGIN(from.ORIGIN){}

/**
 * Destructor - does nothing
 * 	Ensures that things work down the line
 * 	Nothing to do here
 */
shape::~shape(){}





