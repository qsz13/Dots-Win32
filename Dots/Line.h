#pragma once
#include <vector>
#include "MatrixCoordinate.h"
#include "WindowCoordinate.h"
#include "Director.h"
#include "Dot.h"
#include <iostream>
using namespace std;
class Dot;
class Line
{
private:
	Line();
	Line(Line const&);
	void operator=(Line const&);
	HWND hWnd;
	HDC hdc;
	PAINTSTRUCT ps;

public:
	static Line& getLine();
	~Line();
	void drawLine();
	void addDot(Dot* dot);
	vector<Dot*> dotVector;
	void removeLine();

};

