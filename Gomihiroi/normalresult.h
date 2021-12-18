#pragma once

#define NORMAL_RESULTFONT_SIZE_X 256
#define NORMAL_RESULTFONT_SIZE_Y 144
#define NORMAL_RESULTBUTTON_SIZE_X 192
#define NORMAL_RESULTBUTTON_SIZE_Y 96

#define NORMAL_RESULTBUTTON_HALF_SIZE_X 96  
#define NORMAL_RESULTBUTTON_HALF_SIZE_Y 48

void InitNormalResult(void);
void UninitNormalResult(void);
void UpdateNormalResult(HWND hWnd);
void DrawNormalResult(void);

void NormalResultSetMouse(int index);