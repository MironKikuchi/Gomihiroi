#include "scene.h"
#include "title.h"
#include "game.h"



/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static SCENE g_SceneIndex = SCENE_GAME;
static SCENE g_ScenePrevIndex = g_SceneIndex;
static SCENE g_SceneNextIndex = g_SceneIndex;


/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitScene(SCENE index)
{
	g_SceneIndex = g_SceneNextIndex = index;

	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		InitTitle();
		break;

	case SCENE_GAME:
		InitGame();
		g_ScenePrevIndex = SCENE_GAME;
		break;


	}
}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitScene(void)
{
	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		UninitTitle();
		break;

	case SCENE_GAME:
		UninitGame();
		break;

	}
}

/*------------------------------------------------------------------------------
更新処理をする関数
------------------------------------------------------------------------------*/
void UpdateScene(HWND hWnd)
{
	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		UpdateTitle(hWnd);
		break;

	case SCENE_GAME:
		UpdateGame(hWnd);
		break;

	}

	//UpdateFade();
}

/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/
void DrawScene(void)
{

	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		DrawTitle();
		break;

	case SCENE_GAME:
		DrawGame();
		break;

	}

	//DrawFade();
}

/*------------------------------------------------------------------------------
シーン遷移を要求する関数
------------------------------------------------------------------------------*/
void SetScene(SCENE index)
{
	//遷移先シーンを設定する
	g_SceneNextIndex = index;
}

/*------------------------------------------------------------------------------
遷移を要求がある場合にシーンを切り替える関数
------------------------------------------------------------------------------*/
void CheckScene(void)
{
	//現在のシーンと遷移先シーンが違っていたら
	if (g_SceneIndex != g_SceneNextIndex)
	{
		//現在のシーンを終了させる
		UninitScene();

		//遷移先シーンの初期化処理を行う
		InitScene(g_SceneNextIndex);
		DrawScene();
	}
}

/*------------------------------------------------------------------------------
GAMEOVER時に現在のシーンを読み込む関数
------------------------------------------------------------------------------*/
void ReviveScene(void)
{
	UninitScene();
	InitScene(g_ScenePrevIndex);
	DrawScene();
}