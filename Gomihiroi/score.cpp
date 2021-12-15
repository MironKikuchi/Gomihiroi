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
static SCORE_T g_ScoreButton;

static int g_ScoreTextureIndex;

//取得したスコアポイントの入れ物
static int ScorePointContainer = 0;

static int ScorePointCharge = 0;

//ループした数を入れる
int g_Shift;

int g_CountNumber[SCORE_MAX];



/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitScore(void)
{
	g_ScoreButton.Pos.x = (SCORE_SIZE_X);
	g_ScoreButton.Pos.x = (SCORE_SIZE_Y) + 150;

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
void UpdateScore(void)
{
	/*char str[256];
	sprintf_s(str, "ポイント: %d Score: %d \n", ScorePointContainer, ScorePointCharge);
	OutputDebugString(str);*/
	/*char str[256];
	sprintf_s(str, " %d \n", SCOREFONT_POS_X);
	OutputDebugString(str);*/
	//char str[256];
	//sprintf_s(str, " %d \n", SCOREFONT_POS_X);
	//OutputDebugString(str);
}

/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/
void DrawScore(void)
{

	for (int i = 0; i < _countof(g_CountNumber); i++)
	{
		DrawSprite(g_ScoreTextureIndex,
			SCOREFONT_POS_X, SCOREFONT_POS_Y,
			SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
			0.1f + (i % 10), 0.0f,
			0.1f, 1.0f);
		ScorePointCharge += ScorePointContainer;
	}


	/*if (ScorePointContainer != 0)
	{
		ScorePointCharge += ScorePointContainer;
		for (int n = 0; n < ScorePointCharge; n++)
		{

			for (int i = 0; i < sizeof(g_Shift); i++)
			{
				DrawSprite(g_ScoreTextureIndex,
					SCOREFONT_POS_X, SCOREFONT_POS_Y,
					SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
					0.0f, 0.0f,
					0.1f, 1.0f);
				
			}
		}

		ScorePointContainer = 0;
	}
	else
	{
		for (int i = 0; i < sizeof(g_Shift); i++)
		{
			DrawSprite(g_ScoreTextureIndex,
				SCOREFONT_POS_X, SCOREFONT_POS_Y,
				SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
				0.0f, 0.0f,
				0.1f, 1.0f);
		}
	}*/
}

//int ShiftScorePos()
//{
//
//}
int SetScorePoint(int index)
{
	ScorePointContainer = index;
	return ScorePointContainer;
}