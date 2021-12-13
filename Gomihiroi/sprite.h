#pragma once

#include <d3d9.h>
#include "texture.h"

//同じ名前で引数の違う関数を作れる。関数のオーバーロードという
void DrawSprite(int texture_index, float posx, float posy, float width, float height);

void DrawSprite(int texture_index, float posx, float posy, float width, float height, float tx, float ty, float tw, float th);

void DrawSpriteColor(int texture_index, float posx, float posy, float width, float height, float tx, float ty, float tw, float th, D3DXCOLOR color);
