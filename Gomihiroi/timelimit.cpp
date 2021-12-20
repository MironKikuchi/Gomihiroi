#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include "DirectX.h"
#include "main.h"
#include "timelimit.h"
#include "texture.h"
#include "scene.h"
#include "sprite.h"
#include "highscoreresult.h"
#include "normalresult.h"



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

static int g_TimeImageTexture;
static int g_TimeTextureIndex;
static int g_Waku;

static int TimeLimit;

static int TimeFrame = 1;

static int i = 0;
static int j = 0;
static int b = 0;

static int g_HighScoreJudge = 0;
static int g_NormalScoreJudge = 0;

float Timer1 = 0.0f;
float Timer2 = 0.0f;
float Timer3 = 0.5f;

clock_t TimeStart;


/*------------------------------------------------------------------------------
�������֐�
------------------------------------------------------------------------------*/
void InitTime(void)
{
	g_TimeImageTexture = LoadTexture("texture/minitime.png");
	g_TimeTextureIndex = LoadTexture("texture/Gage2.png");
	g_Waku = LoadTexture("texture/Waku.png");

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
	g_TimeGage.Pos.x = TIMEFONT_POS_X;
	g_TimeGage.Pos.y = TIMEFONT_POS_Y;

	TimeLimit = TIME_LIMIT;

	TimeStart = clock();
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
		if (g_HighScoreJudge >= g_NormalScoreJudge)
		{
			SetScene(SCENE_HIGHRESULT);
			CheckScene();
		}
		else
		{
			SetScene(SCENE_NORMAL);
			CheckScene();
		}
	}

	i = TimeCount;
	j += addpenalty;
	b += TimeCount + addpenalty;
	/*char str[256];
	sprintf_s(str, "Time: %d Limit: %d PENALTY: %d \n", i, TimeLimit, j);
	OutputDebugString(str);*/
}

/*------------------------------------------------------------------------------
�`�揈��������֐�
------------------------------------------------------------------------------*/
void DrawTime(void)
{
	DrawSprite(g_TimeImageTexture,
		TIME_IMAGE_X + 80, TIME_IMAGE_Y,
		TIME_IMAGE_WIDTH, TIME_IMAGE_HEIGHT,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_Waku,
		SCREEN_HALFWIDTH + 120, 100,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT - 460,
		0.0f, 0.0f,
		1.0f, 1.0f);

	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//����90  280
	//�E��450 500
	//��360   220
	// ���_�f�[�^
	Vertex2D Gage[] = {
		{//����
			D3DXVECTOR4((float)(g_TimeGage.Pos.x - TIMEFONT_SIZE_X) + (((float)i * 3.7) + (float)j * 3.7), (float)g_TimeGage.Pos.y - TIMEFONT_SIZE_Y, 0.0f, 1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,0.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_TimeGage.Pos.x + TIMEFONT_SIZE_X, (float)g_TimeGage.Pos.y - TIMEFONT_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,0.0f),
		},
		{//����
			D3DXVECTOR4((float)(g_TimeGage.Pos.x - TIMEFONT_SIZE_X) + (((float)i * 3.7) + (float)j * 3.7), (float)g_TimeGage.Pos.y + TIMEFONT_SIZE_Y,0.0f,1.0f),
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

void HighScoreJudge(int highscore)
{
	g_HighScoreJudge = highscore;
}

void NormalScoreJudge(int normalscore)
{
	g_NormalScoreJudge = normalscore;
}