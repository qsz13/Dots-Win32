#include "stdafx.h"
#include "DotFactory.h"


DotFactory::DotFactory()
{
	
}


DotFactory::~DotFactory()
{
}

Dot* DotFactory::getRandomDot()
{

	Dot* newDot;


	int r = std::rand()%5;

	switch (r)
	{
	case 0:
		newDot = DotFactory::getBlueDot();
		break;
	case 1:
		newDot = DotFactory::getGreenDot();
		break;
	case 2:
		newDot = DotFactory::getPurpleDot();
		break;
	case 3:
		newDot = DotFactory::getRedDot();
		break;
	case 4:
		newDot = DotFactory::getYellowDot();
		break;
	default:
		newDot = DotFactory::getBlueDot();
		break;
	}
	return newDot;
}

Dot* DotFactory::getBlueDot()
{
	Dot* blueDot = new Dot(BlueDot);
	return blueDot;
}

Dot* DotFactory::getGreenDot()
{
	Dot* greenDot = new Dot(GreenDot);
	return greenDot;
}
Dot* DotFactory::getPurpleDot()
{
	Dot* purpleDot = new Dot(PurpleDot);
	return purpleDot;
}
Dot* DotFactory::getRedDot()
{
	Dot* redDot = new Dot(RedDot);
	return redDot;
}
Dot* DotFactory::getYellowDot()
{
	Dot* yellowDot = new Dot(YellowDot);
	return yellowDot;
}

