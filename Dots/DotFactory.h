#pragma once

#include "Dot.h"
#include "DotType.h"
#include <ctime>


class Dot;
class BlueDot;

class DotFactory
{
public:
	DotFactory();
	~DotFactory();
	static Dot* getRandomDot();
private:
	static Dot* getBlueDot();
	static Dot* getGreenDot();
	static Dot* getPurpleDot();
	static Dot* getRedDot();
	static Dot* getYellowDot();

};

