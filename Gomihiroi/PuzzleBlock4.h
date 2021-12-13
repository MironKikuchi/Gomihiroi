#pragma once
#pragma warning(suppress : 5208)

#include "PuzzleBlock.h"


void InitPuzzle4(void);
void UninitPuzzle4(void);
void UpdatePuzzle4(HWND hWnd);
void DrawPuzzle4(void);

bool IsActivePuzzle4(void);
void SetActivePuzzle4(int flag);
bool PuzzleGetMouse4(int index);