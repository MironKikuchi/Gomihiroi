#pragma once

#include <d3dx9.h>
// �E�B���h�E�̃T�C�Y
#define SCREEN_WIDTH  540	//��
#define SCREEN_HEIGHT 960	//����
#define SCREEN_HALFWIDTH  270	//��
#define SCREEN_HALFHEIGHT 480	//����

//620 924

// �QD�|���S�����_�\����
typedef struct Vertex2D_tag
{
	D3DXVECTOR4 position; // ���_���W�i���W�ϊ��ςݒ��_�j
	D3DCOLOR	color;
	D3DXVECTOR2 texCoord;
} Vertex2D;
#define FVF_VERTEX2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1) // �QD�|���S�����_�t�H�[�}�b�g

int MousePointerPos();