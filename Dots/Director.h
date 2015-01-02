#pragma once
#include "Matrix.h"
#include "Line.h"
#include "Text.h"


class Director
{
private:
	Director();
	Director(Director const&);
	void operator=(Director const&);
	bool menuScene = false;
	bool gameScene = true;
	int timeLeft = 60;
	bool timerIsCounting = true;
	void gameOver();
	int score;
	void loadTitle();
	bool isPlaying = false;
	void loadText();
	int maxScore;
	int currentScore;

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
	void mouseMove();
	void timerEvent();
	void startGame();
	void stopGame();
	void addScore(int s);
};

