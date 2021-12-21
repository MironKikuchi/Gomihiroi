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
	int			Isdisp = false;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 speed;
};


/*------------------------------------------------------------------------------
�O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static DUST_T g_DustBlockUp[UP_DUST_COUNT_SIZE];
static DUST_T g_DustBlockDown[DOWN_DUST_COUNT_SIZE];
static DUST_T g_DustBlockRight[RIGHT_DUST_COUNT_SIZE];
static DUST_T g_DustBlockLeft[LEFT_DUST_COUNT_SIZE];
static int g_TextureIndex;
static int mouse = 0;
static int FrameD;
static int FrameU;
static int FrameR;
static int FrameL;
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

	for (int i = 0; i < _countof(g_DustBlockDown); i++)
	{	
		SetDustDownPos(i);
		SetDustUpPos(i);
		SetDustRightPos(i);
		SetDustLeftPos(i);
		SetDustDownSpeed(i);
		SetDustUpSpeed(i);
		SetDustRightSpeed(i);
		SetDustLeftSpeed(i);
		g_DustBlockDown[i].Isdisp = false;
		g_DustBlockUp[i].Isdisp = false;
		g_DustBlockRight[i].Isdisp = false;
		g_DustBlockLeft[i].Isdisp = false;

		//g_DustBlockDown[i].speed = {0, 5.5};
		//g_DustBlockUp[i].speed = { 0, 5.5 };
		//g_DustBlockRight[i].speed = { 5.5, 0 };
		//g_DustBlockLeft[i].speed = { 5.5, 0 };
	}

	/*for (int i = 0; i < _countof(g_DustBlockUp); i++)
	{
		SetDustPos(i);
		g_DustBlockUp[i].Isdisp = false;
	}

	for (int i = 0; i < _countof(g_DustBlockRight); i++)
	{
		SetDustPos(i);
		g_DustBlockRight[i].Isdisp = false;
	}
	for (int i = 0; i < _countof(g_DustBlockLeft); i++)
	{
		SetDustPos(i);
		g_DustBlockLeft[i].Isdisp = false;
	}*/
}

/*------------------------------------------------------------------------------
�u���b�N�̍��W�������_���ŃZ�b�c
------------------------------------------------------------------------------*/
void SetDustDownPos(int index)
{
	int randomposX = rand() % SCREEN_WIDTH - 50;
	int randomposY = rand() % SCREEN_HEIGHT;

	g_DustBlockDown[index].pos.x = randomposX;
	g_DustBlockDown[index].pos.y = SCREEN_TOP - 20;
}

void SetDustUpPos(int index)
{
	int randomposX = rand() % SCREEN_WIDTH - 50;
	int randomposY = rand() % SCREEN_HEIGHT;

	g_DustBlockUp[index].pos.x = randomposX;
	g_DustBlockUp[index].pos.y = SCREEN_BOTTOM + 20;
}

void SetDustRightPos(int index)
{
	int randomposX = rand() % SCREEN_WIDTH - 50;
	int randomposY = rand() % SCREEN_HEIGHT;

	g_DustBlockRight[index].pos.x = SCREEN_LEFT - 20;
	g_DustBlockRight[index].pos.y = randomposY;
}

void SetDustLeftPos(int index)
{
	int randomposX = rand() % SCREEN_WIDTH - 50;
	int randomposY = rand() % SCREEN_HEIGHT;

	g_DustBlockLeft[index].pos.x = SCREEN_RIGHT + 20;
	g_DustBlockLeft[index].pos.y = randomposY;
}

/*------------------------------------------------------------------------------
�u���b�N�̃X�s�[�h�������_���ŃZ�b�c
------------------------------------------------------------------------------*/
void SetDustDownSpeed(int index)
{
	int randomSpeedX = rand() % 5 + 1;
	int randomSpeedY = rand() % 5 + 1;

	g_DustBlockDown[index].speed.x = 0;
	g_DustBlockDown[index].speed.y = randomSpeedY;
	/*char str[256];
	sprintf_s(str, "PosY: %d \n", randomSpeedY);
	OutputDebugString(str);*/
}

