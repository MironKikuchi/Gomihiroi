#include <windows.h>
#include <stdio.h>
#include "game.h"
#include "main.h"
#include "DirectX.h"
#include "scene.h"
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

static int g_BgTextureIndex;
static int g_BGMIndex = 0;

/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitGame(void)
{
	g_BgTextureIndex = LoadTexture("texture/car_road.png");
	InitPuzzle();
	InitPuzzle2();
	InitPuzzle3();
	InitPuzzle4();
	InitPuzzle5();

	InitScore();
	//g_BGMIndex = LoadSound("sound/bgm01.wav");

	// クリアカラーを水色に変更
	SetClearColor(100, 100, 200);
}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitGame(void)
{
	UninitPuzzle();
	UninitPuzzle2();
	UninitPuzzle3();
	UninitPuzzle4();
	UninitPuzzle5();

	UninitScore();
}

/*------------------------------------------------------------------------------
更新処理をする関数
------------------------------------------------------------------------------*/
void UpdateGame(HWND hWnd)
{
	UpdatePuzzle(hWnd);
	UpdatePuzzle2(hWnd);
	UpdatePuzzle3(hWnd);
	UpdatePuzzle4(hWnd);
	UpdatePuzzle5(hWnd);
	//全ての移動処理が終わってから当たり判定を行う
	//UpdateCollision();


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


	DrawPuzzle();
	DrawPuzzle2();
	DrawPuzzle3();
	DrawPuzzle4();
	DrawPuzzle5();

	DrawScore();
}

