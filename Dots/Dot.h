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
	static WindowCoordinate matrixToWinCoord(int x, int y);

	MatrixCoordinate getMatrixCoordinate();
	WindowCoordinate getWindowCoordinate();
	int getSize();
	COLORREF getColor();
	DotType dotType;
	bool visible = true;
	void moveToMatrix(int x, int y);
	int dropStep = 0;
	void update();
private:
	MatrixCoordinate matrixCoord;
	WindowCoordinate winCoord;
	HWND hWnd;
	HDC hdc;
	COLORREF color;
	PAINTSTRUCT ps;
	WindowCoordinate targetWinCoord;
	bool moving;
	int size;
	int acc=0;


};

