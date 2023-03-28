#include "ViewPortGL.h"
#include <cmath>
#include <algorithm>
#include "Shape.h"

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
	greenSquare.prepare(targetWindow, 700, 400, 300);
	//yellow square
	Square yellowSquare = Square(255, 255, 0);
	yellowSquare.prepare(targetWindow, 600, 800, 200);
	//blue square
	Square blueSquare = Square(0, 0, 255);
	blueSquare.prepare(targetWindow, 900, 200, 70);
	//red square
	Square redSqaure = Square(255, 0, 0);
	redSqaure.prepare(targetWindow, 200, 300, 50);
	//prepare for shipping
	targetWindow.sendTriangles();
	targetWindow.swapBuffers();
	//keep window open
	while (!targetWindow.windowShouldClose()) {}
}



void DrawTriangles()
{
	ViewPortGL targetWindow = ViewPortGL("Triangles", 1000, 1000);
	//green square
	EquilateralTriangle greenTriangle = EquilateralTriangle(0, 255, 0);
	greenTriangle.prepare(targetWindow, 700, 400, 300);
	//yellow square
	EquilateralTriangle yellowTriangle = EquilateralTriangle(255, 255, 0);
	yellowTriangle.prepare(targetWindow, 600, 800, 200);
	//blue square
	EquilateralTriangle blueTriangle = EquilateralTriangle(0, 0, 255);
	blueTriangle.prepare(targetWindow, 900, 200, 70);
	//red square
	EquilateralTriangle redTriangle = EquilateralTriangle(255, 0, 0);
	redTriangle.prepare(targetWindow, 200, 300, 50);
	//prepare for shipping
	targetWindow.sendTriangles();
	targetWindow.swapBuffers();
	//keep window open
	while (!targetWindow.windowShouldClose()) {}
}

int main() {
	//test();
	//DrawSquares();
	DrawTriangles();
	return 0;
}




