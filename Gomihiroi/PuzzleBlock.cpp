#include "DirectX.h"
#include "PuzzleBlock.h"
#include "input.h"
#include "main.h"
#include "sprite.h"
//#include "collision.h"
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
	//COLBOX	colBox;



};


/*------------------------------------------------------------------------------
�O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static PUZZLE_T g_PuzzleBlock1;
static PUZZLE_T g_PuzzleBlock2;
static PUZZLE_T g_PuzzleBlock3;
static PUZZLE_T g_PuzzleBlock4;
static PUZZLE_T g_PuzzleBlock5;

static int g_TextureIndex;
static int g_DustTextureIndex;
static int g_BananaTextureIndex;
static int g_GomiTextureIndex;
static int g_ReizoukoTextureIndex;
static int mouse = 0;

/*------------------------------------------------------------------------------
�������֐�
------------------------------------------------------------------------------*/
void InitPuzzle(void)
{
	g_PuzzleBlock1.pos.x = SCREEN_HALFWIDTH - 200;
	g_PuzzleBlock1.pos.y = 0;
	g_PuzzleBlock1.Isdisp = false;

	g_PuzzleBlock2.pos.x = SCREEN_HALFWIDTH - 100;
	g_PuzzleBlock2.pos.y = 0;
	g_PuzzleBlock2.Isdisp = false;

	g_PuzzleBlock3.pos.x = SCREEN_HALFWIDTH;
	g_PuzzleBlock3.pos.y = 0;
	g_PuzzleBlock3.Isdisp = false;

	g_PuzzleBlock4.pos.x = SCREEN_HALFWIDTH + 100;
	g_PuzzleBlock4.pos.y = 0;
	g_PuzzleBlock4.Isdisp = false;

	g_PuzzleBlock5.pos.x = SCREEN_HALFWIDTH; +200;
	g_PuzzleBlock5.pos.y = 0;
	g_PuzzleBlock5.Isdisp = false;


	//�t���p�Xfull path�ł͂Ȃ���
	//���΃p�X���w�肷��
	g_TextureIndex = LoadTexture("texture/enemy.png");
	g_DustTextureIndex = LoadTexture("texture/Hokori.jpg");
	g_BananaTextureIndex = LoadTexture("texture/banana_peel.png");
	g_GomiTextureIndex = LoadTexture("texture/Gomi.png");
	g_ReizoukoTextureIndex = LoadTexture("texture/REIZOUKO.png");

	/*g_PuzzleBlock1.colBox.width =  PUZZLE_SIZE_X;
	g_PuzzleBlock1.colBox.height =  PUZZLE_SIZE_Y;*/

	g_PuzzleBlock1.Isdisp = true;
}

/*------------------------------------------------------------------------------
�I������������֐�
------------------------------------------------------------------------------*/
void UninitPuzzle()
{

}

/*------------------------------------------------------------------------------
�X�V����������֐�
------------------------------------------------------------------------------*/
void UpdatePuzzle(HWND hWnd)
{
	g_PuzzleBlock1.pos.y += g_PuzzleBlock1.speed.y;
	g_PuzzleBlock2.pos.y += g_PuzzleBlock2.speed.y;
	g_PuzzleBlock3.pos.y += g_PuzzleBlock3.speed.y;
	g_PuzzleBlock4.pos.y += g_PuzzleBlock4.speed.y;
	g_PuzzleBlock5.pos.y += g_PuzzleBlock5.speed.y;

	POINT mouse_p;
	//�}�E�X�̍��W�Q�b�c
	GetCursorPos(&mouse_p);
	//�}�E�X�̍��W���X�N���[������N���C�A���g(�E�B���h�E)��
	ScreenToClient(hWnd, &mouse_p);

	char str[256];
	sprintf_s(str, "PosX: %d PosY: %d \n", mouse_p.x, mouse_p.y);
	OutputDebugString(str);

	//�摜�̃{�^���̓����蔻��
	if (mouse_p.x < (g_PuzzleBlock1.pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock1.pos.x - PUZZLEHALF_SIZE_X) &&
		mouse_p.y < (g_PuzzleBlock1.pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock1.pos.y - PUZZLEHALF_SIZE_Y) )
	{
		if (mouse == 1)
		{
			g_PuzzleBlock1.Isdisp = false;
		}
	}

	//�摜�̃{�^���̓����蔻��
	if (mouse_p.x < (g_PuzzleBlock2.pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock2.pos.x - PUZZLEHALF_SIZE_X) &&
		mouse_p.y < (g_PuzzleBlock2.pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock2.pos.y - PUZZLEHALF_SIZE_Y))
	{
		if (mouse == 1)
		{
			g_PuzzleBlock1.Isdisp = false;
		}
	}

	//�摜�̃{�^���̓����蔻��
	if (mouse_p.x < (g_PuzzleBlock3.pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock3.pos.x - PUZZLEHALF_SIZE_X) &&
		mouse_p.y < (g_PuzzleBlock3.pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock3.pos.y - PUZZLEHALF_SIZE_Y))
	{
		if (mouse == 1)
		{
			g_PuzzleBlock1.Isdisp = false;
		}
	}

	//�摜�̃{�^���̓����蔻��
	if (mouse_p.x < (g_PuzzleBlock4.pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock4.pos.x - PUZZLEHALF_SIZE_X) &&
		mouse_p.y < (g_PuzzleBlock4.pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock4.pos.y - PUZZLEHALF_SIZE_Y))
	{
		if (mouse == 1)
		{
			g_PuzzleBlock1.Isdisp = false;
		}
	}

	//�摜�̃{�^���̓����蔻��
	if (mouse_p.x < (g_PuzzleBlock5.pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock5.pos.x - PUZZLEHALF_SIZE_X) &&
		mouse_p.y < (g_PuzzleBlock5.pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock5.pos.y - PUZZLEHALF_SIZE_Y))
	{
		if (mouse == 1)
		{
			g_PuzzleBlock1.Isdisp = false;
		}
	}


	/*g_PuzzleBlock1.colBox.posx = g_PuzzleBlock1.pos.x;
	g_PuzzleBlock1.colBox.posy = g_PuzzleBlock1.pos.y;*/

	/*if (g_PuzzleBlock1.dispSwitch == 0)
	{
		OutputDebugString("0�������Ă��");
		g_PuzzleBlock1.colBox.posx = -64;
		g_PuzzleBlock1.colBox.posy = -64;
		g_PuzzleBlock1.colBox.width = 0;
		g_PuzzleBlock1.colBox.height = 0;
	}*/

}

