#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define TIME_SIZE_X 256
#define TIME_SIZE_Y 144

#define TIMEFONT_SIZE_X 110
#define TIMEFONT_SIZE_Y 7
#define TIME_WAKU_WIDTH 100
#define TIME_WAKU_HEIGHT 20


#define TIMEFONT_POS_X SCREEN_HALFWIDTH	+ 120	//制限時間ゲージの表示座標X
#define TIMEFONT_POS_Y 100					//制限時間ゲージの表示座標Y

#define TIME_NUMBER_MAX 4
#define TIME_LIMIT 180

void InitTime(void);
void UninitTime(void);
void UpdateTime(int addpenalty);
void DrawTime(void);
void HighScoreJudge(int highscore); 
void NormalScoreJudge(int normalscore);