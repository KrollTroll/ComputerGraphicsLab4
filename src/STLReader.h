/*
 * STLReader.h
 *
 *  Created on: Apr 15, 2018
 *      Author: ckroll
 */

#ifndef STLREADER_H_
#define STLREADER_H_

#include <iostream>
#include <vector>

#include "shape.h"

using namespace std;

class STLReader{

public:
	void parseFile(ifstream myFile, vector<shape*> shapes);

protected:
	float xFlo;
	float yFlo;
	float zFlo;

	int RED;
	int GREEN;
	int BLUE;

	float xFlo2;
	float yFlo2;
	float zFlo2;

	float xFlo3;
	float yFlo3;
	float zFlo3;

	int total;

	bool initialized;
	bool validFile;
};



#endif /* STLREADER_H_ */
