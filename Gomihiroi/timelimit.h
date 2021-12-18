#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define TIME_SIZE_X 256
#define TIME_SIZE_Y 144

#define TIMEFONT_SIZE_X 180
#define TIMEFONT_SIZE_Y 20

#define TIMEFONT_POS_X SCREEN_HALFWIDTH //スコアの表示座標X
#define TIMEFONT_POS_Y SCREEN_HALFHEIGHT * 2 -200	//スコアの表示座標Y

#define TIME_NUMBER_MAX 4
#define TIME_LIMIT 180

void InitTime(void);
void UninitTime(void);
void UpdateTime(int addpenalty);
void DrawTime(void);