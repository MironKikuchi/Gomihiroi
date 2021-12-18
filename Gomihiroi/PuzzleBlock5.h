#pragma once
#pragma warning(suppress : 5208)

#define FRIDGE_SIZE_X 80
#define FRIDGE_SIZE_Y 80
#define FRIDGECOUNT_SIZE 15

#define SCREEN_TOP 0

void InitFridge(void);
void SetRandomFridge(int index);
void UninitFridge(void);
void UpdateFridge(HWND hWnd);
void DrawFridge(void);

void FridgeSetMouse(int index);