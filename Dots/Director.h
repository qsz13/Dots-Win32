#pragma once
#include "Matrix.h"
#include "Line.h"
class Director
{
private:
	Director();
	Director(Director const&);
	void operator=(Director const&);

public:
	static Director& getDirector();
	~Director();
	HWND hWnd;
	HDC hdc;
	void update();
	int mouseX;
	int mouseY;
	bool mouseIsDown;
	void mouseUpEvent();
	void mouseDownEvent();
	bool allowConnect = true;
};

