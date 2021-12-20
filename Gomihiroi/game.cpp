#include <windows.h>
#include <stdio.h>
#include "main.h"
#include "DirectX.h"
#include "scene.h"
#include "Title.h"
#include "game.h"
//#include "fade.h"
//#include "sound.h"
#include "texture.h"
#include "PuzzleBlock.h"
#include "PuzzleBlock2.h"
#include "PuzzleBlock3.h"
#include "PuzzleBlock4.h"
#include "PuzzleBlock5.h"
#include "input.h"
#include "sprite.h"
#include "score.h"
#include "level.h"
#include "timeLimit.h"

static int g_BgTextureIndex;
static int g_SubBgTextureIndex;
static int g_FrameTextureIndex;
static int g_BGMIndex = 0;

/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitGame(void)
{
	
	g_BgTextureIndex = LoadTexture("texture/car_road.png");
	g_SubBgTextureIndex = LoadTexture("texture/white.jpeg");
	g_FrameTextureIndex = LoadTexture("texture/Waku.png");
	InitDust();
	InitBanana();
	InitBook();
	InitTrash();
	InitFridge();

	InitScore();
	InitLevel();
	InitTime();
	//g_BGMIndex = LoadSound("sound/bgm01.wav");

	// クリアカラーを水色に変更
	SetClearColor(100, 100, 200);
}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitGame(void)
{
	UninitDust();
	UninitBanana();
	UninitBook();
	UninitTrash();
	UninitFridge();

	UninitScore();
	UninitLevel();
	UninitTime();
}

/*------------------------------------------------------------------------------
更新処理をする関数
------------------------------------------------------------------------------*/
void UpdateGame(HWND hWnd)
{
	UpdateDust(hWnd);
	UpdateBanana(hWnd);
	UpdateBook(hWnd);
	UpdateTrash(hWnd);
	UpdateFridge(hWnd);

}

/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/
void DrawGame(void)
{
	DrawSprite(g_BgTextureIndex,
		SCREEN_HALFWIDTH,SCREEN_HALFHEIGHT,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		0.0f, 0.0f,
		1.0f, 1.0f);


	DrawDust();
	DrawBanana();
	DrawBook();
	DrawTrash();
	DrawFridge();

	DrawSprite(g_SubBgTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_TOP,
		SCREEN_WIDTH, SCREEN_HALFHEIGHT -200,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_FrameTextureIndex,
		SCREEN_HALFWIDTH - 120, SCREEN_TOP + 80,
		SCREEN_HALFWIDTH - 200, SCREEN_HALFHEIGHT - 400,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_FrameTextureIndex,
		SCREEN_HALFWIDTH - 200, SCREEN_TOP + 80,
		SCREEN_HALFWIDTH - 200, SCREEN_HALFHEIGHT - 400,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawScore();
	DrawLevel();

	DrawTime();
}

