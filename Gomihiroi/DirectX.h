#pragma once

#include <windows.h>
#include <d3dx9.h>

bool Initialize(HWND hWnd);

LPDIRECT3DDEVICE9 GetDevice();

void ClearBuffer(void);
void SetClearColor(BYTE r, BYTE g, BYTE b);