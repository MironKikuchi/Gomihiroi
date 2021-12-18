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
#include "score.h"
#include "highscoreresult.h"


/*------------------------------------------------------------------------------
構造体宣言
------------------------------------------------------------------------------*/
typedef struct
{
	D3DXVECTOR3 Pos;

}HIGH_T;


/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static HIGH_T g_HighResultButton;

static int g_BgTextureIndex;
static int g_ResultTextureIndex;

static int g_HighScoreFontTextureIndex;
static int g_HighScoreNumberTextureIndex;
float g_Highbyouga;
float g_High10byouga;
float g_High100byouga;
float g_High1000byouga;
float g_High10000byouga;
float g_High100000byouga;
float g_High1000000byouga;

static int g_1stScoreTextureIndex;
static int g_1stScoreNumberTextureIndex;
float g_1stbyouga;
float g_1st10byouga;
float g_1st100byouga;
float g_1st1000byouga;
float g_1st10000byouga;
float g_1st100000byouga;
float g_1st1000000byouga;

static int g_2ndScoreTextureIndex;
static int g_2ndScoreNumberTextureIndex;
float g_2ndbyouga;
float g_2nd10byouga;
float g_2nd100byouga;
float g_2nd1000byouga;
float g_2nd10000byouga;
float g_2nd100000byouga;
float g_2nd1000000byouga;

static int g_3rdScoreTextureIndex;
static int g_3rdScoreNumberTextureIndex;
float g_3rdbyouga;
float g_3rd10byouga;
float g_3rd100byouga;
float g_3rd1000byouga;
float g_3rd10000byouga;
float g_3rd100000byouga;
float g_3rd1000000byouga;

static int g_4thScoreTextureIndex;
static int g_4thScoreNumberTextureIndex;
float g_4thbyouga;
float g_4th10byouga;
float g_4th100byouga;
float g_4th1000byouga;
float g_4th10000byouga;
float g_4th100000byouga;
float g_4th1000000byouga;

static int g_5thScoreTextureIndex;
static int g_5thScoreNumberTextureIndex;
float g_5thbyouga;
float g_5th10byouga;
float g_5th100byouga;
float g_5th1000byouga;
float g_5th10000byouga;
float g_5th100000byouga;
float g_5th1000000byouga;

//タイトルに戻るボタン
static int g_ExitTextureIndex;


static int g_BGMIndex = 0;
static int g_HighScore = 0;
static int mouse;


/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitHighResult(void)
{
	g_HighResultButton.Pos.x = (HIGH_RESULTBUTTON_HALF_SIZE_X);
	g_HighResultButton.Pos.y = (HIGH_RESULTBUTTON_HALF_SIZE_Y)+150;

	g_BgTextureIndex = LoadTexture("texture/Title.png");
	g_ResultTextureIndex = LoadTexture("texture/SceneFont5");

	//直近のハイスコアのフォントと数字
	g_HighScoreFontTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");
	g_HighScoreNumberTextureIndex = LoadTexture("texture/number.png");

	//1位のフォントとハイスコアの数字
	g_1stScoreTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");
	g_1stScoreNumberTextureIndex = LoadTexture("texture/number.png");

	//2位のフォントとハイスコアの数字
	g_2ndScoreTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");
	g_2ndScoreNumberTextureIndex = LoadTexture("texture/number.png");

	//3位のフォントとハイスコアの数字
	g_3rdScoreTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");
	g_3rdScoreNumberTextureIndex = LoadTexture("texture/number.png");

	//4位のフォントとハイスコアの数字
	g_4thScoreTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");
	g_4thScoreNumberTextureIndex = LoadTexture("texture/number.png");

	//5位のフォントとハイスコアの数字
	g_5thScoreTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");
	g_5thScoreNumberTextureIndex = LoadTexture("texture/number.png");

	g_ExitTextureIndex = LoadTexture("texture/EXIT_BUTTON.png");

	/*g_BGMIndex = LoadSound("sound/bgm01.WAV");

	PlaySound(g_BGMIndex, -1);*/
}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitHighResult(void)
{

}

