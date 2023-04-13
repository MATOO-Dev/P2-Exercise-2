#pragma once

#include "../include/ViewPortGL.h"
#include <iostream>

class Shape {
public:
	Shape(int red, int green, int blue);
	virtual void prepare(ViewPortGL& vp, int centerX, int centerY, int size) = 0;

protected:
	int red, green, blue;
};

class Square : public Shape
{
public:
	Square(int red, int green, int blue) :Shape(red, green, blue) {}
	void prepare(ViewPortGL& vp, int centerX, int centerY, int size) override;
};

class Disk : public Shape
{
public:
	Disk(int red, int green, int blue) :Shape(red, green, blue) {}
	void prepare(ViewPortGL& vp, int centerX, int centerY, int size) override;
};

class EquilateralTriangle : public Shape
{
public:
	EquilateralTriangle(int red, int green, int blue) :Shape(red, green, blue) {}
	void prepare(ViewPortGL& vp, int centerX, int centerY, int size) override;
};

class EquiTriDown : public Shape
{
public:
	EquiTriDown(int red, int green, int blue) :Shape(red, green, blue) {}
	void prepare(ViewPortGL& vp, int centerX, int centerY, int size) override;
};

//simple vector utility
struct Vector2
{
public:
	Vector2() { x = 0, y = 0; }
	Vector2(int xVal, int yVal) { x = xVal, y = yVal; }
	int x;
	int y;

	friend Vector2 operator+ (const Vector2& first, const Vector2& second)
	{
		return Vector2(first.x + second.x, first.y + second.y);
	}

	friend Vector2 operator- (const Vector2& first, const Vector2& second)
	{
		return Vector2(second.x - first.x, second.y - first.y);
	}

	friend Vector2 operator* (const Vector2& vec, float mult)
	{
		return Vector2(vec.x * mult, vec.y * mult);
	}

	Vector2 rotateAround(const Vector2& pivot, double degrees)
	{
		//convert angle from degrees to radians
		double angle = degrees * (3.1415926 / 180);
		//i stole the math for these 2 lines online: https://stackoverflow.com/questions/620745/c-rotating-a-vector-around-a-certain-point
		float rotX = ((this->x - pivot.x) * cos(angle)) - ((pivot.y - this->y) * sin(angle)) + pivot.x;
		float rotY = pivot.y - ((pivot.y - this->y) * cos(angle)) + ((this->x - pivot.x) * sin(angle));
		return Vector2(rotX, rotY);
	}

	float Distance(const Vector2& other)
	{
		Vector2 diff = Vector2(other.x - x, other.y - y);
		return sqrt((diff.x * diff.x) + (diff.y * diff.y));
	}
};