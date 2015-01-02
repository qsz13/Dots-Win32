#pragma once
#include "Matrix.h"
#include "Line.h"
#include "Text.h"
#include <Mmsystem.h>


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
	
	MCIDEVICEID  dev[20];
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;

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
	void playBackgroundMusic();
};