/*------------------------------------------------------------------------------
更新処理をする関数
------------------------------------------------------------------------------*/
void UpdateHighResult(HWND hWnd)
{
	POINT mouse_p;
	//マウスの座標ゲッツ
	GetCursorPos(&mouse_p);
	//マウスの座標をスクリーンからクライアント(ウィンドウ)へ
	ScreenToClient(hWnd, &mouse_p);

	/*char str[256];
	sprintf_s(str, "PosX: %d PosY: %d \n", mouse_p.x, mouse_p.y);
	OutputDebugString(str);*/

	//リザルトボタンの当たり判定
	if (mouse_p.x < (SCREEN_HALFWIDTH + EXITBUTTON_SIZE_X) && mouse_p.x >= (SCREEN_HALFWIDTH - EXITBUTTON_SIZE_X) &&
		mouse_p.y < ((SCREEN_HALFHEIGHT - 100) + EXITBUTTON_SIZE_Y)&& mouse_p.y >= ((SCREEN_HALFHEIGHT - 100) - EXITBUTTON_SIZE_Y))
	{
		if (mouse == 1)
		{
			SetScene(SCENE_TITLE);
			CheckScene();
		}
	}

	int NumberChenge = 0;

	NumberChenge = g_HighScore;
	char str[256];
	sprintf_s(str, " %d \n", NumberChenge);
	OutputDebugString(str);

	g_Highbyouga = (float)NumberChenge / 10;

	if (g_HighScore >= 10)
	{
		NumberChenge = g_Highbyouga;
		g_High10byouga = (float)NumberChenge / 10;
	}
	if (g_HighScore >= 100)
	{
		NumberChenge = g_High10byouga;
		g_High100byouga = (float)NumberChenge / 10;
	}
	if (g_HighScore >= 1000)
	{
		NumberChenge = g_High100byouga;
		g_High1000byouga = (float)NumberChenge / 10;
	}
	if (g_HighScore >= 10000)
	{
		NumberChenge = g_High1000byouga;
		g_High10000byouga = (float)NumberChenge / 10;
	}
	if (g_HighScore >= 100000)
	{
		NumberChenge = g_High10000byouga;
		g_High100000byouga = (float)NumberChenge / 10;
	}
	if (g_HighScore >= 1000000)
	{
		NumberChenge = g_High100000byouga;
		g_High1000000byouga = (float)NumberChenge / 10;
	}

	//1位のスコアを見比べる時に使う
	/*g_1stbyouga = (float)NumberChenge / 10;

	if (g_HighScore >= 10)
	{
		NumberChenge = g_1stbyouga;
		g_1st10byouga = (float)NumberChenge / 10;
	}
	if (g_HighScore >= 100)
	{
		NumberChenge = g_1st10byouga;
		g_1st100byouga = (float)NumberChenge / 10;
	}
	if (g_HighScore >= 1000)
	{
		NumberChenge = g_1st100byouga;
		g_1st1000byouga = (float)NumberChenge / 10;
	}
	if (g_HighScore >= 10000)
	{
		NumberChenge = g_1st1000byouga;
		g_1st10000byouga = (float)NumberChenge / 10;
	}
	if (g_HighScore >= 100000)
	{
		NumberChenge = g_1st10000byouga;
		g_1st100000byouga = (float)NumberChenge / 10;
	}
	if (g_HighScore >= 1000000)
	{
		NumberChenge = g_1st100000byouga;
		g_1st1000000byouga = (float)NumberChenge / 10;
	}*/
}

/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/
void DrawHighResult(void)
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

	DrawSprite(g_ExitTextureIndex,
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT) - 100,
		EXITBUTTON_SIZE_X, EXITBUTTON_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);



	//ハイスコアの表示場所
	DrawSprite(g_HighScoreFontTextureIndex,
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT) -300,
		TITLEBUTTON_SIZE_X, TITLEBUTTON_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_HighScoreNumberTextureIndex,
		SCOREFONT_POS_X - 90, SCOREFONT_POS_Y - 560,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_High1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_HighScoreNumberTextureIndex,
		SCOREFONT_POS_X - 60, SCOREFONT_POS_Y - 560,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_High100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_HighScoreNumberTextureIndex,
		SCOREFONT_POS_X - 30, SCOREFONT_POS_Y - 560,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_High10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_HighScoreNumberTextureIndex,
		SCOREFONT_POS_X, SCOREFONT_POS_Y - 560,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_High1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_HighScoreNumberTextureIndex,
		SCOREFONT_POS_X + 30, SCOREFONT_POS_Y - 560,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_High100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_HighScoreNumberTextureIndex,
		SCOREFONT_POS_X + 60, SCOREFONT_POS_Y - 560,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_High10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_HighScoreNumberTextureIndex,
		SCOREFONT_POS_X + 90, SCOREFONT_POS_Y - 560,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_Highbyouga, 0.0f,
		0.1f, 1.0f);



