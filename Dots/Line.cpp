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
		Director::getDirector().addScore(dotVector.size());
		Director::getDirector().allowConnect = false;
		vector<Dot*>::iterator it;
		for (it = this->dotVector.begin(); it != this->dotVector.end(); it++)
		{
			(*it)->visible = false;
			this->hiddenVector.push_back((*it));
		}

		this->dotVector.clear();

		Matrix::getMatrix().dropDots();
		

	}
	else {
		this->dotVector.clear();

	}


}

void Line::update()
{
	this->drawLine();
}