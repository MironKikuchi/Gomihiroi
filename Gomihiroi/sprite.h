#pragma once

#include <d3d9.h>
#include "texture.h"

//�������O�ň����̈Ⴄ�֐�������B�֐��̃I�[�o�[���[�h�Ƃ���
void DrawSprite(int texture_index, float posx, float posy, float width, float height);

void DrawSprite(int texture_index, float posx, float posy, float width, float height, float tx, float ty, float tw, float th);

void DrawSpriteColor(int texture_index, float posx, float posy, float width, float height, float tx, float ty, float tw, float th, D3DXCOLOR color);
