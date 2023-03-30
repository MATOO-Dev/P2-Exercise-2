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
	vp.prepareBlock(centerX - size, centerY - size, size * 2, size * 2, this->red, this->green, this->blue);
}

void Disk::prepare(ViewPortGL& vp, int centerX, int centerY, int size)
{
	//create center vector
	Vector2 center = Vector2(centerX, centerY);
	const int segments = 60;
	//create array for border points
	Vector2 points[segments];
	//fill point zero
	points[0] = center + (Vector2(0, -1) * size);
	//iterate over rest of points array
	float step = 360 / segments;
	for (int i = 1; i < segments; i++)
	{
		//set current to points[0] rotated by step around center i times
		points[i] = points[0].rotateAround(center, step * i);
		//std::cout << "p[" << i << "] set to " << points[i].x << ", " << points[i].y << std::endl;
		//std::cout << "Total should be " << i*step << " degrees" << std::endl;
		//prepare triangle between i and i-1
		vp.prepareTriangle(points[i].x, points[i].y, points[i - 1].x, points[i - 1].y, center.x, center.y, this->red, this->green, this->blue);
		
	}
	//connect last to first
	vp.prepareTriangle(points[segments - 1].x, points[segments - 1].y, points[0].x, points[0].y, center.x, center.y, this->red, this->green, this->blue);
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
	int x1 = centerX - (v);
	int y1 = centerY + u;
	int x2 = centerX + (v);
	int y2 = centerY + u;
	int x3 = centerX;
	int y3 = centerY - size;

	vp.prepareTriangle(x1, y1, x2, y2, x3, y3, this->red, this->green, this->blue);
}

//same as above but points down
//this is just a copy, because im not sure whether im supposed to leave the prepare function the same
void EquiTriDown::prepare(ViewPortGL& vp, int centerX, int centerY, int size)
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
	int x1 = centerX - (v);
	int y1 = centerY - u;
	int x2 = centerX + (v);
	int y2 = centerY - u;
	int x3 = centerX;
	int y3 = centerY + size;

	vp.prepareTriangle(x1, y1, x2, y2, x3, y3, this->red, this->green, this->blue);
}