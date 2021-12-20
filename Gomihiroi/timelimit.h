#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define TIME_SIZE_X 256
#define TIME_SIZE_Y 144

#define TIME_IMAGE_X SCREEN_HALFWIDTH + 45
#define TIME_IMAGE_Y 80
#define TIME_IMAGE_WIDTH 128
#define TIME_IMAGE_HEIGHT 128

#define TIMEFONT_SIZE_X 110
#define TIMEFONT_SIZE_Y 7
#define TIME_WAKU_WIDTH 100
#define TIME_WAKU_HEIGHT 20


#define TIMEFONT_POS_X SCREEN_HALFWIDTH	+ 120	//�������ԃQ�[�W�̕\�����WX
#define TIMEFONT_POS_Y 100					//�������ԃQ�[�W�̕\�����WY

#define TIME_NUMBER_MAX 4
#define TIME_LIMIT 60

void InitTime(void);
void UninitTime(void);
void UpdateTime(int addpenalty);
void DrawTime(void);
void HighScoreJudge(int highscore); 
void NormalScoreJudge(int normalscore);