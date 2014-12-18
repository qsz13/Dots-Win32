#pragma once
#include <vector>
#include "Dot.h"
#include "DotType.h"
#include "DotFactory.h"
#include "MatrixCoordinate.h"
#include <cmath>

using namespace std;
class Dot;
class Matrix
{
private:
	vector<vector<Dot *>> matrix;
	Matrix();
	Matrix(Matrix const&);
	void operator=(Matrix const&);
	void initMatrix();
	bool Matrix::mouseInDot(int mouseX, int mouseY, Dot *dot);
	
	Dot* lastVistedDot;
	bool sameColor(Dot* dot1, Dot * dot2);
	bool isNeighbour(Dot* dot1, Dot *dot2);
	bool alreadyVisited(Dot* dot);
	void drop(Dot *dot);
	vector<Dot*> dropVec;
	vector<Dot*> movedVec;
	void clearDropStep();


public:
	bool mouseIsInDot = false;
	static Matrix& getMatrix();
	~Matrix();
	int x;
	int y;
	int interval;
	Dot* Matrix::getDot(MatrixCoordinate coor);
	Dot* getDot(int x, int y);
	void drawMatrix();
	void addDotInLine(int mouseX, int mouseY);
	Dot* Matrix::getNearestDot(int mouseX, int mouseY);
	void removeDot(int x, int y);
	void dropDots();

};

