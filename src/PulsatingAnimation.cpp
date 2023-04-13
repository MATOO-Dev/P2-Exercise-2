#include "../include/PulsatingAnimation.h"

PulsatingAnimation::PulsatingAnimation(int x, int y, int min, int max)
{
	posX = x;
	posY = y;
	minSize = min;
	maxSize = max;
	currentSize = minSize;
	targetSize = maxSize;
	changeStep = 1;
}


void PulsatingAnimation::animate(ViewPortGL& vp, Shape& s)
{
	//zoom shape in and out
	//can reuse a lot of code from 1-3 since my version was almost the same thing
	if (currentSize > targetSize)
		changeStep *= -1;
	//suggestion: clamp this value to squareSizeMin/Max, to prevent over/undershooting while scaling
	currentSize = currentSize + changeStep;
	//check whether to flip grow direction next iteration
	if (currentSize <= minSize || currentSize >= maxSize)
		changeStep *= -1;
	s.prepare(vp, posX, posY, currentSize);
}