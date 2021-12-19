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


/*------------------------------------------------------------------------------
構造体宣言
------------------------------------------------------------------------------*/
typedef struct
{
	D3DXVECTOR3 Pos;

}TITLE_T;


/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static TITLE_T g_TitleButton;

static int g_BgTextureIndex;
static int g_TitleTextureIndex;
static int g_StartTextureIndex;
static int g_ExitTextureIndex;
static int g_BGMIndex = 0;
static int mouse;


/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitTitle(void)
{
	g_TitleButton.Pos.x = (TITLEBG_HALF_SIZE_X);
	g_TitleButton.Pos.y = (TITLEBG_HALF_SIZE_Y) + 150;

	g_BgTextureIndex = LoadTexture("texture/Title.png");
	g_TitleTextureIndex = LoadTexture("texture/Title02.png");
	g_StartTextureIndex = LoadTexture("texture/Play.png");
	g_ExitTextureIndex = LoadTexture("texture/Rizart.png");

	/*g_BGMIndex = LoadSound("sound/bgm01.WAV");

	PlaySound(g_BGMIndex, -1);*/
}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitTitle(void)
{
	g_TitleButton.Pos.x = (TITLEBG_HALF_SIZE_X);
	g_TitleButton.Pos.y = (TITLEBG_HALF_SIZE_Y)+150;

}

/*------------------------------------------------------------------------------
更新処理をする関数
------------------------------------------------------------------------------*/
void UpdateTitle(HWND hWnd)
{
	POINT mouse_p;
	//マウスの座標ゲッツ
	GetCursorPos(&mouse_p);
	//マウスの座標をスクリーンからクライアント(ウィンドウ)へ
	ScreenToClient(hWnd, &mouse_p);

	char str[256];
	sprintf_s(str, "PosX: %d PosY: %d \n", mouse_p.x, mouse_p.y);
	OutputDebugString(str);

	//タイトルのボタンの当たり判定
	if (mouse_p.x < BUTTON_COLLISION_RIGHT && mouse_p.x >= BUTTON_COLLISION_LEFT &&
		mouse_p.y < BUTTON_COLLISION_DOWN && mouse_p.y >= BUTTON_COLLISION_UP)
	{
		if (mouse == 1)
		{
			SetScene(SCENE_GAME);
			CheckScene();
		}
	}

}

/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/
void DrawTitle(void)
{
	DrawSprite(g_BgTextureIndex,
		SCREEN_HALFWIDTH,SCREEN_HALFHEIGHT,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_TitleTextureIndex,
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT) - 360,
		TITLEFONT_SIZE_X, TITLEFONT_SIZE_Y,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_StartTextureIndex,
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT) + 200,
		TITLEBUTTON_SIZE_X, TITLEBUTTON_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_ExitTextureIndex,
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT) + 400,
		TITLEBUTTON_SIZE_X, TITLEBUTTON_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);
}

void TitleSetMouse(int index)
{
	mouse = index;
}