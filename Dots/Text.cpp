#include "stdafx.h"
#include "Text.h"


Text::Text()
{
	this->hWnd = Director::getDirector().hWnd;
}


Text::~Text()
{
}

Text& Text::getText()
{
	static Text text;
	return text;
}

void Text::loadTitle()
{
	HDC hdc = GetDC(this->hWnd);

	SetBkMode(hdc, TRANSPARENT);
	LOGFONT   logfont;
	ZeroMemory(&logfont, sizeof(LOGFONT));
	logfont.lfCharSet = CP_UTF8;
	logfont.lfHeight = 80;
	HFONT   hFont = CreateFontIndirect(&logfont);
	SelectObject(hdc, hFont);

	TCHAR buffer[10];

	LPCTSTR made;
	made = buffer;
	SetTextColor(hdc, GREEN_DOT);
	int D = sprintf_s(buffer, 10, "D");
	TextOut(hdc, 230, 50, made, D);
	SetTextColor(hdc, YELLOW_DOT);
	int o = sprintf_s(buffer, 10, "o");
	TextOut(hdc, 300, 50, made, o);
	SetTextColor(hdc, RED_DOT);
	int t = sprintf_s(buffer, 10, "t");
	TextOut(hdc, 360, 50, made, t);
	SetTextColor(hdc, BLUE_DOT);
	int s = sprintf_s(buffer, 10, "s");
	TextOut(hdc, 400, 50, made, s);

	DeleteObject(hFont);

}

void Text::loadText(int timeLeft, int currentScore, int maxScore)
{
	loadTitle();
	HDC hdc = GetDC(this->hWnd);

	SetBkMode(hdc, TRANSPARENT);
	LOGFONT   logfont;
	ZeroMemory(&logfont, sizeof(LOGFONT));
	logfont.lfCharSet = CP_UTF8;
	logfont.lfHeight = 30;
	HFONT   hFont = CreateFontIndirect(&logfont);
	SelectObject(hdc, hFont);

	TCHAR buffer[100];

	LPCTSTR made;
	made = buffer;
	SetTextColor(hdc, RGB(0, 0, 0));

	int timeText = sprintf_s(buffer, 100, "倒计时：%ds", timeLeft);

	TextOut(hdc, 560, 300, made, timeText);


	int currentScoreText = sprintf_s(buffer, 100, "得分：%d", currentScore);

	TextOut(hdc, 560, 350, made, currentScoreText);


	int maxScoreText = sprintf_s(buffer, 100, "最高分：%d", maxScore);

	TextOut(hdc, 560, 400, made, maxScoreText);

	int s = sprintf_s(buffer, 100, "按下S开始游戏");
	TextOut(hdc, 560, 150, made, s);
	int q = sprintf_s(buffer, 100, "按下Q结束游戏");
	TextOut(hdc, 560, 200, made, q);

	DeleteObject(hFont);
}