//1位～5位までの表示場所
	//1st
	DrawSprite(g_1stScoreTextureIndex,
		SCREEN_HALFWIDTH - 150, (SCREEN_HALFHEIGHT) + HIGH_1STFONT_POS_Y,
		HIGH_RESULTBUTTON_HALF_SIZE_X, HIGH_RESULTBUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_1st1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 30, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_1st100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 60, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_1st10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 90, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_1st1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_1st100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 150, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_1st10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 180, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_1stbyouga, 0.0f,
		0.1f, 1.0f);

//////////////////////////////////////////////////////////////////////
	//2nd
	DrawSprite(g_2ndScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT) + HIGH_2NDFONT_POS_Y,
		HIGH_RESULTBUTTON_HALF_SIZE_X, HIGH_RESULTBUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_2nd1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 30, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_2nd100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 60, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_2nd10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 90, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_2nd1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_2nd100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 150, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_2nd10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 180, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_2ndbyouga, 0.0f,
		0.1f, 1.0f);
//////////////////////////////////////////////////////////////////////
	//3rd
	DrawSprite(g_3rdScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT) + HIGH_3RDFONT_POS_Y,
		HIGH_RESULTBUTTON_HALF_SIZE_X, HIGH_RESULTBUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_3rd1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 30, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_3rd100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 60, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_3rd10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 90, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_3rd1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_3rd100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 150, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_3rd10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 180, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_3rdbyouga, 0.0f,
		0.1f, 1.0f);
//////////////////////////////////////////////////////////////////////
	//4th
	DrawSprite(g_4thScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT) +HIGH_4THFONT_POS_Y,
		HIGH_RESULTBUTTON_HALF_SIZE_X, HIGH_RESULTBUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);
	
	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_4th1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 30, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_4th100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 60, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_4th10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 90, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_4th1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_4th100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 150, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_4th10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 180, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_4thbyouga, 0.0f,
		0.1f, 1.0f);
//////////////////////////////////////////////////////////////////////
	//5th
	DrawSprite(g_5thScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT) + HIGH_5THFONT_POS_Y,
		HIGH_RESULTBUTTON_HALF_SIZE_X, HIGH_RESULTBUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_5th1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 30, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_5th100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 60, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_5th10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 90, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_5th1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_5th100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 150, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_5th10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 180, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		SCOREFONT_SIZE_X, SCOREFONT_SIZE_Y,
		g_5thbyouga, 0.0f,
		0.1f, 1.0f);
}

void HighResultSetMouse(int index)
{
	mouse = index;
}

void SetScore(int index)
{
	g_HighScore = index;
	return;
}

//int GetScore(void)
//{
//	int NumberChenge = 0;
//
//	NumberChenge = g_HighScore;
//	g_1stbyouga = (float)NumberChenge / 10;
//
//	if (g_HighScore >= 10)
//	{
//		NumberChenge = g_1stbyouga;
//		g_1st10byouga = (float)NumberChenge / 10;
//	}
//	if (g_HighScore >= 100)
//	{
//		NumberChenge = g_1st10byouga;
//		g_1st100byouga = (float)NumberChenge / 10;
//	}
//	if (g_HighScore >= 1000)
//	{
//		NumberChenge = g_1st100byouga;
//		g_1st1000byouga = (float)NumberChenge / 10;
//	}
//	if (g_HighScore >= 10000)
//	{
//		NumberChenge = g_1st1000byouga;
//		g_1st10000byouga = (float)NumberChenge / 10;
//	}
//	if (g_HighScore >= 100000)
//	{
//		NumberChenge = g_1st10000byouga;
//		g_1st100000byouga = (float)NumberChenge / 10;
//	}
//	if (g_HighScore >= 1000000)
//	{
//		NumberChenge = g_1st100000byouga;
//		g_1st1000000byouga = (float)NumberChenge / 10;
//	}
//}