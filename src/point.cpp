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

point& point::clone(){
	return *(new point(x, y, RED, BLUE, GREEN));
}

/**
 * prints point data to an output stream
 * @param os : target output stream
 * @return   : adress of same output stream
 */
std::ostream& point::out(std::ostream& os) const{
	os << "START POINT " << "\n";
	shape::out(os);
	os << "END" << endl << endl;
	return os;
}

void point::in(std::istream& in) {

	int RED, GREEN, BLUE = 0;
	float xFlo, yFlo = 0;

		//Print error if file does not open for whatever reason
		if(!in){
			cerr << "\n**Unable to open file " << endl;
			cout << "**\n**File may be missing, incorrect format, or corrupted**\n\n";
		}
		//If the file is valid
		else{
			//read in x origin coordinate
			string vertX;
			getline(in, vertX, ' ');
			while(!vertX.compare("")){
				getline(in, vertX, ' ');
			}
			xFlo = stof(vertX);

			//read in y origin coordinate
			string vertY;
			getline(in, vertY, ' ');
			while(!vertY.compare("")){
				getline(in, vertY, ' ');
			}
			yFlo = stof(vertY);

			//read in red
			string R;
			getline(in, R, ' ');
			while(!R.compare("")){
				getline(in, R, ' ');
			}
			RED = stoi(R);

			//read in green
			string G;
			getline(in, G, ' ');
			while(!G.compare("")){
				getline(in, G, ' ');
			}
			GREEN = stoi(G);

			//read in blue
			string B;
			getline(in, B, ' ');
			while(!B.compare("")){
				getline(in, B, ' ');
			}
			BLUE = stoi(B);

		}
		//modify point
		this->x = xFlo;
		this->y = yFlo;
		this->RED = RED;
		this->GREEN = GREEN;
		this->BLUE = BLUE;
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
