#include "stdafx.h"
#include "Director.h"
#include "DotColor.h"
#include <stdio.h>
#include <string>

Director::Director()
{

}


Director::~Director()
{

}

Director& Director::getDirector()
{
	static Director director;
	return director;
}

void Director::mouseMove()
{
	if (this->mouseIsDown && allowConnect && gameScene && isPlaying)
	{
		Matrix::getMatrix().addDotInLine(mouseX, mouseY);
	}

}

void Director::update()
{
	Text::getText().loadText(timeLeft,currentScore,maxScore);
	Line::getLine().update();
	Matrix::getMatrix().update();
	SetTimer(hWnd, 1, 1000, NULL);
}



void Director::mouseUpEvent()
{
	this->mouseIsDown = false;
	Line::getLine().removeLine();
}

void Director::mouseDownEvent()
{
	this->mouseIsDown = true;
}

void Director::timerEvent()
{
	
	if (isPlaying)
	{
		
		if (timeLeft > 0)
		{
			timeLeft--;
			
		}
		else
		{
			gameOver();
		}
		
	}


}

void Director::gameOver()
{
	timerIsCounting = false;
	isPlaying = false;
	TCHAR buf[100];
	_stprintf_s(buf, "��Ϸ��������ǰ�÷�:%d", currentScore);
	MessageBox(hWnd, buf, "", MB_OK);
	if (currentScore > maxScore)
	{
		maxScore = currentScore;
	}

}


void Director::startGame()
{
	
	if (!isPlaying)
	{
		this->timeLeft = 60;
		currentScore = 0;
		timerIsCounting = true;
		Matrix::getMatrix().newMatrix();
		isPlaying = true;
	}
}

void Director::stopGame()
{
	if (isPlaying)
	{
		timerIsCounting = false;
		isPlaying = false;
		gameOver();
		
	}
	
}



void Director::addScore(int s)
{
	currentScore += s;
	if (currentScore > maxScore)
	{
		maxScore = currentScore;
	}
}