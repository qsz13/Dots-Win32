#include "stdafx.h"
#include "MatrixCoordinate.h"


MatrixCoordinate::MatrixCoordinate(int x, int y)
{
	this->x = x;
	this->y = y;
}
MatrixCoordinate::MatrixCoordinate()
{
	this->x = -1;
	this->y = -1;
}

MatrixCoordinate::~MatrixCoordinate()
{
}
