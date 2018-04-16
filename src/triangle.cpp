#include <vector>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

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

triangle& triangle::clone(){
	return *(new triangle(x, y, RED, GREEN, BLUE, x2, y2, x3, y3));
}

std::ostream& triangle::out(std::ostream& os) const{
	os << "START TRIANGLE" << "\n";
	shape::out(os);
	os << "  " << x2 << "\n";
	os << "  " << y2 << "\n";
	os << "  " << x3 << "\n";
	os << "  " << y3 << "\n";
	os << "END" << endl << endl;
	return os;
}

/**
 * read in a single triangle from a file
 * @param in : istream to parse from
 * @return   : the new triangle object
 */
void triangle::in(std::istream& in) {
	//cout << "TRIANGLE IN CALLED!" << endl;

		//Print error if file does not open for whatever reason
		if(!in){
			cerr << "\n**Unable to open file " << endl;
			cout << "**\n**File may be missing, incorrect format, or corrupted**\n\n";
		}
		//If the file is valid
		else{
			string holder;

				getline(in, holder);
				holder.erase(std::remove(holder.begin(),holder.end(),' '),holder.end());
				this->x = stof(holder);
				getline(in, holder);
				holder.erase(std::remove(holder.begin(),holder.end(),' '),holder.end());
				this->y = stof(holder);
				getline(in, holder);
				holder.erase(std::remove(holder.begin(),holder.end(),' '),holder.end());
				this->RED = stoi(holder);
				getline(in, holder);
				holder.erase(std::remove(holder.begin(),holder.end(),' '),holder.end());
				this->GREEN = stoi(holder);
				getline(in, holder);
				holder.erase(std::remove(holder.begin(),holder.end(),' '),holder.end());
				this->BLUE = stoi(holder);
				getline(in, holder);
				holder.erase(std::remove(holder.begin(),holder.end(),' '),holder.end());
				this->x2 = stof(holder);
				getline(in, holder);
				holder.erase(std::remove(holder.begin(),holder.end(),' '),holder.end());
				this->y2 = stof(holder);
				getline(in, holder);
				holder.erase(std::remove(holder.begin(),holder.end(),' '),holder.end());
				this->x3 = stof(holder);
				getline(in, holder);
				holder.erase(std::remove(holder.begin(),holder.end(),' '),holder.end());
				this->y3 = stof(holder);

		}
}

std::ostream& operator<<(std::ostream& os, const triangle& rhs){
	rhs.out(os);
	return os;
}
