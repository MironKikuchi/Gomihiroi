#pragma once
#pragma warning(suppress : 5208)

#include "PuzzleBlock.h"


void InitPuzzle2(void);
void UninitPuzzle2(void);
void UpdatePuzzle2(HWND hWnd);
void DrawPuzzle2(void);

bool IsActivePuzzle2(void);
void SetActivePuzzle2(int flag);
bool PuzzleGetMouse2(int index);