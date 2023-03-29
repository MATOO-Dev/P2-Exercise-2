#include "ViewPortGL.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include "Shape.h"
#include "PulsatingAnimation.h"

void test() {
	ViewPortGL vp = ViewPortGL("OpenGL Plain Test", 1000, 1000);
	bool isRunning = true;
	while (isRunning) {
		isRunning = !vp.windowShouldClose();

		vp.prepareTriangle(0, 999, 999, 999, 500, 0, 200, 0, 0, 0, 0, 200, 0, 200, 0);
		vp.sendTriangles();

		vp.swapBuffers();
	}
}

void DrawSquares()
{
	ViewPortGL targetWindow = ViewPortGL("Squares", 1000, 1000);
	//green square
	Square greenSquare = Square(0, 255, 0);
	greenSquare.prepare(targetWindow, 700, 400, 150);
	//yellow square
	Square yellowSquare = Square(255, 255, 0);
	yellowSquare.prepare(targetWindow, 600, 800, 100);
	//blue square
	Square blueSquare = Square(0, 0, 255);
	blueSquare.prepare(targetWindow, 900, 200, 35);
	//red square
	Square redSqaure = Square(255, 0, 0);
	redSqaure.prepare(targetWindow, 200, 300, 25);
	//prepare for shipping
	targetWindow.sendTriangles();
	targetWindow.swapBuffers();
	//keep window open
	while (!targetWindow.windowShouldClose()) {}
}

void DrawCircles()
{
	ViewPortGL targetWindow = ViewPortGL("Circles", 1000, 1000);
	//green disk
	Disk greenDisk = Disk(0, 255, 0);
	greenDisk.prepare(targetWindow, 700, 400, 150);
	//yellow disk
	Disk yellowDisk = Disk(255, 255, 0);
	yellowDisk.prepare(targetWindow, 600, 800, 100);
	//blue disk
	Disk blueDisk = Disk(0, 0, 255);
	blueDisk.prepare(targetWindow, 900, 200, 35);
	//red disk
	Disk redDisk = Disk(255, 0, 0);
	redDisk.prepare(targetWindow, 200, 300, 25);
	//prepare for shipping
	targetWindow.sendTriangles();
	targetWindow.swapBuffers();
	//keep window open
	while (!targetWindow.windowShouldClose()) {}
}

void DrawTriangles()
{
	ViewPortGL targetWindow = ViewPortGL("Triangles", 1000, 1000);
	//green triangle
	EquilateralTriangle greenTriangle = EquilateralTriangle(0, 255, 0);
	greenTriangle.prepare(targetWindow, 700, 400, 150);
	//yellow triangle
	EquilateralTriangle yellowTriangle = EquilateralTriangle(255, 255, 0);
	yellowTriangle.prepare(targetWindow, 600, 800, 100);
	//blue triangle
	EquilateralTriangle blueTriangle = EquilateralTriangle(0, 0, 255);
	blueTriangle.prepare(targetWindow, 900, 200, 35);
	//red triangle
	EquilateralTriangle redTriangle = EquilateralTriangle(255, 0, 0);
	redTriangle.prepare(targetWindow, 200, 300, 25);
	//prepare for shipping
	targetWindow.sendTriangles();
	targetWindow.swapBuffers();
	//keep window open
	while (!targetWindow.windowShouldClose()) {}
}

void AnimateShapes()
{
	ViewPortGL targetWindow = ViewPortGL("Animations weeeeeeeee", 1000, 1000);

	Square redSquare = Square(255, 0, 0);
	PulsatingAnimation squareAnim = PulsatingAnimation(200, 300, 25, 50);
	Disk greenDisk = Disk(0, 255, 0);
	PulsatingAnimation diskAnim = PulsatingAnimation(700, 400, 50, 300);
	EquilateralTriangle yellowTriangle = EquilateralTriangle(255, 255, 0);
	PulsatingAnimation triangleAnim = PulsatingAnimation(600, 800, 10, 100);
	//wait for window close signal
	while (!targetWindow.windowShouldClose())
	{
		targetWindow.clearViewPort();
		squareAnim.animate(targetWindow, redSquare);
		diskAnim.animate(targetWindow, greenDisk);
		triangleAnim.animate(targetWindow, yellowTriangle);
		targetWindow.sendTriangles();
		targetWindow.swapBuffers();
	}
}

int main() {
	//test();
	//DrawSquares();
	//DrawCircles();
	//DrawTriangles();
	AnimateShapes();
	return 0;
}