void SetDustUpSpeed(int index)
{
	int randomSpeedX = rand() % 5 + 1;
	int randomSpeedY = rand() % 5 + 1;

	g_DustBlockUp[index].speed.x = 0;
	g_DustBlockUp[index].speed.y = randomSpeedY;
}

void SetDustRightSpeed(int index)
{

	int randomSpeedX = rand() % 5 + 1;
	int randomSpeedY = rand() % 5 + 1;

	g_DustBlockRight[index].speed.x = randomSpeedX;
	g_DustBlockRight[index].speed.y = 0;
}

void SetDustLeftSpeed(int index)
{
	int randomSpeedX = rand() % 5 + 1;
	int randomSpeedY = rand() % 5 + 1;

	g_DustBlockLeft[index].speed.x = randomSpeedX;
	g_DustBlockLeft[index].speed.y = 0;
}



/*------------------------------------------------------------------------------
�I������������֐�
------------------------------------------------------------------------------*/
void UninitDust()
{
	srand(DustNowTime);
	for (int i = 0; i < _countof(g_DustBlockDown); i++)
	{
		SetDustDownPos(i);
		SetDustUpPos(i);
		SetDustRightPos(i);
		SetDustLeftPos(i);

		g_DustBlockDown[i].Isdisp = false;
		g_DustBlockDown[i].speed = { 0, 5.5 };

		g_DustBlockUp[i].Isdisp = false;
		g_DustBlockUp[i].speed = { 0, 5.5 };

		g_DustBlockRight[i].Isdisp = false;
		g_DustBlockRight[i].speed = { 5.5, 0 };

		g_DustBlockLeft[i].Isdisp = false;
		g_DustBlockLeft[i].speed = { 5.5, 0 };
	}
}

