#include "DirectX.h"
#include "PuzzleBlock5.h"
#include "input.h"
#include "main.h"
#include "sprite.h"
#include <stdio.h>


/*------------------------------------------------------------------------------
�\���̐錾
------------------------------------------------------------------------------*/
typedef struct PUZZLE_T
{
	int		Isdisp = false;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 speed = { 0, 1 };
	D3DXVECTOR2 initspeed = { 0, -5.5 };

};


/*------------------------------------------------------------------------------
�O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static PUZZLE_T g_PuzzleBlock5;

static int g_DustTextureIndex;

static int mouse5 = 0;

/*------------------------------------------------------------------------------
�������֐�
------------------------------------------------------------------------------*/
void InitPuzzle5(void)
{
	g_PuzzleBlock5.pos.x = SCREEN_HALFWIDTH + 200;
	g_PuzzleBlock5.pos.y = 0;
	g_PuzzleBlock5.Isdisp = false;

	//�t���p�Xfull path�ł͂Ȃ���
	//���΃p�X���w�肷��
	g_DustTextureIndex = LoadTexture("texture/REIZOUKO.png");


	g_PuzzleBlock5.Isdisp = true;
}

/*------------------------------------------------------------------------------
�I������������֐�
------------------------------------------------------------------------------*/
void UninitPuzzle5()
{

}

/*------------------------------------------------------------------------------
�X�V����������֐�
------------------------------------------------------------------------------*/
void UpdatePuzzle5(HWND hWnd)
{

	g_PuzzleBlock5.pos.y += g_PuzzleBlock5.speed.y;

	POINT mouse_p;
	//�}�E�X�̍��W�Q�b�c
	GetCursorPos(&mouse_p);
	//�}�E�X�̍��W���X�N���[������N���C�A���g(�E�B���h�E)��
	ScreenToClient(hWnd, &mouse_p);


	//�摜�̃{�^���̓����蔻��
	if (mouse_p.x < (g_PuzzleBlock5.pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock5.pos.x - PUZZLEHALF_SIZE_X) &&
		mouse_p.y < (g_PuzzleBlock5.pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock5.pos.y - PUZZLEHALF_SIZE_Y))
	{
		if (mouse5 == 1)
		{
			g_PuzzleBlock5.Isdisp = false;
		}
	}
	else
	{
		mouse5 = 0;
	}

}

/*------------------------------------------------------------------------------
�`�揈��������֐�
------------------------------------------------------------------------------*/

void DrawPuzzle5(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	// ���_�f�[�^
	Vertex2D PuzzleBlock5[] = {
		{//����
			D3DXVECTOR4((float)g_PuzzleBlock5.pos.x - PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock5.pos.y - PUZZLEHALF_SIZE_Y, 0.0f, 1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,0.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_PuzzleBlock5.pos.x + PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock5.pos.y - PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,0.0f),
		},
		{//����
			D3DXVECTOR4((float)g_PuzzleBlock5.pos.x - PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock5.pos.y + PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,1.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_PuzzleBlock5.pos.x + PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock5.pos.y + PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,1.0f),
		}
	};


	//�|���S���ƃe�N�X�`����Ή�������
	LPDIRECT3DTEXTURE9 pTexture;
	//�~�����e�N�X�`���̐����ԍ���`����
	pTexture = GetTexture(g_DustTextureIndex);
	pDevice->SetTexture(0, pTexture);
	pDevice->SetFVF(FVF_VERTEX2D);


	if (g_PuzzleBlock5.Isdisp == true)
	{
		pDevice->DrawPrimitiveUP(
			D3DPT_TRIANGLESTRIP,
			2,
			PuzzleBlock5,
			sizeof(Vertex2D)
		);
	}

}


/*------------------------------------------------------------------------------
�G�̗L���t���O��n��
------------------------------------------------------------------------------*/
bool IsActivePuzzle5(void)
{
	return g_PuzzleBlock5.Isdisp;
}

/*------------------------------------------------------------------------------
�G�̗L���t���O��ݒ肷��
------------------------------------------------------------------------------*/
void SetActivePuzzle5(int flag)
{
	g_PuzzleBlock5.Isdisp = flag;
}

void PuzzleSetMouse5(int index)
{
	mouse5 = index;
}