#include "x11context.h"
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "image.h"

#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){

	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);

	if(argc == 1){
	point p1(500, 25, 255, 0, 0);
	line l1(75, 150, 0, 255, 0, 7, 600);
	triangle t1(  10,   10,   0, 0, 255, 100, 100, 200,  10);

	triangle t2(200, 200, 255, 0,   0, 700, 400, 600, 600);
	line l2(100, 500, 0, 0, 255, 800, 200);
	point p2(400, 300, 0, 255, 0);

	point p3(700,200,0,0,255);
	line l3(800, 100, 255, 0, 0, 200, 50);
	triangle t3(600, 300, 0, 255, 0, 200, 400, 50, 50);

	image img;

	img.add(&p1);
	img.add(&l1);
	img.add(&t1);

	img.draw(gc);

	image img2(img);

	img2.add(&t2);
	img2.add(&l2);
	img2.add(&p2);

	sleep(5);

	img.erase();
	img2.draw(gc);
	sleep(5);

	//un-comment the next two lines if you would like to see terminal output
	//std::cout << "IMAGE 2" << std::endl;
	//std::cout << img2 << std::endl;

	//create and modify image 3 from image 2
	image img3 = img2;
	img2.erase();
	img3.add(&p3);
	img3.add(&l3);
	img3.add(&t3);

	//output image 3 to a file
	std::ofstream output;
	output.open("SampleOutput.txt");
	output << "IMAGE 3" << std::endl;
	output << img3 << std::endl;

	//clear the image and draw image 3
	gc->clear();
	img3.draw(gc);
	sleep(5);
	}

	else{

		image img4;
		//open file
		std::ifstream input;
		input.open(argv[1]);
		while(input){
			img4.in(input);
		}
		input.close();
		gc->clear();
		img4.draw(gc);
		sleep(5);

		std::cout << img4;
	}

	delete(gc);

	return 0;
}
