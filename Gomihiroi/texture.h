#pragma once

#include <d3dx9.h>

int LoadTexture(char* fileName);
void UninitTexture(void);

LPDIRECT3DTEXTURE9 GetTexture(int index);
