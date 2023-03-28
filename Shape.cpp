#define _USE_MATH_DEFINES
#include <cmath>
#include "Shape.h"
#include <iostream>

Shape::Shape(int red, int green, int blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

void Square::prepare(ViewPortGL& vp, int centerX, int centerY, int size)
{
	//shapes are rendered from top left corner downwards and rightwards
	//therefore, offset render target by size/2 from center
	vp.prepareBlock(centerX - size / 2, centerY - size / 2, size, size, this->red, this->green, this->blue);
}

void Disk::prepare(ViewPortGL& vp, int centerX, int centerY, int size)
{
	//unclear because circle
	//shapes are rendered from top left corner downwards and rightwards
	//therefore, offset render target by size/2 from center
	//vp.preparePix(centerX - size / 2, centerY - size / 2, size, size, this->red, this->green, this->blue);
}

void EquilateralTriangle::prepare(ViewPortGL& vp, int centerX, int centerY, int size)
{
	//some math:
	//triangles are defined by A,B,C coordinates in ViewPortGL
	//therefore, we need to calculate u and v
	//angle alpha = pi/6
	double alpha = (M_PI / 6);
	//u = s * sin(alpha)
	double u = size * sin(alpha);
	//v = s * cos(alpha)
	double v = size * cos(alpha);
	//for example, bottom left corner is centerX - v/2, centerY + u and so on for all points
	int x1 = centerX - (v / 2);
	int y1 = centerY + u;
	int x2 = centerX + (v / 2);
	int y2 = centerY + u;
	int x3 = centerX;
	int y3 = centerY - size;

	//example
	//center is 700, 400
	//size is 300
	//alpha is approximately 0.5235
	//u is 150
	//v is approximately 299.9874 = 300
	//p1 is 550, 550
	//p2 is 850, 550
	//p3 is 700, 100
	std::cout << "alpha is " << alpha << std::endl;
	std::cout << "u is " << u << std::endl;
	std::cout << "v is " << v << std::endl;
	std::cout << "p1 is " << x1 << ", " << y1 << std::endl;
	std::cout << "p1 is " << x2 << ", " << y2 << std::endl;
	std::cout << "p1 is " << x3 << ", " << y3 << std::endl;

	vp.prepareTriangle(x1, y1, x2, y2, x3, y3, this->red, this->green, this->blue);
}