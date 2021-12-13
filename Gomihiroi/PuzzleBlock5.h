#pragma once
#pragma warning(suppress : 5208)

#include "PuzzleBlock.h"


void InitPuzzle5(void);
void UninitPuzzle5(void);
void UpdatePuzzle5(HWND hWnd);
void DrawPuzzle5(void);

bool IsActivePuzzle5(void);
void SetActivePuzzle5(int flag);
bool PuzzleGetMouse5(int index);