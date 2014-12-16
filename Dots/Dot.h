#pragma once

#include "MatrixCoordinate.h"
#include "WindowCoordinate.h"
#include "Director.h"
#include "Matrix.h"
#include "DotType.h"
#include "DotColor.h"	



class Dot
{
public:
	Dot();
	Dot(DotType type);
	~Dot(); 

	void drawDot();
	void setMatrixCoordinate(int x, int y);
	static WindowCoordinate matrixToWinCoord(MatrixCoordinate matrixCoord);
	MatrixCoordinate getMatrixCoordinate();
	WindowCoordinate getWindowCoordinate();
	int getSize();
	COLORREF getColor();
	DotType dotType;


private:
	MatrixCoordinate matrixCoord;
	WindowCoordinate winCoord;
	HWND hWnd;
	HDC hdc;
	COLORREF color;
	PAINTSTRUCT ps;

	int size;



};

