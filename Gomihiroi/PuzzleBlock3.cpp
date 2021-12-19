#include "DirectX.h"
#include "PuzzleBlock3.h"
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
typedef struct BOOK_T
{
	int		Isdisp = false;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 speed = { 0, 1 };
	D3DXVECTOR2 initspeed = { 0, -5.5 };

};


/*------------------------------------------------------------------------------
�O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static BOOK_T g_Book[BOOKCOUNT_SIZE];
static int g_TextureIndex;
static int mouse = 0;
static int Frame;
unsigned int BookNowTime = (unsigned int)time(NULL);

/*------------------------------------------------------------------------------
�������֐�
------------------------------------------------------------------------------*/
void InitBook(void)
{
	srand(BookNowTime);//������

	//�t���p�Xfull path�ł͂Ȃ���
	//���΃p�X���w�肷��
	g_TextureIndex = LoadTexture("texture/Book.png");

	for (int i = 0; i < _countof(g_Book); i++)
	{
		SetRandomBookPos(i);
		g_Book[i].Isdisp = false;
	}
}

/*------------------------------------------------------------------------------
�u���b�N��X���������_���ŃZ�b�c
------------------------------------------------------------------------------*/
void SetRandomBookPos(int index)
{
	int randomposX = rand() % SCREEN_WIDTH;
	g_Book[index].pos.x = randomposX;
	g_Book[index].pos.y = SCREEN_TOP;
}

/*------------------------------------------------------------------------------
�I������������֐�
------------------------------------------------------------------------------*/
void UninitBook()
{
	srand(BookNowTime);
	for (int i = 0; i < _countof(g_Book); i++)
	{
		SetRandomBookPos(i);
		g_Book[i].Isdisp = false;
	}
}

/*------------------------------------------------------------------------------
�X�V����������֐�
------------------------------------------------------------------------------*/
void UpdateBook(HWND hWnd)
{
	Frame += 1;
	if ((Frame % 240) == 0)
	{
		for (int i = 0; i < BOOKCOUNT_SIZE; i++)
		{
			if (g_Book[i].Isdisp == false)
			{
				SetRandomBookPos(i);
				g_Book[i].Isdisp = true;
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


	for (int i = 0; i < _countof(g_Book); i++)
	{

		if (!g_Book[i].Isdisp)
		{
			continue;
		}

		g_Book[i].pos.y += g_Book[i].speed.y;

		//�摜���N���b�N���ꂽ��
		if (mouse == 1 && GetLevel() >= LEVEL_BOOK)
		{
			if (mouse_p.x < (g_Book[i].pos.x + BOOK_SIZE_X) && mouse_p.x >= (g_Book[i].pos.x - BOOK_SIZE_X) &&
				mouse_p.y < (g_Book[i].pos.y + BOOK_SIZE_Y) && mouse_p.y >= (g_Book[i].pos.y - BOOK_SIZE_Y))
			{
				g_Book[i].Isdisp = false;
				g_Book[i].pos.y = 0;
				UpdateScore(50);
			}
		}
		else if (mouse == 1 && GetLevel() < LEVEL_BOOK)
		{
			if (mouse_p.x < (g_Book[i].pos.x + BOOK_SIZE_X) && mouse_p.x >= (g_Book[i].pos.x - BOOK_SIZE_X) &&
				mouse_p.y < (g_Book[i].pos.y + BOOK_SIZE_Y) && mouse_p.y >= (g_Book[i].pos.y - BOOK_SIZE_Y))
			{
				UpdateTime(2);
			}
		}

		//�摜�����ɍs�����珉���l�ɂ���
		if (g_Book[i].pos.y > SCREEN_HEIGHT - 220)
		{
			g_Book[i].Isdisp = false;
			g_Book[i].pos.y = SCREEN_TOP;
		}
	}

}


/*------------------------------------------------------------------------------
�`�揈��������֐�
------------------------------------------------------------------------------*/

void DrawBook(void)
{

	for (int i = 0; i < _countof(g_Book); i++)
	{
		if (!g_Book[i].Isdisp)
		{
			continue;
		}

		LPDIRECT3DDEVICE9 pDevice;
		pDevice = GetDevice();


		// ���_�f�[�^
		Vertex2D PuzzleBlock2[] = {
			{//����
				D3DXVECTOR4((float)g_Book[i].pos.x - BOOK_SIZE_X, (float)g_Book[i].pos.y - BOOK_SIZE_Y, 0.0f, 1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,0.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_Book[i].pos.x + BOOK_SIZE_X, (float)g_Book[i].pos.y - BOOK_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(1.0f,0.0f),
			},
			{//����
				D3DXVECTOR4((float)g_Book[i].pos.x - BOOK_SIZE_X, (float)g_Book[i].pos.y + BOOK_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,1.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_Book[i].pos.x + BOOK_SIZE_X, (float)g_Book[i].pos.y + BOOK_SIZE_Y,0.0f,1.0f),
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


		if (g_Book[i].Isdisp == true)
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

void BookSetMouse(int index)
{
	mouse = index;
}