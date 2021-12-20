#pragma once
#pragma warning(suppress : 5208)


#define DUST_SIZE_X 64
#define DUST_SIZE_Y 64

//#define DUST_COUNT_SIZE 100

#define UP_DUST_COUNT_SIZE 10
#define DOWN_DUST_COUNT_SIZE 10
#define RIGHT_DUST_COUNT_SIZE 10
#define LEFT_DUST_COUNT_SIZE 10



void InitDust(void);
//void SetDustPos(int index);
void SetDustDownPos(int index);
void SetDustUpPos(int index);
void SetDustRightPos(int index);
void SetDustLeftPos(int index);
void SetDustDownSpeed(int index);
void SetDustUpSpeed(int index);
void SetDustRightSpeed(int index);
void SetDustLeftSpeed(int index);
void UninitDust(void);
void UpdateDust(HWND hWnd);
void DrawDust(void);


void DustSetMouse(int index);