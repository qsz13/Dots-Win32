#include "stdafx.h"
#include "Dot.h"


Dot::Dot()
{
	matrixCoord.x = -1;
	matrixCoord.y = -1;
	this->hWnd = Director::getDirector().hWnd;
	this->hdc = Director::getDirector().hdc;
	this->size = 30;
}


Dot::Dot(DotType type)
{
	this->dotType = type;
	switch (type)
	{
	case BlueDot:
		this->color = BLUE_DOT;
		break;
	case GreenDot:
		this->color = GREEN_DOT;
		break;
	case PurpleDot:
		this->color = PURPLE_DOT;
		break;
	case RedDot:
		this->color = RED_DOT;
		break;
	case YellowDot:
		this->color = YELLOW_DOT;
		break;

	}

	matrixCoord.x = -1;
	matrixCoord.y = -1;
	this->hWnd = Director::getDirector().hWnd;
	this->hdc = GetDC(this->hWnd);
	this->size = 30;
}

Dot::~Dot()
{
}

int Dot::getSize()
{
	return this->size;
}

void Dot::drawDot()
{
	if (this->visible)
	{
		BeginPaint(this->hWnd, &this->ps);
		SelectObject(this->hdc, GetStockObject(DC_BRUSH));
		SelectObject(this->hdc, GetStockObject(DC_PEN));
		SetDCBrushColor(this->hdc, this->color);
		SetDCPenColor(this->hdc, this->color);
		this->winCoord = matrixToWinCoord(this->matrixCoord);
		Ellipse(this->hdc, this->winCoord.x - size / 2, this->winCoord.y - size / 2,
			this->winCoord.x + size / 2, this->winCoord.y + size / 2);
		EndPaint(this->hWnd, &ps);
	}
	
}

void Dot::setMatrixCoordinate(int x, int y)
{
	this->matrixCoord.x = x;
	this->matrixCoord.y = y;
	this->winCoord = matrixToWinCoord(this->matrixCoord);
	
}

WindowCoordinate Dot::matrixToWinCoord(MatrixCoordinate matrixCoord)
{
	WindowCoordinate winC;
	Matrix *m = &Matrix::getMatrix();
	winC.x = m->x + matrixCoord.x*m->interval;
	winC.y = m->y + matrixCoord.y*m->interval;
	return winC;
}

MatrixCoordinate Dot::getMatrixCoordinate()
{
	return this->matrixCoord;
}

WindowCoordinate Dot::getWindowCoordinate()
{
	return this->winCoord;
}

COLORREF Dot::getColor()
{
	return this->color;
}

void Dot::moveToMatrix(int x, int y)
{
	AllocConsole();
	std::cout << x <<"    " <<y << endl;
	this->setMatrixCoordinate(x, y);
	this->dropStep = 0;

	
}

