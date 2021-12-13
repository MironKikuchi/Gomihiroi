#include "DirectX.h"
#include "PuzzleBlock4.h"
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
static PUZZLE_T g_PuzzleBlock4;

static int g_DustTextureIndex;

static int mouse4 = 0;

/*------------------------------------------------------------------------------
�������֐�
------------------------------------------------------------------------------*/
void InitPuzzle4(void)
{
	g_PuzzleBlock4.pos.x = SCREEN_HALFWIDTH + 100;
	g_PuzzleBlock4.pos.y = 0;
	g_PuzzleBlock4.Isdisp = false;

	//�t���p�Xfull path�ł͂Ȃ���
	//���΃p�X���w�肷��
	g_DustTextureIndex = LoadTexture("texture/Gomi.jpg");


	g_PuzzleBlock4.Isdisp = true;
}

/*------------------------------------------------------------------------------
�I������������֐�
------------------------------------------------------------------------------*/
void UninitPuzzle4()
{

}

/*------------------------------------------------------------------------------
�X�V����������֐�
------------------------------------------------------------------------------*/
void UpdatePuzzle4(HWND hWnd)
{

	g_PuzzleBlock4.pos.y += g_PuzzleBlock4.speed.y;

	POINT mouse_p;
	//�}�E�X�̍��W�Q�b�c
	GetCursorPos(&mouse_p);
	//�}�E�X�̍��W���X�N���[������N���C�A���g(�E�B���h�E)��
	ScreenToClient(hWnd, &mouse_p);

	char str[256];
	sprintf_s(str, "PosX: %d PosY: %d \n", mouse_p.x, mouse_p.y);
	OutputDebugString(str);


	//�摜�̃{�^���̓����蔻��
	if (mouse_p.x < (g_PuzzleBlock4.pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock4.pos.x - PUZZLEHALF_SIZE_X) &&
		mouse_p.y < (g_PuzzleBlock4.pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock4.pos.y - PUZZLEHALF_SIZE_Y))
	{
		if (mouse4 == 1)
		{
			g_PuzzleBlock4.Isdisp = false;
		}
	}
	else
	{
		mouse4 = 0;
	}

}

/*------------------------------------------------------------------------------
�`�揈��������֐�
------------------------------------------------------------------------------*/

void DrawPuzzle4(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	// ���_�f�[�^
	Vertex2D PuzzleBlock3[] = {
		{//����
			D3DXVECTOR4((float)g_PuzzleBlock4.pos.x - PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock4.pos.y - PUZZLEHALF_SIZE_Y, 0.0f, 1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,0.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_PuzzleBlock4.pos.x + PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock4.pos.y - PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,0.0f),
		},
		{//����
			D3DXVECTOR4((float)g_PuzzleBlock4.pos.x - PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock4.pos.y + PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,1.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_PuzzleBlock4.pos.x + PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock4.pos.y + PUZZLEHALF_SIZE_Y,0.0f,1.0f),
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


	if (g_PuzzleBlock4.Isdisp == true)
	{
		pDevice->DrawPrimitiveUP(
			D3DPT_TRIANGLESTRIP,
			2,
			PuzzleBlock3,
			sizeof(Vertex2D)
		);
	}

}


/*------------------------------------------------------------------------------
�G�̗L���t���O��n��
------------------------------------------------------------------------------*/
bool IsActivePuzzle4(void)
{
	return g_PuzzleBlock4.Isdisp;
}

/*------------------------------------------------------------------------------
�G�̗L���t���O��ݒ肷��
------------------------------------------------------------------------------*/
void SetActivePuzzle4(int flag)
{
	g_PuzzleBlock4.Isdisp = flag;
}

bool PuzzleGetMouse4(int index)
{
	mouse4 = index;
	return 0;
}