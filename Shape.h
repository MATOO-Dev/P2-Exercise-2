#pragma once

#include "ViewPortGL.h"

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