/*------------------------------------------------------------------------------
�`�揈��������֐�
------------------------------------------------------------------------------*/

void DrawPuzzle(void)
{
	/*if (g_Enemy.dispSwitch == 1)
	{
		pDevice->DrawPrimitiveUP(
			D3DPT_TRIANGLESTRIP,
			2,
			v,
			sizeof(Vertex2D)
		);
	}
	DrawSprite(g_DustTextureIndex,
		SCREEN_HALFWIDTH,SCREEN_HALFHEIGHT,
		PUZZLE_SIZE_X, PUZZLE_SIZE_Y,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_BananaTextureIndex,
		SCREEN_HALFWIDTH - 150,SCREEN_HALFHEIGHT,
		PUZZLE_SIZE_X, PUZZLE_SIZE_Y,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_TextureIndex,
		SCREEN_HALFWIDTH + 150, SCREEN_HALFHEIGHT,
		PUZZLE_SIZE_X, PUZZLE_SIZE_Y,
		0.0f, 0.0f,
		1.0f, 1.0f);*/

	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	// ���_�f�[�^
	Vertex2D v[] = {
		{//����
			D3DXVECTOR4((float)g_PuzzleBlock1.pos.x - PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1.pos.y - PUZZLEHALF_SIZE_Y, 0.0f, 1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,0.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_PuzzleBlock1.pos.x + PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1.pos.y - PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,0.0f),
		},
		{//����
			D3DXVECTOR4((float)g_PuzzleBlock1.pos.x - PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1.pos.y + PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,1.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_PuzzleBlock1.pos.x + PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1.pos.y + PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,1.0f),
		}
	};

	Vertex2D v[] = {
		{//����
			D3DXVECTOR4((float)g_PuzzleBlock1.pos.x - PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1.pos.y - PUZZLEHALF_SIZE_Y, 0.0f, 1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,0.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_PuzzleBlock1.pos.x + PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1.pos.y - PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,0.0f),
		},
		{//����
			D3DXVECTOR4((float)g_PuzzleBlock1.pos.x - PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1.pos.y + PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,1.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_PuzzleBlock1.pos.x + PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1.pos.y + PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,1.0f),
		}
	};

	//�|���S���ƃe�N�X�`����Ή�������
	LPDIRECT3DTEXTURE9 pTexture;
	//�~�����e�N�X�`���̐����ԍ���`����
	pTexture = GetTexture(g_TextureIndex);
	pDevice->SetTexture(0, pTexture);
	pDevice->SetFVF(FVF_VERTEX2D);

	if (g_PuzzleBlock1.Isdisp == 1)
	{
		pDevice->DrawPrimitiveUP(
			D3DPT_TRIANGLESTRIP,
			2,
			v,
			sizeof(Vertex2D)
		);
	}
}

/*------------------------------------------------------------------------------
�G�̃o�E���f�B���O�{�b�N�X��n��
------------------------------------------------------------------------------*/
/*COLBOX GetColBoxPuzzle(void)
{
	return (g_PuzzleBlock1.colBox);
}*/

//D3DXVECTOR2 PuzzlePosition(void)
//{
//	return (g_PuzzleBlock1.pos);
//}

/*------------------------------------------------------------------------------
�G�̗L���t���O��n��
------------------------------------------------------------------------------*/
bool IsActivePuzzle(void)
{
	return g_PuzzleBlock1.Isdisp;
}

/*------------------------------------------------------------------------------
�G�̗L���t���O��ݒ肷��
------------------------------------------------------------------------------*/
void SetActivePuzzle(int flag)
{
	g_PuzzleBlock1.Isdisp = flag;
}

bool PuzzleGetMouse(int index)
{
	mouse = index;
	return 0;
}