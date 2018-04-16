/*
 * STLReader.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: ckroll
 *
 *      This is a lab for computer graphics that parses STL files
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

#include "STLReader.h"
#include "shape.h"
#include "triangle.h"
using namespace std;

/**
 * This function parses through an input file and calls printAndCheck
 * @param inFile : the file to be parsed in a string format
 */
void STLReader::parseFile(ifstream myFile, vector<shape*> shapes){
	total = 0;
	initialized = false;
	validFile = false;

		//Print error if file does not open for whatever reason
		if(!myFile){
			cerr << "\n**Unable to open file " << endl;
			cout << "**\n**File may be missing, incorrect format, or corrupted**\n\n";
			validFile = false;
		}
		//If the file is valid
		else{
			//boolean switch for later logic
			validFile = true;

			string holder;
			//as long as there is more in the file
			while(getline(myFile, holder, ' ')){
				//if entering an outer loop
				if(!holder.compare("outer")){
					//increment the total number of facets
					total++;
				}
				//if entering a vertex range
				if(!holder.compare("Triangle")){

					//read in x origin coordinate
					string vertX;
					getline(myFile, vertX, ' ');
					while(!vertX.compare("")){
						getline(myFile, vertX, ' ');
					}
					xFlo = stof(vertX);

					//read in y origin coordinate
					string vertY;
					getline(myFile, vertY, ' ');
					while(!vertY.compare("")){
						getline(myFile, vertY, ' ');
					}
					yFlo = stof(vertY);

					//no Z yet -- can be easily implemened later
					zFlo = 0;

					//read in red
					string R;
					getline(myFile, R, ' ');
					while(!R.compare("")){
						getline(myFile, R, ' ');
					}
					RED = stoi(R);

					//read in green
					string G;
					getline(myFile, G, ' ');
					while(!G.compare("")){
						getline(myFile, G, ' ');
					}
					GREEN = stoi(G);

					//read in blue
					string B;
					getline(myFile, B, ' ');
					while(!B.compare("")){
						getline(myFile, B, ' ');
					}
					BLUE = stoi(B);

					//read in x2 coordinate
					string vertX2;
					getline(myFile, vertX2, ' ');
					while(!vertX2.compare("")){
						getline(myFile, vertX2, ' ');
					}
					xFlo2 = stof(vertX2);

					//read in y2 coordinate
					string vertY2;
					getline(myFile, vertY2, ' ');
					while(!vertY2.compare("")){
						getline(myFile, vertY2, ' ');
					}
					yFlo2 = stof(vertY2);

					//no Z2 yet -- can be easily implemened later
					zFlo2 = 0;

					//read in x3 coordinate
					string vertX3;
					getline(myFile, vertX3, ' ');
					while(!vertX3.compare("")){
						getline(myFile, vertX3, ' ');
					}
					xFlo3 = stof(vertX3);

					//read in y3 coordinate
					string vertY3;
					getline(myFile, vertY3, ' ');
					while(!vertY3.compare("")){
						getline(myFile, vertY3, ' ');
					}
					yFlo3 = stof(vertY3);

					//no Z3 yet -- can be easily implemened later
					zFlo3 = 0;

					//add new triangle to the image
					shapes.push_back(new triangle(xFlo, yFlo, RED, GREEN, BLUE, xFlo2, yFlo2, xFlo3, yFlo3));
				}
		}

		//close file to save memory
		myFile.close();
		}
}

/**
 * main funcion - executes complete file read and console output
 * @param argc : number of arguments passed
 * @param argv : array of arguments passed
 */
//int main (int argc, char *argv[]){

	//as long as two arguments are entered
	//if(argc == 2){
		//pass in second argument as file name
	//	parseFile(argv[1]);
	//}
	//otherwise print error
	//else{
	//	cerr << "\n**      Invalid program arguments!      **";
	//	cout << "\n**Please use a valid .stl file as input!**\n\n";
	//}
	//return 0;
//}




