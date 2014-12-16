#include "stdafx.h"
#include "Line.h"


Line::Line()
{
	this->hWnd = Director::getDirector().hWnd;
	this->hdc = GetDC(this->hWnd);
}


Line::~Line()
{
}

Line& Line::getLine()
{
	static Line line;
	return line;
}

void Line::drawLine()
{
	AllocConsole();
	FILE *stream;
	freopen_s(&stream, "CONOUT$", "w", stdout);
	std::cout << dotVector.size()<< endl;

	if (dotVector.size() > 1)
	{
		SelectObject(hdc, GetStockObject(DC_PEN));
		HPEN hpen = CreatePen(PS_SOLID, 5, this->dotVector[0]->getColor());
		SelectObject(this->hdc,hpen);
		
		MoveToEx(hdc, (*dotVector[0]).getWindowCoordinate().x, (*dotVector[0]).getWindowCoordinate().y, NULL);
		 
		vector<Dot*>::iterator vertexIterator;

		for (vertexIterator = this->dotVector.begin() + 1;
			vertexIterator != this->dotVector.end();
			vertexIterator++)
		{
			Dot* d = *vertexIterator;
			WindowCoordinate winCoord = d->getWindowCoordinate();
			LineTo(hdc, winCoord.x, winCoord.y);
		}
		if (Director::getDirector().mouseIsDown)
		{
			LineTo(hdc, Director::getDirector().mouseX, Director::getDirector().mouseY);
		}
		DeleteObject(hpen);
	}
	else if (dotVector.size() == 1)
	{
		SelectObject(hdc, GetStockObject(DC_PEN));
		HPEN hpen = CreatePen(PS_SOLID, 5, this->dotVector[0]->getColor());
		SelectObject(this->hdc, hpen);

		MoveToEx(hdc, (*dotVector[0]).getWindowCoordinate().x, (*dotVector[0]).getWindowCoordinate().y, NULL);
		if (Director::getDirector().mouseIsDown)
		{
			LineTo(hdc, Director::getDirector().mouseX, Director::getDirector().mouseY);
		}
		DeleteObject(hpen);
	}
}

void Line::addDot(Dot* dot)
{
	this->dotVector.push_back(dot);
}


void Line::removeLine()
{
	Matrix::getMatrix().mouseIsInDot = false;
	if (this->dotVector.size()>1)
	{
		Director::getDirector().allowConnect = false;
		Matrix *matrix = &Matrix::getMatrix();
		vector<Dot*>::iterator dotIt;
		dotIt = dotVector.begin();
		while (dotIt != dotVector.end()) {
			MatrixCoordinate matrixCoord = (*dotIt)->getMatrixCoordinate();
			matrix->removeDot(matrixCoord.x, matrixCoord.y);
			dotIt++;
		}



	}
	this->dotVector.clear();


}