#pragma once
#include "../include/Shape.h"
#include <iostream>

struct ColorContainer
{
public:
	ColorContainer() { red = 255, green = 255, blue = 255; }
	ColorContainer(int _r, int _g, int _b) { red = _r, green = _g, blue = _b; }
	int red;
	int green;
	int blue;

	friend ColorContainer operator* (ColorContainer color, float multi)
	{
		return ColorContainer(color.red * multi, color.green * multi, color.blue * multi);
	}

	static ColorContainer EvaluateColor(Vector2 position)
	{
		float topDistance = Vector2(500, 0).Distance(position);
		float topScale = 1 - (topDistance / 1000);
		if (topScale < 0) topScale = 0;
			float topColor = 255 * topScale;

		float leftDistance = Vector2(0, 1000).Distance(position);
		float leftScale = 1 - (leftDistance / 1000);
		if (leftScale < 0) leftScale = 0;
			float leftColor = 255 * leftScale;

		float rightDistance = Vector2(1000, 1000).Distance(position);
		float rightScale = 1 - (rightDistance / 1000);
		if (rightScale < 0) rightScale = 0;
			float rightColor = 255 * rightScale;

		return ColorContainer(leftColor, topColor, rightColor);
	}
};


class FractalUnit
{
public:
	Vector2 position;
	int size;
	ColorContainer color;
	int maxDepth;
	//ViewPortGL& targetWindow;
	FractalUnit(Vector2 pos, int siz, ColorContainer objColor, int maxD, ViewPortGL& window);
	void PrepareRender(ColorContainer objColor, ViewPortGL& window);
	void GenerateChildUnits(FractalUnit& parent, int currentDepth, ViewPortGL& window);
private:
};