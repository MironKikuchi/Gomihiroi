#pragma once

#define HIGH_RESULTFONT_SIZE_X 256
#define HIGH_RESULTFONT_SIZE_Y 144
#define HIGH_RESULTBUTTON_SIZE_X 192
#define HIGH_RESULTBUTTON_SIZE_Y 96

#define HIGH_RESULTBUTTON_HALF_SIZE_X 96  
#define HIGH_RESULTBUTTON_HALF_SIZE_Y 48

#define EXITBUTTON_SIZE_X 128
#define EXITBUTTON_SIZE_Y 64

#define HIGH_1STFONT_POS_Y 100
#define HIGH_1ST_POS_Y 100

#define HIGH_2NDFONT_POS_Y 180
#define HIGH_2ND_POS_Y 180

#define HIGH_3RDFONT_POS_Y 260
#define HIGH_3RD_POS_Y 260

#define HIGH_4THFONT_POS_Y 340
#define HIGH_4TH_POS_Y 340

#define HIGH_5THFONT_POS_Y 420
#define HIGH_5TH_POS_Y 420

void InitHighResult(void);
void UninitHighResult(void);
void UpdateHighResult(HWND hWnd);
void DrawHighResult(void);

void HighResultSetMouse(int index);
void SetScore(int index);