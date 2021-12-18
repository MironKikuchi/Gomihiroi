#include <Windows.h>
#include <stdio.h>
#include "DirectX.h"
#include "main.h"
#include "scene.h"
//#include "input.h"
//#include "fade.h"
//#include "sound.h"
#include "texture.h"
#include "sprite.h"
#include "title.h"
#include "normalresult.h"


/*------------------------------------------------------------------------------
構造体宣言
------------------------------------------------------------------------------*/
typedef struct
{
	D3DXVECTOR3 Pos;

}NORMAL_T;


/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static NORMAL_T g_NormalResultButton;

static int g_BgTextureIndex;
static int g_ResultTextureIndex;
static int g_NormalScoreTextureIndex;

static int g_1stScoreTextureIndex;
static int g_2ndScoreTextureIndex;
static int g_3rdScoreTextureIndex;
static int g_4thScoreTextureIndex;
static int g_5thScoreTextureIndex;

static int g_ExitTextureIndex;
static int g_BGMIndex = 0;
static int mouse;


/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitNormalResult(void)
{
	g_NormalResultButton.Pos.x = (NORMAL_RESULTBUTTON_HALF_SIZE_X);
	g_NormalResultButton.Pos.y = (NORMAL_RESULTBUTTON_HALF_SIZE_Y)+150;

	g_BgTextureIndex = LoadTexture("texture/Title.png");
	g_ResultTextureIndex = LoadTexture("texture/SceneFont5");
	g_NormalScoreTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");

	g_1stScoreTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");
	g_2ndScoreTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");
	g_3rdScoreTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");
	g_4thScoreTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");
	g_5thScoreTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");

	g_ExitTextureIndex = LoadTexture("texture/EXIT_BUTTON.png");

	/*g_BGMIndex = LoadSound("sound/bgm01.WAV");

	PlaySound(g_BGMIndex, -1);*/
}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitNormalResult(void)
{

}

/*------------------------------------------------------------------------------
更新処理をする関数
------------------------------------------------------------------------------*/
void UpdateNormalResult(HWND hWnd)
{
	POINT mouse_p;
	//マウスの座標ゲッツ
	GetCursorPos(&mouse_p);
	//マウスの座標をスクリーンからクライアント(ウィンドウ)へ
	ScreenToClient(hWnd, &mouse_p);

	char str[256];
	sprintf_s(str, "PosX: %d PosY: %d \n", mouse_p.x, mouse_p.y);
	OutputDebugString(str);

	//リザルトボタンの当たり判定
	if (mouse_p.x < (SCREEN_HALFWIDTH + NORMAL_RESULTBUTTON_HALF_SIZE_X) && mouse_p.x >= (SCREEN_HALFWIDTH - NORMAL_RESULTBUTTON_HALF_SIZE_X) &&
		mouse_p.y < (SCREEN_HALFHEIGHT + NORMAL_RESULTBUTTON_HALF_SIZE_Y) + 300 && mouse_p.y >= (SCREEN_HALFHEIGHT - NORMAL_RESULTBUTTON_HALF_SIZE_Y) + 300)
	{
		if (mouse == 1)
		{
			SetScene(SCENE_TITLE);
			CheckScene();
		}
	}

}

/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/
void DrawNormalResult(void)
{
	DrawSprite(g_BgTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		0.0f, 0.0f,
		1.0f, 1.0f);

	/*DrawSprite(g_ResultTextureIndex,
		(TITLEFONT_SIZE_X) + 60, (TITLEFONT_SIZE_Y)+60,
		TITLEFONT_SIZE_X, TITLEFONT_SIZE_Y,
		0.0f, 0.0f,
		1.0f, 1.0f);*/

	DrawSprite(g_NormalScoreTextureIndex,
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT)-200,
		NORMAL_RESULTBUTTON_SIZE_X, NORMAL_RESULTBUTTON_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_ExitTextureIndex,
		(SCREEN_HALFWIDTH)+150, (SCREEN_HALFHEIGHT)+400,
		NORMAL_RESULTBUTTON_SIZE_X, NORMAL_RESULTBUTTON_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);




	DrawSprite(g_1stScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT),
		NORMAL_RESULTBUTTON_HALF_SIZE_X, NORMAL_RESULTBUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_2ndScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT)+100,
		NORMAL_RESULTBUTTON_HALF_SIZE_X, NORMAL_RESULTBUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_3rdScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT)+200,
		NORMAL_RESULTBUTTON_HALF_SIZE_X, NORMAL_RESULTBUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_4thScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT)+300,
		NORMAL_RESULTBUTTON_HALF_SIZE_X, NORMAL_RESULTBUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_5thScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT)+400,
		NORMAL_RESULTBUTTON_HALF_SIZE_X, NORMAL_RESULTBUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);
}

void NormalResultSetMouse(int index)
{
	mouse = index;
}