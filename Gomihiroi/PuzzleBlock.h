#pragma once
#pragma warning(suppress : 5208)


#define DUST_SIZE_X 64
#define DUST_SIZE_Y 64
#define DUSTCOUNT_SIZE 100

#define SCREEN_TOP 0


void InitDust(void);
void SetRandomDustPos(int index);
void UninitDust(void);
void UpdateDust(HWND hWnd);
void DrawDust(void);


void DustSetMouse(int index);