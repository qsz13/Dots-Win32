#include "stdafx.h"
#include "Director.h"


Director::Director()
{
	this->hWnd = GetActiveWindow();
}


Director::~Director()
{
}

Director& Director::getDirector()
{
	static Director director;
	return director;
}

void Director::update()
{
	if (this->mouseIsDown && allowConnect)
	{
		Matrix::getMatrix().addDotInLine(mouseX, mouseY);
	}
	Line::getLine().drawLine();
	Matrix::getMatrix().drawMatrix();	
}

void Director::mouseUpEvent()
{
	this->mouseIsDown = false;
	Line::getLine().removeLine();
}

void Director::mouseDownEvent()
{
	this->mouseIsDown = true;
}