/*------------------------------------------------------------------------------
�X�V����������֐�
------------------------------------------------------------------------------*/
void UpdateDust(HWND hWnd)
{
	FrameD += 1;
	FrameU += 1;
	FrameR += 1;
	FrameL += 1;
	//DebugPrint(FrameD);
	if ((FrameD % 60) == 0)
	{
		for (int i = 0; i < DOWN_DUST_COUNT_SIZE; i++)
		{
			if (g_DustBlockDown[i].Isdisp == false)
			{
				SetDustDownPos(i);
				SetDustDownSpeed(i);
				g_DustBlockDown[i].Isdisp = true;
				break;
			}
		}
	}	
	
	if ((FrameU % 90) == 0)
	{
		for (int i = 0; i < UP_DUST_COUNT_SIZE; i++)
		{
			if (g_DustBlockUp[i].Isdisp == false)
			{
				SetDustUpPos(i);
				SetDustUpSpeed(i);
				g_DustBlockUp[i].Isdisp = true;
				break;
			}
		}
	}

	if ((FrameR % 60) == 0)
	{
		for (int i = 0; i < RIGHT_DUST_COUNT_SIZE; i++)
		{
			if (g_DustBlockRight[i].Isdisp == false)
			{
				SetDustRightPos(i);
				SetDustRightSpeed(i);
				g_DustBlockRight[i].Isdisp = true;
				break;
			}
		}
	}

	if ((FrameL % 60) == 0)
	{
		for (int i = 0; i < LEFT_DUST_COUNT_SIZE; i++)
		{
			if (g_DustBlockLeft[i].Isdisp == false)
			{
				SetDustLeftPos(i);
				SetDustLeftSpeed(i);
				g_DustBlockLeft[i].Isdisp = true;
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

	//�ォ�牺�ɗ�������
	for (int d = 0; d < _countof(g_DustBlockDown); d++)
	{

		if (!g_DustBlockDown[d].Isdisp)
		{
			continue;
		}

		g_DustBlockDown[d].pos.y += g_DustBlockDown[d].speed.y;

		/*char str[256];
		sprintf_s(str, "PosY: %d \n", g_DustBlockDown[d].pos.y);
		OutputDebugString(str);*/
		if (mouse == 1)
		{
			if (mouse_p.x < (g_DustBlockDown[d].pos.x + (DUST_SIZE_X - 22)) && mouse_p.x >= (g_DustBlockDown[d].pos.x - (DUST_SIZE_X - 22)) &&
				mouse_p.y < (g_DustBlockDown[d].pos.y + (DUST_SIZE_Y - 22)) && mouse_p.y >= (g_DustBlockDown[d].pos.y - (DUST_SIZE_Y - 22)))
			{
				g_DustBlockDown[d].Isdisp = false;
				g_DustBlockDown[d].pos.y = 0;
				g_DustBlockDown[d].speed.y = 0;
				UpdateScore(5);
			}
		}
		else
		{
			UpdateTime(0);
		}

		//�摜�����ɍs�����珉���l�ɂ���
		if (g_DustBlockDown[d].pos.y > SCREEN_HEIGHT + 20)
		{
			g_DustBlockDown[d].Isdisp = false;
			g_DustBlockDown[d].pos.y = SCREEN_TOP + 120;
			g_DustBlockDown[d].speed.y = 0;
		}
	}

	//�������ɏ�鏈��
	for (int u = 0; u < _countof(g_DustBlockUp); u++)
	{

		if (!g_DustBlockUp[u].Isdisp)
		{
			continue;
		}
		//g_DustBlockUp[u].speed.y = 3;
		g_DustBlockUp[u].pos.y -= g_DustBlockUp[u].speed.y;

		if (mouse == 1)
		{
			if (mouse_p.x < (g_DustBlockUp[u].pos.x + (DUST_SIZE_X - 22)) && mouse_p.x >= (g_DustBlockUp[u].pos.x - (DUST_SIZE_X - 22)) &&
				mouse_p.y < (g_DustBlockUp[u].pos.y + (DUST_SIZE_Y - 22)) && mouse_p.y >= (g_DustBlockUp[u].pos.y - (DUST_SIZE_Y - 22)))
			{
				g_DustBlockUp[u].Isdisp = false;
				g_DustBlockUp[u].pos.y = SCREEN_BOTTOM + 20;
				g_DustBlockUp[u].speed.y = 0;
				UpdateScore(5);
			}
		}
		else
		{
			UpdateTime(0);
		}
		/*char str[256];
	    sprintf_s(str, "PosX: %f PosY: %f \n", g_DustBlockUp[u].pos.x, g_DustBlockUp[u].pos.y);
	    OutputDebugString(str);*/
		//�摜����ɍs�����珉���l�ɂ���
		if (g_DustBlockUp[u].pos.y < -50)
		{
			g_DustBlockUp[u].Isdisp = false;
			g_DustBlockUp[u].pos.y = SCREEN_BOTTOM;
			g_DustBlockUp[u].speed.y = 0;
		}
	
	}

	//������E�Ɉړ����鏈��
	for (int u = 0; u < _countof(g_DustBlockRight); u++)
	{

		if (!g_DustBlockRight[u].Isdisp)
		{
			continue;
		}
		g_DustBlockRight[u].pos.x += g_DustBlockRight[u].speed.x;

		if (mouse == 1)
		{
			if (mouse_p.x < (g_DustBlockRight[u].pos.x + (DUST_SIZE_X - 22)) && mouse_p.x >= (g_DustBlockRight[u].pos.x - (DUST_SIZE_X - 22)) &&
				mouse_p.y < (g_DustBlockRight[u].pos.y + (DUST_SIZE_Y - 22)) && mouse_p.y >= (g_DustBlockRight[u].pos.y - DUST_SIZE_Y - 22))
			{
				g_DustBlockRight[u].Isdisp = false;
				g_DustBlockRight[u].pos.x = SCREEN_LEFT - 20;
				//g_DustBlockRight[u].speed.x = 0;
				UpdateScore(5);
			}
		}
		else
		{
			UpdateTime(0);
		}
		//�摜���E�ɍs�����珉���l�ɂ���
		if (g_DustBlockRight[u].pos.x > SCREEN_RIGHT + 50)
		{
			g_DustBlockRight[u].Isdisp = false;
			g_DustBlockRight[u].pos.x = SCREEN_LEFT - 20;
			g_DustBlockRight[u].speed.x = 0;
		}

	}

	//�E���獶�Ɉړ����鏈��
	for (int u = 0; u < _countof(g_DustBlockLeft); u++)
	{

		if (!g_DustBlockLeft[u].Isdisp)
		{
			continue;
		}
		g_DustBlockLeft[u].pos.x -= g_DustBlockLeft[u].speed.x;

		if (mouse == 1)
		{
			if (mouse_p.x < (g_DustBlockLeft[u].pos.x + (DUST_SIZE_X - 22)) && mouse_p.x >= (g_DustBlockLeft[u].pos.x - (DUST_SIZE_X - 22)) &&
				mouse_p.y < (g_DustBlockLeft[u].pos.y + (DUST_SIZE_Y - 22)) && mouse_p.y >= (g_DustBlockLeft[u].pos.y - (DUST_SIZE_Y - 22)))
			{
				g_DustBlockLeft[u].Isdisp = false;
				g_DustBlockLeft[u].pos.x = SCREEN_RIGHT + 20;
				g_DustBlockLeft[u].speed.x = 0;
				UpdateScore(5);
			}
		}
		else
		{
			UpdateTime(0);
		}
		//�摜�����ɍs�����珉���l�ɂ���
		if (g_DustBlockLeft[u].pos.x < SCREEN_LEFT - 50)
		{
			g_DustBlockLeft[u].Isdisp = false;
			g_DustBlockLeft[u].pos.x = SCREEN_RIGHT + 20;
			g_DustBlockLeft[u].speed.x = 0;
		}

	}

}


/*------------------------------------------------------------------------------
�`�揈��������֐�
------------------------------------------------------------------------------*/

void DrawDust(void)
{
	//Top
	for (int i = 0; i < _countof(g_DustBlockDown); i++)
	{
		if (!g_DustBlockDown[i].Isdisp)
		{
			continue;
		}

		LPDIRECT3DDEVICE9 pDevice;
		pDevice = GetDevice();


		// ���_�f�[�^
		Vertex2D TopDust[] = {
			{//����
				D3DXVECTOR4((float)g_DustBlockDown[i].pos.x -  DUST_SIZE_X, (float)g_DustBlockDown[i].pos.y -  DUST_SIZE_Y, 0.0f, 1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,0.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_DustBlockDown[i].pos.x +  DUST_SIZE_X, (float)g_DustBlockDown[i].pos.y -  DUST_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(1.0f,0.0f),
			},
			{//����
				D3DXVECTOR4((float)g_DustBlockDown[i].pos.x -  DUST_SIZE_X, (float)g_DustBlockDown[i].pos.y +  DUST_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,1.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_DustBlockDown[i].pos.x +  DUST_SIZE_X, (float)g_DustBlockDown[i].pos.y +  DUST_SIZE_Y,0.0f,1.0f),
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


		if (g_DustBlockDown[i].Isdisp == true)
		{
			pDevice->DrawPrimitiveUP(
				D3DPT_TRIANGLESTRIP,
				2,
				TopDust,
				sizeof(Vertex2D)
			);
		}

	}

	//Bottom
	for (int i = 0; i < _countof(g_DustBlockUp); i++)
	{
		if (!g_DustBlockUp[i].Isdisp)
		{
			continue;
		}

		LPDIRECT3DDEVICE9 pDevice;
		pDevice = GetDevice();


		// ���_�f�[�^
		Vertex2D UpDust[] = {
			{//����
				D3DXVECTOR4((float)g_DustBlockUp[i].pos.x - DUST_SIZE_X, (float)g_DustBlockUp[i].pos.y - DUST_SIZE_Y, 0.0f, 1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,0.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_DustBlockUp[i].pos.x + DUST_SIZE_X, (float)g_DustBlockUp[i].pos.y - DUST_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(1.0f,0.0f),
			},
			{//����
				D3DXVECTOR4((float)g_DustBlockUp[i].pos.x - DUST_SIZE_X, (float)g_DustBlockUp[i].pos.y + DUST_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,1.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_DustBlockUp[i].pos.x + DUST_SIZE_X, (float)g_DustBlockUp[i].pos.y + DUST_SIZE_Y,0.0f,1.0f),
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


		if (g_DustBlockUp[i].Isdisp == true)
		{
			pDevice->DrawPrimitiveUP(
				D3DPT_TRIANGLESTRIP,
				2,
				UpDust,
				sizeof(Vertex2D)
			);
		}

	}
	//Right
	for (int i = 0; i < _countof(g_DustBlockRight); i++)
	{
		if (!g_DustBlockRight[i].Isdisp)
		{
			continue;
		}

		LPDIRECT3DDEVICE9 pDevice;
		pDevice = GetDevice();


		// ���_�f�[�^
		Vertex2D RightDust[] = {
			{//����
				D3DXVECTOR4((float)g_DustBlockRight[i].pos.x - DUST_SIZE_X, (float)g_DustBlockRight[i].pos.y - DUST_SIZE_Y, 0.0f, 1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,0.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_DustBlockRight[i].pos.x + DUST_SIZE_X, (float)g_DustBlockRight[i].pos.y - DUST_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(1.0f,0.0f),
			},
			{//����
				D3DXVECTOR4((float)g_DustBlockRight[i].pos.x - DUST_SIZE_X, (float)g_DustBlockRight[i].pos.y + DUST_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,1.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_DustBlockRight[i].pos.x + DUST_SIZE_X, (float)g_DustBlockRight[i].pos.y + DUST_SIZE_Y,0.0f,1.0f),
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


		if (g_DustBlockRight[i].Isdisp == true)
		{
			pDevice->DrawPrimitiveUP(
				D3DPT_TRIANGLESTRIP,
				2,
				RightDust,
				sizeof(Vertex2D)
			);
		}

	}

	//Left
	for (int i = 0; i < _countof(g_DustBlockLeft); i++)
	{
		if (!g_DustBlockLeft[i].Isdisp)
		{
			continue;
		}

		LPDIRECT3DDEVICE9 pDevice;
		pDevice = GetDevice();


		// ���_�f�[�^
		Vertex2D LeftDust[] = {
			{//����
				D3DXVECTOR4((float)g_DustBlockLeft[i].pos.x - DUST_SIZE_X, (float)g_DustBlockLeft[i].pos.y - DUST_SIZE_Y, 0.0f, 1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,0.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_DustBlockLeft[i].pos.x + DUST_SIZE_X, (float)g_DustBlockLeft[i].pos.y - DUST_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(1.0f,0.0f),
			},
			{//����
				D3DXVECTOR4((float)g_DustBlockLeft[i].pos.x - DUST_SIZE_X, (float)g_DustBlockLeft[i].pos.y + DUST_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,1.0f),
			},
			{//�E��
				D3DXVECTOR4((float)g_DustBlockLeft[i].pos.x + DUST_SIZE_X, (float)g_DustBlockLeft[i].pos.y + DUST_SIZE_Y,0.0f,1.0f),
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


		if (g_DustBlockLeft[i].Isdisp == true)
		{
			pDevice->DrawPrimitiveUP(
				D3DPT_TRIANGLESTRIP,
				2,
				LeftDust,
				sizeof(Vertex2D)
			);
		}

	}
}

void DustSetMouse(int index)
{
	mouse = index;
}