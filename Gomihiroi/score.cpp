#include <Windows.h>
#include <stdio.h>
#include "DirectX.h"
#include "main.h"
#include "texture.h"
#include "sprite.h"
#include "score.h"


/*------------------------------------------------------------------------------
構造体宣言
------------------------------------------------------------------------------*/
typedef struct
{
	D3DXVECTOR3 Pos;

}SCORE_T;


/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static SCORE_T g_ScoreNumber[SCORE_NUMBER_MAX];

static int g_ScoreTextureIndex;


static int ScorePointCharge = 0;

//ループした数を入れる
int g_Shift = 0;

static int g_r = 0;

float byouga1;
float byouga2;
float byouga3;
float byouga4;
float byouga5;
float byouga6;
float byouga7;



/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitScore(void)
{
	g_ScoreTextureIndex = LoadTexture("texture/number.png");

	/*g_BGMIndex = LoadSound("sound/bgm01.WAV");

	PlaySound(g_BGMIndex, -1);*/
}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitScore(void)
{

}

/*------------------------------------------------------------------------------
更新処理をする関数
------------------------------------------------------------------------------*/
void UpdateScore(int addScore)
{
	/*char str[256];
	sprintf_s(str, "ポイント: %d Score: %d \n", ScorePointContainer, ScorePointCharge);
	OutputDebugString(str);*/
	/*char str[256];
	sprintf_s(str, " %f \n", byouga);
	OutputDebugString(str);*/

	int ScoreChenge = 0;
	
	ScorePointCharge += addScore;
	ScoreChenge = ScorePointCharge;
	byouga1 = (float)ScoreChenge / 10;

	if (ScorePointCharge >= 10)
	{
		byouga2 = (float)ScoreChenge / 100;
	}
	if (ScorePointCharge >= 100)
	{
		byouga3 = (float)ScoreChenge / 1000;
	}

	/*char str[256];
	sprintf_s(str, " %f \n", byouga2);
	OutputDebugString(str);*/
	char str[256];
	sprintf_s(str, " %f \n", byouga3);
	OutputDebugString(str);
}

/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/
void DrawScore(void)
{
	DrawSprite(g_ScoreTextureIndex,
		SCOREFONT_POS_X + 30, SCOREFONT_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		byouga7, 0.0f,
		0.1f, 1.0f);

	
	DrawSprite(g_ScoreTextureIndex,
		 SCOREFONT_POS_X + 60, SCOREFONT_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		byouga6, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_ScoreTextureIndex,
		 SCOREFONT_POS_X + 90, SCOREFONT_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		byouga5, 0.0f,
		0.1f, 1.0f);

	
	DrawSprite(g_ScoreTextureIndex,
		 SCOREFONT_POS_X + 120, SCOREFONT_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		byouga4, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_ScoreTextureIndex,
		 SCOREFONT_POS_X + 150, SCOREFONT_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		byouga3, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_ScoreTextureIndex,
		 SCOREFONT_POS_X + 180, SCOREFONT_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		byouga2, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_ScoreTextureIndex,
		 SCOREFONT_POS_X + 210, SCOREFONT_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		byouga1, 0.0f,
		0.1f, 1.0f);
}

//switch (g_r)
//{
//case 0:
//	g_SetTexture = g_ScoreTextureIndex1;
//	DrawSprite(g_SetTexture,
//		g_ScoreNumber[i].Pos.x, g_ScoreNumber[i].Pos.y,
//		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
//		byouga, 0.0f,
//		0.1f, 1.0f);
//	break;
//case 1:
//	g_SetTexture = g_ScoreTextureIndex2;
//	DrawSprite(g_SetTexture,
//		g_ScoreNumber[i].Pos.x, g_ScoreNumber[i].Pos.y,
//		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
//		byouga, 0.0f,
//		0.1f, 1.0f);
//	break;
//case 2:
//	g_SetTexture = g_ScoreTextureIndex3;
//	DrawSprite(g_SetTexture,
//		g_ScoreNumber[i].Pos.x, g_ScoreNumber[i].Pos.y,
//		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
//		byouga, 0.0f,
//		0.1f, 1.0f);
//	break;
//case 3:
//	g_SetTexture = g_ScoreTextureIndex4;
//	DrawSprite(g_SetTexture,
//		g_ScoreNumber[i].Pos.x, g_ScoreNumber[i].Pos.y,
//		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
//		byouga, 0.0f,
//		0.1f, 1.0f);
//	break;
//case 4:
//	g_SetTexture = g_ScoreTextureIndex5;
//	DrawSprite(g_SetTexture,
//		g_ScoreNumber[i].Pos.x, g_ScoreNumber[i].Pos.y,
//		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
//		byouga, 0.0f,
//		0.1f, 1.0f);
//	break;
//case 5:
//	g_SetTexture = g_ScoreTextureIndex6;
//	DrawSprite(g_SetTexture,
//		g_ScoreNumber[i].Pos.x, g_ScoreNumber[i].Pos.y,
//		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
//		byouga, 0.0f,
//		0.1f, 1.0f);
//	break;
//case 6:
//	g_SetTexture = g_ScoreTextureIndex7;
//	DrawSprite(g_SetTexture,
//		g_ScoreNumber[i].Pos.x, g_ScoreNumber[i].Pos.y,
//		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
//		byouga, 0.0f,
//		0.1f, 1.0f);
//	break;
//
//default:
//	char str[256];
//	sprintf_s(str, "エラー \n");
//	OutputDebugString(str);
//	break;
//}
//		}

//int ShiftScorePos()
//{
//
//}