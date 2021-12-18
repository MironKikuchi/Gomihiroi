#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include "DirectX.h"
#include "main.h"
#include "timelimit.h"
#include "texture.h"
#include "scene.h"
#include "sprite.h"



/*------------------------------------------------------------------------------
�\���̐錾
------------------------------------------------------------------------------*/
typedef struct
{
	D3DXVECTOR3 Pos;

}TIMELIMIT_T;


/*------------------------------------------------------------------------------
�O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static TIMELIMIT_T g_TimeGage;

static int g_TimeTextureIndex;

static int TimeLimit;

static int TimeFrame = 1;

static int i = 0;
static int j = 0;
static int b = 0;


float Timer1 = 0.0f;
float Timer2 = 0.0f;
float Timer3 = 0.5f;

clock_t TimeStart;


/*------------------------------------------------------------------------------
�������֐�
------------------------------------------------------------------------------*/
void InitTime(void)
{
	g_TimeTextureIndex = LoadTexture("texture/Gage.png");

	g_TimeGage.Pos.x = TIMEFONT_POS_X;
	g_TimeGage.Pos.y = TIMEFONT_POS_Y;

	TimeLimit = TIME_LIMIT;

	TimeStart = clock();
}

/*------------------------------------------------------------------------------
�I������������֐�
------------------------------------------------------------------------------*/
void UninitTime(void)
{

}

/*------------------------------------------------------------------------------
�X�V����������֐�
------------------------------------------------------------------------------*/
void UpdateTime(int addpenalty)
{
	clock_t TimeEnd = clock();
	float TimeCount = (TimeEnd - TimeStart) / CLOCKS_PER_SEC;
	
	
	TimeLimit -= addpenalty;
	if(TimeCount > TimeLimit)
	{
		SetScene(SCENE_HIGHRESULT);
		CheckScene();
	}

	i = TimeCount;
	j += addpenalty;
	b += TimeCount + addpenalty;
	/*char str[256];
	sprintf_s(str, " %f \n", TimeCount);
	OutputDebugString(str);*/
}

/*------------------------------------------------------------------------------
�`�揈��������֐�
------------------------------------------------------------------------------*/
void DrawTime(void)
{

	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//����90
	//�E��450
	//360
	// ���_�f�[�^
	Vertex2D Gage[] = {
		{//����
			D3DXVECTOR4((float)(g_TimeGage.Pos.x - TIMEFONT_SIZE_X) + (((float)i * 2) + j * 2), (float)g_TimeGage.Pos.y - TIMEFONT_SIZE_Y, 0.0f, 1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,0.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_TimeGage.Pos.x + TIMEFONT_SIZE_X, (float)g_TimeGage.Pos.y - TIMEFONT_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,0.0f),
		},
		{//����
			D3DXVECTOR4((float)(g_TimeGage.Pos.x - TIMEFONT_SIZE_X) + (((float)i * 2) + j * 2), (float)g_TimeGage.Pos.y + TIMEFONT_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,1.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_TimeGage.Pos.x + TIMEFONT_SIZE_X, (float)g_TimeGage.Pos.y + TIMEFONT_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,1.0f),
		}
	};
	//�|���S���ƃe�N�X�`����Ή�������
	LPDIRECT3DTEXTURE9 pTexture;
	//�~�����e�N�X�`���̐����ԍ���`����
	pTexture = GetTexture(g_TimeTextureIndex);
	pDevice->SetTexture(0, pTexture);
	pDevice->SetFVF(FVF_VERTEX2D);


	pDevice->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Gage,
		sizeof(Vertex2D)
	);

}