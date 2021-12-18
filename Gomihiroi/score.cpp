#include <Windows.h>
#include <stdio.h>
#include "DirectX.h"
#include "main.h"
#include "texture.h"
#include "sprite.h"
#include "score.h"
#include "level.h"
#include "highscoreresult.h"
#include "normalresult.h"


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

	int i = 0;
	int ScoreChenge = 0;
	
	ScorePointCharge += addScore;
	ScoreChenge = ScorePointCharge;
	byouga1 = (float)ScoreChenge / 10;

	if (ScorePointCharge >= 10)
	{
		ScoreChenge = byouga1;
		byouga2 = (float)ScoreChenge / 10;
	}
	if (ScorePointCharge >= 100)
	{
		ScoreChenge = byouga2;
		byouga3 = (float)ScoreChenge / 10;
	}
	if (ScorePointCharge >= 1000)
	{
		ScoreChenge = byouga3;
		byouga4 = (float)ScoreChenge / 10;
	}
	if (ScorePointCharge >= 10000)
	{
		ScoreChenge = byouga4;
		byouga5= (float)ScoreChenge / 10;
	}
	if (ScorePointCharge >= 100000)
	{
		ScoreChenge = byouga5;
		byouga6 = (float)ScoreChenge / 10;
	}
	if (ScorePointCharge >= 1000000)
	{
		ScoreChenge = byouga6;
		byouga7 = (float)ScoreChenge / 10;
	}

	i += addScore;
	UpdateLevel(i);

	SetScore(ScorePointCharge);
	/*char str[256];
	sprintf_s(str, " %d \n", ScorePointCharge);
	OutputDebugString(str);*/

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