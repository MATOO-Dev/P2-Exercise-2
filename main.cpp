#include "include/ViewPortGL.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include "include/Shape.h"
#include "include/PulsatingAnimation.h"
#include "include/FractalUnit.h"
#include <chrono>
#include <thread>

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
	while (!targetWindow.windowShouldClose())
        this_thread::sleep_for(chrono::milliseconds(100));
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
	while (!targetWindow.windowShouldClose())
        this_thread::sleep_for(chrono::milliseconds(100));
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
	while (!targetWindow.windowShouldClose())
        this_thread::sleep_for(chrono::milliseconds(100));
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
        this_thread::sleep_for(chrono::milliseconds(10));
	}
}

void RenderTriangleFractal()
{
	//create window
	ViewPortGL targetWindow = ViewPortGL("Triangles go brrrrrrrrrrrrrrrrrrrrr", 1000, 900);

	//create starting triangle
	Vector2 startPos = Vector2(500, 590);
	int startSize = 300;
	//ColorContainer startingColor = ColorContainer(66, 50, 0);
	ColorContainer startingColor = ColorContainer::EvaluateColor(startPos);
	int maxDepth = 5;

	FractalUnit startingTri = FractalUnit(startPos, startSize, startingColor, maxDepth, targetWindow);
	startingTri.PrepareRender(startingColor, targetWindow);

	//recursively generate child triangles
	startingTri.GenerateChildUnits(startingTri, 0, targetWindow);

	//render generated triangles
	targetWindow.sendTriangles();
	targetWindow.swapBuffers();

	//keep window open
	while (!targetWindow.windowShouldClose())
        this_thread::sleep_for(chrono::milliseconds(100));
}

void Sierpinski(ViewPortGL& targetWindow, Vector2 pointA, Vector2 pointB, Vector2 pointC, int depth)
{
	if (depth == 0)
		return;

	Vector2 MAB = Vector2((pointA.x + pointB.x) * 0.5f, (pointA.y + pointB.y) * 0.5f);
	Vector2 MAC = Vector2((pointA.x + pointC.x) * 0.5f, (pointA.y + pointC.y) * 0.5f);
	Vector2 MBC = Vector2((pointB.x + pointC.x) * 0.5f, (pointB.y + pointC.y) * 0.5f);

	targetWindow.prepareTriangle(MAB.x, MAB.y, MAC.x, MAC.y, MBC.x, MBC.y, 255, 255, 255);

	Sierpinski(targetWindow, pointA, MAB, MAC, depth - 1);
	Sierpinski(targetWindow, MAB, pointB, MBC, depth - 1);
	Sierpinski(targetWindow, MAC, MBC, pointC, depth - 1);
}

void RunSierpinski()
{
	//create window
	ViewPortGL targetWindow = ViewPortGL("Sierpinski", 1000, 1000);

	targetWindow.sendTriangles();

	Sierpinski(targetWindow, Vector2(0, 1000), Vector2(1000, 1000), Vector2(500, 0), 6);

	targetWindow.sendTriangles();
	targetWindow.swapBuffers();

	//keep window open
	while (!targetWindow.windowShouldClose())
        this_thread::sleep_for(chrono::milliseconds(100));
}

int main() {
	//DrawSquares();
	//DrawCircles();
	//DrawTriangles();
	//AnimateShapes();
	//RenderTriangleFractal();
	RunSierpinski();
	return 0;
}