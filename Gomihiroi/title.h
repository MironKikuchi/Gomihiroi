#pragma once


#define TITLEFONT_SIZE_X 256 + 256
#define TITLEFONT_SIZE_Y 256 + 256
#define TITLEBUTTON_SIZE_X 192
#define TITLEBUTTON_SIZE_Y 96

#define TITLEBG_HALF_SIZE_X 225
#define TITLEBG_HALF_SIZE_Y 400
#define TITLEBUTTON_HALF_SIZE_X 96  
#define TITLEBUTTON_HALF_SIZE_Y 48

void InitTitle(void);
void UninitTitle(void);
void UpdateTitle(HWND hWnd);
void DrawTitle(void);

void TitleSetMouse(int index);