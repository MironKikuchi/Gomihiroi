#pragma once
#pragma warning(suppress : 5208)

#define BOOK_SIZE_X 48
#define BOOK_SIZE_Y 48
#define BOOKCOUNT_SIZE 15

#define SCREEN_TOP 0


void InitBook(void);
void SetRandomBookPos(int index);
void UninitBook(void);
void UpdateBook(HWND hWnd);
void DrawBook(void);


void BookSetMouse(int index);