#pragma once
#pragma warning(suppress : 5208)

#define TRASH_SIZE_X 64
#define TRASH_SIZE_Y 64
#define TRASHCOUNT_SIZE 15

#define SCREEN_TOP 0

void InitTrash(void);
void SetRandomTrash(int index);
void UninitTrash(void);
void UpdateTrash(HWND hWnd);
void DrawTrash(void);

void TrashSetMouse(int index);