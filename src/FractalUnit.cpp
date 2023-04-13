#define _USE_MATH_DEFINES
#include "../include/FractalUnit.h"
#include <cmath>

FractalUnit::FractalUnit(Vector2 pos, int siz, ColorContainer objColor, int maxD, ViewPortGL& window)
{
	position = pos;
	size = siz;
	color = objColor;
	maxDepth = maxD;
	//targetWindow = window;
}


void FractalUnit::PrepareRender(ColorContainer objColor, ViewPortGL& window)
{
	EquiTriDown newTri = EquiTriDown(objColor.red, objColor.green, objColor.blue);
	newTri.prepare(window, position.x, position.y, size);

	//Disk newDisk = Disk(objColor.red, objColor.green, objColor.blue);
	//newDisk.prepare(window, position.x, position.y, size / 2);

	//Square newSquare = Square(objColor.red, objColor.green, objColor.blue);
	//newSquare.prepare(window, position.x, position.y, size / 3);
}

void FractalUnit::GenerateChildUnits(FractalUnit& parent, int currentDepth, ViewPortGL& window)
{
	//check if maxdepth is reached, if so, cancel
	if (currentDepth == maxDepth)
		return;
	currentDepth++;

	//some values (yes, this is rounded to int on purpose)
	int parentU = size * sin(M_PI / 6);
	int parentV = size * cos(M_PI / 6);

	//step 1: calculate size of children
	//height of children is half that of the parent
	int parentHeight = size + parentU;
	int childHeight = parentHeight / 2;
	//size is equal to the triangles circumcircle radius, which can be calculated using the height
	int childSize = 2 * childHeight / 3;

	//step 2: calculate child positions
	//create vector array to save positions
	Vector2 childPositions[3];
	//calculate top child position -> parent center, moved up by parent u, moved up by child size
	childPositions[0] = Vector2(this->position.x, this->position.y - parentU - childSize);
	//calculate left child position -> parent center, moved left by parent v, moved down by child u
	int childU = childSize * sin(M_PI / 6);
	childPositions[1] = Vector2(this->position.x - parentV, this->position.y + childU * 2);
	//calculate right child position -> parent center, moved right by parent v, moved down by child u
	childPositions[2] = Vector2(this->position.x + parentV, this->position.y + childU * 2);

	//step 3: generate new color for child position
	ColorContainer childColors[3];
	ColorContainer topColor = ColorContainer(0, 255, 0);
	ColorContainer leftColor = ColorContainer(255, 0, 0);
	ColorContainer rightColor = ColorContainer(255, 255, 0);
	childColors[0] = ColorContainer::EvaluateColor(Vector2(childPositions[0].x, childPositions[0].y));
	childColors[1] = ColorContainer::EvaluateColor(Vector2(childPositions[1].x, childPositions[1].y));
	childColors[2] = ColorContainer::EvaluateColor(Vector2(childPositions[2].x, childPositions[2].y));

	//step 4: generate child fractal units
	FractalUnit childUnits[3]{
	FractalUnit(childPositions[0], childSize, childColors[0], maxDepth, window),
	FractalUnit(childPositions[1], childSize, childColors[1], maxDepth, window),
	FractalUnit(childPositions[2], childSize, childColors[2], maxDepth, window)
	};

	//step 5: call render and generate on children
	for (int i = 0; i < 3; i++)
	{
		//render child
		childUnits[i].PrepareRender(childColors[i], window);
		//generate grandchildren
		childUnits[i].GenerateChildUnits(*this, currentDepth, window);
	}
}