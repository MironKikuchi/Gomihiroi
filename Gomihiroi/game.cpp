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
//#include "collision.h"
#include "input.h"
#include "sprite.h"

static int g_BgTextureIndex;
static int g_BGMIndex = 0;

/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitGame(void)
{
	g_BgTextureIndex = LoadTexture("texture/car_road.png");
	InitPuzzle();
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

}

/*------------------------------------------------------------------------------
更新処理をする関数
------------------------------------------------------------------------------*/
void UpdateGame(HWND hWnd)
{
	UpdatePuzzle(hWnd);


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
}

