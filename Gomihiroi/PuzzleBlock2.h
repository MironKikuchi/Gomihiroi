#pragma once
#pragma warning(suppress : 5208)

#define BANANA_SIZE_X 32
#define BANANA_SIZE_Y 32
#define BANANACOUNT_SIZE 15

#define SCREEN_TOP 0


void InitBanana(void);
void SetRandomBananaPos(int index);
void UninitBanana(void);
void UpdateBanana(HWND hWnd);
void DrawBanana(void);


void BananaSetMouse(int index);