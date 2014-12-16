#include "stdafx.h"
#include "Matrix.h"
typedef std::vector<Dot*> DotVector;
typedef std::vector<DotVector> VecVector;



Matrix::Matrix()
{
	this->initMatrix();
	this->x = 50;
	this->y = 50;
	this->interval = 50;
}


Matrix::~Matrix()
{
}

void Matrix::initMatrix()
{
	for (int i = 0; i < 6; i++)
	{
		this->matrix.push_back(vector<Dot*>());
		for (int j = 0; j < 6; j++)
		{
			Dot *newDot = DotFactory::getRandomDot();
			newDot->setMatrixCoordinate(i, j);
			this->matrix[i].push_back(newDot);
		}
	}

}

Matrix& Matrix::getMatrix()
{
	static Matrix matrix;
	return matrix;
}


void Matrix::drawMatrix()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			Dot *dot = this->matrix[i][j];
			if (dot != NULL)
			{
				dot->drawDot();
			}
			
		}
	}
}




Dot* Matrix::getNearestDot(int mouseX, int mouseY)
{



	float tempX = (float)mouseX / this->interval;
	float tempY = (float)mouseY / this->interval;
	int dotX = tempX + 0.5;
	int dotY = tempY + 0.5;

	if (dotX > 6)
	{
		dotX = 5;
	}
	else if (dotX < 1)
	{
		dotX = 0;
	}
	else
	{
		dotX--;
	}
	if (dotY > 6)
	{
		dotY = 5;
	}
	else if (dotY < 1)
	{
		dotY = 0;
	}
	else
	{
		dotY--;
	}

	MatrixCoordinate matrixCoord;
	matrixCoord.x = dotX;
	matrixCoord.y = dotY;




	return getDot(matrixCoord);
}


bool Matrix::mouseInDot(int mouseX, int mouseY, Dot* dot)
{
	int distanceX = mouseX - dot->getWindowCoordinate().x;
	int distanceY = mouseY - dot->getWindowCoordinate().y;
	int size = dot->getSize();


	if ((distanceX*distanceX + distanceY*distanceY < size*size/4))
	{

		return true;
	}
	else
	{

		mouseIsInDot = false;
		return false;
	}
}


void Matrix::addDotInLine(int mouseX, int mouseY)
{


	Dot* nearestDot = getNearestDot(mouseX, mouseY);

		if (mouseInDot(mouseX, mouseY, nearestDot))
		{
			if (mouseIsInDot == false)
			{
				mouseIsInDot = true;
				int size = Line::getLine().dotVector.size();
				if (Line::getLine().dotVector.size()>0)
				{
					if (nearestDot == Line::getLine().dotVector[size - 1])
					{
						Line::getLine().dotVector.pop_back();
					}
					else if (sameColor(nearestDot, Line::getLine().dotVector[0]) && isNeighbour(nearestDot, Line::getLine().dotVector[size - 1]) && (!alreadyVisited(nearestDot)))
					{
							Line::getLine().addDot(nearestDot);
					}
				}
				else
				{
					Line::getLine().addDot(nearestDot);
				}
			}

			
		}

}

bool Matrix::alreadyVisited(Dot * dot)
{
	return std::find(Line::getLine().dotVector.begin(), Line::getLine().dotVector.end(), dot) != Line::getLine().dotVector.end();

}


bool Matrix::sameColor(Dot *dot1, Dot *dot2)
{
	return dot1->dotType == dot2->dotType;
}

bool Matrix::isNeighbour(Dot *dot1, Dot *dot2)
{
	return (abs(dot1->getMatrixCoordinate().x - dot2->getMatrixCoordinate().x) + abs(dot1->getMatrixCoordinate().y - dot2->getMatrixCoordinate().y)) == 1;
}


Dot* Matrix::getDot(MatrixCoordinate coor)
{
	return matrix[coor.x][coor.y];
}

void Matrix::removeDot(int x, int y)
{
	delete matrix[x][y];
	matrix[x][y] = NULL;

}

