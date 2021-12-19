#pragma once

#define SCORE_SIZE_X 256
#define SCORE_SIZE_Y 144

#define SCORE_FONT_SIZE_X 24
#define SCORE_FONT_SIZE_Y 30

#define SCORE_NUMBER_X 20
#define SCORE_NUMBER_Y 10

#define SCORE_FONT_POS_X SCREEN_HALFWIDTH + 100		//スコアの表示座標X
#define SCORE_FONT_POS_Y SCREEN_HALFHEIGHT * 2 -100	//スコアの表示座標Y

#define SCORE_MAX 7
#define SCORE_NUMBER_MAX 7

void InitScore(void);
void UninitScore(void);
void UpdateScore(int addScore);
void DrawScore(void);