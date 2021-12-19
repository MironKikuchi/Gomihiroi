#include "DirectX.h"
#include "PuzzleBlock2.h"
#include "input.h"
#include "main.h"
#include "sprite.h"
#include "score.h"
#include "level.h"
#include "timelimit.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*------------------------------------------------------------------------------
�\���̐錾
------------------------------------------------------------------------------*/
typedef struct BANANA_T
{
	int		Isdisp = false;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 speed = { 0, 1 };
	D3DXVECTOR2 initspeed = { 0, -5.5 };

};


/*------------------------------------------------------------------------------
�O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static BANANA_T g_Banana[BANANACOUNT_SIZE];
static int g_TextureIndex;
static int mouse = 0;
static int Frame;
unsigned int BananaNowTime = (unsigned int)time(NULL);

/*------------------------------------------------------------------------------
�������֐�
------------------------------------------------------------------------------*/
void InitBanana(void)
{
	srand(BananaNowTime);//������

	//�t���p�Xfull path�ł͂Ȃ���
	//���΃p�X���w�肷��
	g_TextureIndex = LoadTexture("texture/Banana.png");

	for (int i = 0; i < _countof(g_Banana); i++)
	{
		SetRandomBananaPos(i);
		g_Banana[i].Isdisp = false;
	}
}

/*------------------------------------------------------------------------------
�u���b�N��X���������_���ŃZ�b�c
------------------------------------------------------------------------------*/
void SetRandomBananaPos(int index)
{
	int randomposX = rand() % SCREEN_WIDTH;
	g_Banana[index].pos.x = randomposX;
	g_Banana[index].pos.y = SCREEN_TOP;
}

/*------------------------------------------------------------------------------
�I������������֐�
------------------------------------------------------------------------------*/
void UninitBanana()
{
	srand(BananaNowTime);
	for (int i = 0; i < _countof(g_Banana); i++)
	{
		SetRandomBananaPos(i);
		g_Banana[i].Isdisp = false;
	}
}

/*------------------------------------------------------------------------------
�X�V����������֐�
------------------------------------------------------------------------------*/
void UpdateBanana(HWND hWnd)
{
	Frame += 1;
	if ((Frame % 180) == 0)
	{
		for (int i = 0; i < BANANACOUNT_SIZE; i++)
		{
			if (g_Banana[i].Isdisp == false)
			{
				SetRandomBananaPos(i);
				g_Banana[i].Isdisp = true;
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


	for (int i = 0; i < _countof(g_Banana); i++)
	{

		if (!g_Banana[i].Isdisp)
		{
			continue;
		}

		g_Banana[i].pos.y += g_Banana[i].speed.y;

		//�摜���N���b�N���ꂽ��
		if (mouse == 1 && GetLevel() >= LEVEL_BANANA)
		{
			if (mouse_p.x < (g_Banana[i].pos.x + BANANA_SIZE_X) && mouse_p.x >= (g_Banana[i].pos.x - BANANA_SIZE_X) &&
				mouse_p.y < (g_Banana[i].pos.y + BANANA_SIZE_Y) && mouse_p.y >= (g_Banana[i].pos.y - BANANA_SIZE_Y))
			{
				g_Banana[i].Isdisp = false;
				g_Banana[i].pos.y = 0;
				UpdateScore(10);
			}
		}
		else if (mouse == 1 && GetLevel() < LEVEL_BANANA)
		{
			if (mouse_p.x < (g_Banana[i].pos.x + BANANA_SIZE_X) && mouse_p.x >= (g_Banana[i].pos.x - BANANA_SIZE_X) &&
				mouse_p.y < (g_Banana[i].pos.y + BANANA_SIZE_Y) && mouse_p.y >= (g_Banana[i].pos.y - BANANA_SIZE_Y))
			{
				UpdateTime(1);
			}
		}

		//�摜�����ɍs�����珉���l�ɂ���
		if (g_Banana[i].pos.y > SCREEN_HEIGHT - 220)
		{
			g_Banana[i].Isdisp = false;
			g_Banana[i].pos.y = SCREEN_TOP;
		}
	}

}


/*------------------------------------------------------------------------------
�`�揈��������֐�
------------------------------------------------------------------------------*/

void DrawBanana(void)
{

	for (int i = 0; i < _countof(g_Banana); i++)
	{
		if (!g_Banana[i].Isdisp)
		{
			continue;
		}

		LPDIRECT3DDEVICE9 pDevice;
		pDevice = GetDevice();


		// ���_�f�[�^
		Vertex2D PuzzleBlock2[] = {
			{//����
				D3DXVECTOR4((float)g_Banana[i].pos.x - BANANA_SIZE_X, (float)g_Banana[i].pos.y - BANANA_SIZE_Y, 0.0f, 1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,0.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_Banana[i].pos.x + BANANA_SIZE_X, (float)g_Banana[i].pos.y - BANANA_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(1.0f,0.0f),
			},
			{//����
				D3DXVECTOR4((float)g_Banana[i].pos.x - BANANA_SIZE_X, (float)g_Banana[i].pos.y + BANANA_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,1.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_Banana[i].pos.x + BANANA_SIZE_X, (float)g_Banana[i].pos.y + BANANA_SIZE_Y,0.0f,1.0f),
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


		if (g_Banana[i].Isdisp == true)
		{
			pDevice->DrawPrimitiveUP(
				D3DPT_TRIANGLESTRIP,
				2,
				PuzzleBlock2,
				sizeof(Vertex2D)
			);
		}

	}
}

void BananaSetMouse(int index)
{
	mouse = index;
}