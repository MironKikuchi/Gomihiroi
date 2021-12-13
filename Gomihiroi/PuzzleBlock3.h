#pragma once
#pragma warning(suppress : 5208)

#include "PuzzleBlock.h"


void InitPuzzle3(void);
void UninitPuzzle3(void);
void UpdatePuzzle3(HWND hWnd);
void DrawPuzzle3(void);

bool IsActivePuzzle3(void);
void SetActivePuzzle3(int flag);
bool PuzzleGetMouse3(int index);