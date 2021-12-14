#pragma once
#pragma warning(suppress : 5208)

//#include "collision.h"

#define PUZZLE_SIZE_X 32
#define PUZZLE_SIZE_Y 32
#define PUZZLEHALF_SIZE_X 16
#define PUZZLEHALF_SIZE_Y 16
#define PUZZLECOUNT_SIZE 20


void InitPuzzle(void);
void UninitPuzzle(void);
void UpdatePuzzle(HWND hWnd);
void DrawPuzzle(void);

//COLBOX GetColBoxEnemy(void);
//D3DXVECTOR2 EnemyPosition(void);
bool IsActivePuzzle(void);
void SetActivePuzzle(int flag);
bool PuzzleGetMouse(int index);