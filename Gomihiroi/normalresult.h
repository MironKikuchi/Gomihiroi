#pragma once

#define NORMAL_RESULT_FONT_SIZE_X 512 + 256
#define NORMAL_RESULT_FONT_SIZE_Y 512 + 256

#define NORMAL_SCORE_SIZE_X 256 + 256
#define NORMAL_SCORE_SIZE_Y 256 + 256

#define NORMAL_RESULT_BUTTON_SIZE_X 192
#define NORMAL_RESULT_BUTTON_SIZE_Y 96

#define NORMAL_RESULT_BUTTON_HALF_SIZE_X 128
#define NORMAL_RESULT_BUTTON_HALF_SIZE_Y 128

#define EXITBUTTON_SIZE_X 128
#define EXITBUTTON_SIZE_Y 64
#define NORMAL_SCORE_NUMBER_X 20
#define NORMAL_SCORE_NUMBER_Y 180
#define NORMAL_SCORE_NUMBER_WIDTH 20
#define NORMAL_SCORE_NUMBER_SIZE_X 48
#define NORMAL_SCORE_NUMBER_SIZE_Y 60

#define NORMAL_1STFONT_POS_Y 100
#define NORMAL_1ST_POS_Y 100

#define NORMAL_2NDFONT_POS_Y 180
#define NORMAL_2ND_POS_Y 180

#define NORMAL_3RDFONT_POS_Y 260
#define NORMAL_3RD_POS_Y 260

#define NORMAL_4THFONT_POS_Y 340
#define NORMAL_4TH_POS_Y 340

#define NORMAL_5THFONT_POS_Y 420
#define NORMAL_5TH_POS_Y 420

#define NUMBER_SPACE 50

void InitNormalResult(void);
void UninitNormalResult(void);
void UpdateNormalResult(HWND hWnd);
void DrawNormalResult(void);

void NormalResultSetMouse(int index);
void SetNormalScore(int score);
void SaveNormalScore(int score);
int PassNormalScore(void);