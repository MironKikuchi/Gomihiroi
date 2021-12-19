#include "DirectX.h"
#include "PuzzleBlock.h"
#include "input.h"
#include "main.h"
#include "sprite.h"
#include "score.h"
#include "timelimit.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*------------------------------------------------------------------------------
�\���̐錾
------------------------------------------------------------------------------*/
typedef struct DUST_T
{
	int		Isdisp = false;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 speed = { 0, 1 };
	D3DXVECTOR2 initspeed = { 0, -5.5 };

};


/*------------------------------------------------------------------------------
�O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static DUST_T g_DustBlock[DUSTCOUNT_SIZE];
static int g_TextureIndex;
static int mouse = 0;
static int Frame;
unsigned int DustNowTime = (unsigned int)time(NULL);

/*------------------------------------------------------------------------------
�������֐�
------------------------------------------------------------------------------*/
void InitDust(void)
{
	srand(DustNowTime);//������
	
	
	//�t���p�Xfull path�ł͂Ȃ���
	//���΃p�X���w�肷��
	g_TextureIndex = LoadTexture("texture/Hokori.png");

	for (int i = 0; i < _countof(g_DustBlock); i++)
	{	
		SetRandomDustPos(i);
		g_DustBlock[i].Isdisp = false;
	}
}

/*------------------------------------------------------------------------------
�u���b�N��X���������_���ŃZ�b�c
------------------------------------------------------------------------------*/
void SetRandomDustPos(int index)
{
	int randomposX = rand() % SCREEN_WIDTH;
	g_DustBlock[index].pos.x = randomposX;
	g_DustBlock[index].pos.y = SCREEN_TOP;
}

/*------------------------------------------------------------------------------
�I������������֐�
------------------------------------------------------------------------------*/
void UninitDust()
{
	srand(DustNowTime);
	for (int i = 0; i < _countof(g_DustBlock); i++)
	{
		SetRandomDustPos(i);
		g_DustBlock[i].Isdisp = false;
	}
}

/*------------------------------------------------------------------------------
�X�V����������֐�
------------------------------------------------------------------------------*/
void UpdateDust(HWND hWnd)
{
	Frame += 1;
	if ((Frame % 30) == 0)
	{
		for (int i = 0; i < DUSTCOUNT_SIZE; i++)
		{
			if (g_DustBlock[i].Isdisp == false)
			{
				SetRandomDustPos(i);
				g_DustBlock[i].Isdisp = true;
				break;
			}
		}
	}
	

	POINT mouse_p;
	//�}�E�X�̍��W�Q�b�c
	GetCursorPos(&mouse_p);
	//�}�E�X�̍��W���X�N���[������N���C�A���g(�E�B���h�E)��
	ScreenToClient(hWnd, &mouse_p);

	/*char str[256];
	sprintf_s(str, "PosX: %d PosY: %d \n", mouse_p.x, mouse_p.y);
	OutputDebugString(str);*/


	for (int i = 0; i < _countof(g_DustBlock); i++)
	{

		if (!g_DustBlock[i].Isdisp)
		{
			continue;
		}

		g_DustBlock[i].pos.y += g_DustBlock[i].speed.y;

		if (mouse == 1)
		{
			if (mouse_p.x < (g_DustBlock[i].pos.x + DUST_SIZE_X) && mouse_p.x >= (g_DustBlock[i].pos.x - DUST_SIZE_X) &&
				mouse_p.y < (g_DustBlock[i].pos.y + DUST_SIZE_Y) && mouse_p.y >= (g_DustBlock[i].pos.y - DUST_SIZE_Y))
			{
				g_DustBlock[i].Isdisp = false;
				g_DustBlock[i].pos.y = 0;
				UpdateScore(5);
			}
		}
		else
		{
			UpdateTime(0);
		}

		//�摜�̃{�^���̓����蔻��
		// if (mouse_p.x < (g_DustBlock[i].pos.x +  DUST_SIZE_X) && mouse_p.x >= (g_DustBlock[i].pos.x -  DUST_SIZE_X) &&
		// 	mouse_p.y < (g_DustBlock[i].pos.y +  DUST_SIZE_Y) && mouse_p.y >= (g_DustBlock[i].pos.y -  DUST_SIZE_Y))
		// {
		// 	if (mouse == 1)
		// 	{
		// 		g_DustBlock[i].Isdisp = false;
		// 		g_DustBlock[i].pos.y = 0;
		// 	}
		// }
		// else
		// {
		// 	mouse = 0;
		// }

		//�摜�����ɍs�����珉���l�ɂ���
		if (g_DustBlock[i].pos.y > SCREEN_HEIGHT + 20)
		{
			g_DustBlock[i].Isdisp = false;
			g_DustBlock[i].pos.y = SCREEN_TOP + 220;
		}
	}
	
	//�摜�̃{�^���̓����蔻��
	/*if (mouse_p.x < (g_DustBlock[j].pos.x +  DUST_SIZE_X) && mouse_p.x >= (g_DustBlock[j].pos.x -  DUST_SIZE_X) &&
		mouse_p.y < (g_DustBlock[j].pos.y +  DUST_SIZE_Y) && mouse_p.y >= (g_DustBlock[j].pos.y -  DUST_SIZE_Y))
	{
		if (mouse == 1)
		{
			g_DustBlock[j].Isdisp = false;
			g_DustBlock[j].pos.y = 0;
		}
	}
	else
	{
		mouse = 0;
	}*/
}


/*------------------------------------------------------------------------------
�`�揈��������֐�
------------------------------------------------------------------------------*/

void DrawDust(void)
{

	for (int i = 0; i < _countof(g_DustBlock); i++)
	{
		if (!g_DustBlock[i].Isdisp)
		{
			continue;
		}

		LPDIRECT3DDEVICE9 pDevice;
		pDevice = GetDevice();


		// ���_�f�[�^
		Vertex2D PuzzleBlock1[] = {
			{//����
				D3DXVECTOR4((float)g_DustBlock[i].pos.x -  DUST_SIZE_X, (float)g_DustBlock[i].pos.y -  DUST_SIZE_Y, 0.0f, 1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,0.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_DustBlock[i].pos.x +  DUST_SIZE_X, (float)g_DustBlock[i].pos.y -  DUST_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(1.0f,0.0f),
			},
			{//����
				D3DXVECTOR4((float)g_DustBlock[i].pos.x -  DUST_SIZE_X, (float)g_DustBlock[i].pos.y +  DUST_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,1.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_DustBlock[i].pos.x +  DUST_SIZE_X, (float)g_DustBlock[i].pos.y +  DUST_SIZE_Y,0.0f,1.0f),
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


		if (g_DustBlock[i].Isdisp == true)
		{
			pDevice->DrawPrimitiveUP(
				D3DPT_TRIANGLESTRIP,
				2,
				PuzzleBlock1,
				sizeof(Vertex2D)
			);
		}

	}
}

void DustSetMouse(int index)
{
	mouse = index;
}