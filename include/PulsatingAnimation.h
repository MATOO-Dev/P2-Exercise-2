#pragma once
#include "../include/ViewPortGL.h"
#include "../include/Shape.h"



class PulsatingAnimation {

public:
	PulsatingAnimation(int x, int y, int min, int max);
	void animate(ViewPortGL& vp, Shape& s);

private:
	int posX, posY;
	int minSize, maxSize;
	int currentSize;
	int targetSize;
	int changeStep;
};
