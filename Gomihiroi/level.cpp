#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include "DirectX.h"
#include "main.h"
#include "texture.h"
#include "sprite.h"
#include "score.h"
#include "level.h"


/*------------------------------------------------------------------------------
構造体宣言
------------------------------------------------------------------------------*/
typedef struct
{
	D3DXVECTOR3 Pos;

}LEVEL_T;


/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static int g_SetTextureIndex;
static int g_SetNextTextureIndex;
static int g_DustTexture;
static int g_BananaTexture;
static int g_EnemyTexture;
static int g_TrashTexture;
static int g_FridgeTexture;

static int LevelExp;
static int ClickLevel;

/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitLevel(void)
{
	g_SetTextureIndex = LoadTexture("texture/Hokori.png");
	g_SetNextTextureIndex = LoadTexture("texture/Banana.png");
	g_DustTexture = LoadTexture("texture/Hokori.png");
	g_BananaTexture = LoadTexture("texture/Banana.png");
	g_EnemyTexture = LoadTexture("texture/Book.png");
	g_TrashTexture = LoadTexture("texture/Gomibukuro.png");
	g_FridgeTexture = LoadTexture("texture/IceBox.png");

}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitLevel(void)
{

}

/*------------------------------------------------------------------------------
更新処理をする関数
------------------------------------------------------------------------------*/
void UpdateLevel(int addLevel)
{
	LevelExp += addLevel;

	

	ChangeLevel(ClickLevel);

	/*char str[256];
	sprintf_s(str, " %d \n", ClickLevel);
	OutputDebugString(str);*/
	
}

/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/
void DrawLevel(void)
{
	DrawSprite(g_SetNextTextureIndex,
		SCREEN_HALFWIDTH - 80, SCREEN_HEIGHT - 100,
		SCREEN_HALFWIDTH - 150, SCREEN_HALFHEIGHT - 350,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_SetTextureIndex,
		SCREEN_HALFWIDTH - 200, SCREEN_HEIGHT - 100,
		SCREEN_HALFWIDTH - 150, SCREEN_HALFHEIGHT - 350,
		0.0f, 0.0f,
		1.0f, 1.0f);
}

void ChangeLevel(int setlevel)
{
	if (LevelExp >= 50)
	{
		ClickLevel = LEVEL_BANANA;
		g_SetTextureIndex = g_BananaTexture;
		g_SetNextTextureIndex = g_EnemyTexture;
	}
	if(LevelExp >= 100)
	{
		ClickLevel = LEVEL_BOOK;
		g_SetTextureIndex = g_EnemyTexture;
		g_SetNextTextureIndex = g_TrashTexture;
	}
	if (LevelExp >= 200)
	{
		ClickLevel = LEVEL_TRASH;
		g_SetTextureIndex = g_TrashTexture;
		g_SetNextTextureIndex = g_FridgeTexture;
	}
	if (LevelExp >= 500)
	{
		ClickLevel = LEVEL_FRIDGE;
		g_SetTextureIndex = g_FridgeTexture;
		g_SetNextTextureIndex = 0;
	}

}

int GetLevel()
{
	return ClickLevel;
}