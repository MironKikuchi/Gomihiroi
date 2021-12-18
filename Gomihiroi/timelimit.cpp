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
構造体宣言
------------------------------------------------------------------------------*/
typedef struct
{
	D3DXVECTOR3 Pos;

}TIMELIMIT_T;


/*------------------------------------------------------------------------------
グローバル変数の定義
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
初期化関数
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
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitTime(void)
{

}

/*------------------------------------------------------------------------------
更新処理をする関数
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
描画処理をする関数
------------------------------------------------------------------------------*/
void DrawTime(void)
{

	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//左上90
	//右上450
	//360
	// 頂点データ
	Vertex2D Gage[] = {
		{//左上
			D3DXVECTOR4((float)(g_TimeGage.Pos.x - TIMEFONT_SIZE_X) + (((float)i * 2) + j * 2), (float)g_TimeGage.Pos.y - TIMEFONT_SIZE_Y, 0.0f, 1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,0.0f),
		},
		{//右上
			D3DXVECTOR4((float)g_TimeGage.Pos.x + TIMEFONT_SIZE_X, (float)g_TimeGage.Pos.y - TIMEFONT_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,0.0f),
		},
		{//左下
			D3DXVECTOR4((float)(g_TimeGage.Pos.x - TIMEFONT_SIZE_X) + (((float)i * 2) + j * 2), (float)g_TimeGage.Pos.y + TIMEFONT_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,1.0f),
		},
		{//右下
			D3DXVECTOR4((float)g_TimeGage.Pos.x + TIMEFONT_SIZE_X, (float)g_TimeGage.Pos.y + TIMEFONT_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,1.0f),
		}
	};
	//ポリゴンとテクスチャを対応させる
	LPDIRECT3DTEXTURE9 pTexture;
	//欲しいテクスチャの整理番号を伝える
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