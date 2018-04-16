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
		os << "START LINE" << "\n";
		shape::out(os);
		os << "  " << x2 << "\n";
		os << "  " << y2 << "\n";
		os << "END" << endl << endl;
		return os;
	}

	/**
	 * read in a single line from a file
	 * @param in : istream to parse from
	 * @return   : the new triangle object
	 */
	void line::in(std::istream& in) {

		int RED, GREEN, BLUE = 0;
		float xFlo, yFlo = 0;
		float xFlo2, yFlo2 = 0;

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

				//read in x2 coordinate
				string vertX2;
				getline(in, vertX2, ' ');
				while(!vertX2.compare("")){
					getline(in, vertX2, ' ');
				}
				xFlo2 = stof(vertX2);

				//read in y2 coordinate
				string vertY2;
				getline(in, vertY2, ' ');
				while(!vertY2.compare("")){
					getline(in, vertY2, ' ');
				}
				yFlo2 = stof(vertY2);
			}
			//add new triangle to the image
			this->x = xFlo;
			this->y = yFlo;
			this->RED = RED;
			this->GREEN = GREEN;
			this->BLUE = BLUE;
			this->x2 = xFlo2;
			this->y2 = yFlo2;
	}

	std::ostream& operator<<(std::ostream& os, const line& rhs){
		rhs.out(os);
		return os;
	}
