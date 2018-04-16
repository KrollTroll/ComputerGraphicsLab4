#include "x11context.h"
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "image.h"
#include <unistd.h>
#include <iostream>


int main(void){

	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);

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

	image img2 = img;

	//p1.draw(gc);
	//std::cout << p1 << std::endl;
	//l1.draw(gc);
	//std::cout << l1 << std::endl;
	//t1.draw(gc);
	//std::cout << t1 << std::endl;

	//sleep(2);

	//t2.draw(gc);
	//l2.draw(gc);
	//p2.draw(gc);

	//sleep(2);

	//p3.draw(gc);
	//l3.draw(gc);
	//t3.draw(gc);

	sleep(5);

	img2.draw(gc);
	sleep(5);

	img.erase();
	img2.erase();

	delete(gc);
	return 0;
}
