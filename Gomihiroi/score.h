#pragma once

#define SCORE_SIZE_X 256
#define SCORE_SIZE_Y 144

#define SCOREFONT_SIZE_X 48
#define SCOREFONT_SIZE_Y 60

#define SCOREFONT_POS_X SCREEN_HALFWIDTH + 30 + (35 * g_Shift)	//スコアの表示座標X
#define SCOREFONT_POS_Y SCREEN_HALFHEIGHT * 2 -100	//スコアの表示座標Y

#define SCORE_MAX 7

void InitScore(void);
void UninitScore(void);
void UpdateScore(void);
void DrawScore(void);

int SetScorePoint(int index);