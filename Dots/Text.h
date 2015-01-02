#pragma once
#include "Director.h"

class Text
{
private:
	HWND hWnd;
	Text();
	void loadTitle();

public:
	static Text& getText();
	~Text();

	void loadText(int timeLeft, int currentScore, int maxScore);
};

