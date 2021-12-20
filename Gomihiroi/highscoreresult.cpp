#define _CRT_SECURE_NO_WARNINGS
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
#include "timelimit.h"
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
float	g_1stbyouga;
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

static int g_1stChenge = 0;
static int g_2stChenge = 0;
static int g_3stChenge = 0;
static int g_4stChenge = 0;
static int g_5stChenge = 0;

static int g_BGMIndex = 0;
static int g_HighScore = 0;
static int g_HighScorePass = 0;
static int mouse;


/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitHighResult(void)
{
	g_HighResultButton.Pos.x = (HIGH_RESULTBUTTON_HALF_SIZE_X);
	g_HighResultButton.Pos.y = (HIGH_RESULTBUTTON_HALF_SIZE_Y)+150;

	g_BgTextureIndex = LoadTexture("texture/Title.png");
	g_ResultTextureIndex = LoadTexture("texture/Result.png");

	//直近のハイスコアのフォントと数字
	g_HighScoreFontTextureIndex = LoadTexture("texture/Highscore.png");
	g_HighScoreNumberTextureIndex = LoadTexture("texture/Newnumber.png");

	//1位のフォントとハイスコアの数字
	g_1stScoreTextureIndex = LoadTexture("texture/1st.png");
	g_1stScoreNumberTextureIndex = LoadTexture("texture/Newnumber.png");

	//2位のフォントとハイスコアの数字
	g_2ndScoreTextureIndex = LoadTexture("texture/2nd.png");
	g_2ndScoreNumberTextureIndex = LoadTexture("texture/Newnumber.png");

	//3位のフォントとハイスコアの数字
	g_3rdScoreTextureIndex = LoadTexture("texture/3rd.png");
	g_3rdScoreNumberTextureIndex = LoadTexture("texture/Newnumber.png");

	//4位のフォントとハイスコアの数字
	g_4thScoreTextureIndex = LoadTexture("texture/4th.png");
	g_4thScoreNumberTextureIndex = LoadTexture("texture/Newnumber.png");

	//5位のフォントとハイスコアの数字
	g_5thScoreTextureIndex = LoadTexture("texture/5th.png");
	g_5thScoreNumberTextureIndex = LoadTexture("texture/Newnumber.png");

	g_ExitTextureIndex = LoadTexture("texture/titlemodoru1.png");

	/*g_BGMIndex = LoadSound("sound/bgm01.WAV");

	PlaySound(g_BGMIndex, -1);*/
}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitHighResult(void)
{
	g_HighScore			= 0;
	g_Highbyouga		= 0.0f;
	g_High10byouga		= 0.0f;
	g_High100byouga		= 0.0f;
	g_High1000byouga	= 0.0f;
	g_High10000byouga	= 0.0f;
	g_High100000byouga	= 0.0f;
	g_High1000000byouga = 0.0f;

	g_1stbyouga		    = 0.0f;
	g_1st10byouga	    = 0.0f;
	g_1st100byouga	    = 0.0f;
	g_1st1000byouga     = 0.0f;
	g_1st10000byouga	= 0.0f;
	g_1st100000byouga	= 0.0f;
	g_1st1000000byouga	= 0.0f;

	g_2ndbyouga			= 0.0f;
	g_2nd10byouga		= 0.0f;
	g_2nd100byouga		= 0.0f;
	g_2nd1000byouga		= 0.0f;
	g_2nd10000byouga	= 0.0f;
	g_2nd100000byouga	= 0.0f;
	g_2nd1000000byouga	= 0.0f;

	g_3rdbyouga			= 0.0f;
	g_3rd10byouga		= 0.0f;
	g_3rd100byouga		= 0.0f;
	g_3rd1000byouga		= 0.0f;
	g_3rd10000byouga	= 0.0f;
	g_3rd100000byouga	= 0.0f;
	g_3rd1000000byouga	= 0.0f;

	g_4thbyouga			= 0.0f;
	g_4th10byouga		= 0.0f;
	g_4th100byouga		= 0.0f;
	g_4th1000byouga		= 0.0f;
	g_4th10000byouga	= 0.0f;
	g_4th100000byouga	= 0.0f;
	g_4th1000000byouga	= 0.0f;

	g_5thbyouga			= 0.0f;
	g_5th10byouga		= 0.0f;
	g_5th100byouga		= 0.0f;
	g_5th1000byouga		= 0.0f;
	g_5th10000byouga	= 0.0f;
	g_5th100000byouga	= 0.0f;
	g_5th1000000byouga	= 0.0f;
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
	if (mouse_p.x < (SCREEN_HALFWIDTH + EXITBUTTON_SIZE_X) - 152 && mouse_p.x >= (SCREEN_HALFWIDTH - EXITBUTTON_SIZE_X) + 152 &&
		mouse_p.y < SCREEN_HALFHEIGHT -30 && mouse_p.y >= SCREEN_HALFHEIGHT - 80)
	{
		if (mouse == 1)
		{
			SetScene(SCENE_TITLE);
			CheckScene();
		}
	}

	int NumberChenge = 0;

	

	NumberChenge = g_HighScore;
	/*char str[256];
	sprintf_s(str, " %d \n", NumberChenge);
	OutputDebugString(str);*/

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

	DrawSprite(g_ResultTextureIndex,
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT)-380,
		HIGH_RESULTFONT_SIZE_X, HIGH_RESULTFONT_SIZE_Y,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_ExitTextureIndex,
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT) - 50,
		EXITBUTTON_SIZE_X, EXITBUTTON_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);



	//ハイスコアの表示場所
	DrawSprite(g_HighScoreFontTextureIndex,
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT) -250,
		HIGH_SCORE_SIZE_X, HIGH_SCORE_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);
	
	DrawSprite(g_HighScoreNumberTextureIndex,
		SCREEN_HALFWIDTH - 120,(SCREEN_HALFHEIGHT) -HIGH_SCORE_NUMBER_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_High1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_HighScoreNumberTextureIndex,
		SCREEN_HALFWIDTH - 80,(SCREEN_HALFHEIGHT) -HIGH_SCORE_NUMBER_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_High100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_HighScoreNumberTextureIndex,
		SCREEN_HALFWIDTH - 40,(SCREEN_HALFHEIGHT) -HIGH_SCORE_NUMBER_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_High10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_HighScoreNumberTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT - HIGH_SCORE_NUMBER_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_High1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_HighScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 40,(SCREEN_HALFHEIGHT) -HIGH_SCORE_NUMBER_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_High100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_HighScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 80,(SCREEN_HALFHEIGHT) -HIGH_SCORE_NUMBER_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_High10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_HighScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120,(SCREEN_HALFHEIGHT) -HIGH_SCORE_NUMBER_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
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
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_1st1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 40, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_1st100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 80, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_1st10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_1st1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 160, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_1st100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 200, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_1st10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 240, SCREEN_HALFHEIGHT + HIGH_1ST_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
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
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_2nd1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 40, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_2nd100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 80, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_2nd10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_2nd1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 160, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_2nd100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 200, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_2nd10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 240, SCREEN_HALFHEIGHT + HIGH_2ND_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
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
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_3rd1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 40, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_3rd100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 80, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_3rd10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_3rd1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 160, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_3rd100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 200, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_3rd10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 240, SCREEN_HALFHEIGHT + HIGH_3RD_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
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
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_4th1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 40, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_4th100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 80, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_4th10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_4th1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 160, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_4th100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 200, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_4th10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 240, SCREEN_HALFHEIGHT + HIGH_4TH_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
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
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_5th1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 40, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_5th100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 80, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_5th10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_5th1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 160, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_5th100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 200, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_5th10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 240, SCREEN_HALFHEIGHT + HIGH_5TH_POS_Y,
		HIGH_SCORE_NUMBER_SIZE_X, HIGH_SCORE_NUMBER_SIZE_Y,
		g_5thbyouga, 0.0f,
		0.1f, 1.0f);
}

void HighResultSetMouse(int index)
{
	mouse = index;
}

void SetHighScore(int index)
{
	g_HighScore = index;
	SaveHighScore(g_HighScore);
}

void SaveHighScore(int score)
{
	int i;
	FILE *fp;
	fp = fopen("1stscore.txt", "r");
	fscanf(fp, "%d", &i);
	HighScoreJudge(score);
	if (i < score)
	{
		fp = fopen("1stscore.txt", "w");
		fprintf(fp, "%d", score);
		fclose(fp);
		g_1stChenge = score;

		g_1stbyouga = (float)g_1stChenge / 10;

		if (g_HighScore >= 10)
		{
			g_1stChenge = g_1stbyouga;
			g_1st10byouga = (float)g_1stChenge / 10;
		}
		if (g_HighScore >= 100)
		{
			g_1stChenge = g_1st10byouga;
			g_1st100byouga = (float)g_1stChenge / 10;
		}
		if (g_HighScore >= 1000)
		{
			g_1stChenge = g_1st100byouga;
			g_1st1000byouga = (float)g_1stChenge / 10;
		}
		if (g_HighScore >= 10000)
		{
			g_1stChenge = g_1st1000byouga;
			g_1st10000byouga = (float)g_1stChenge / 10;
		}
		if (g_HighScore >= 100000)
		{
			g_1stChenge = g_1st10000byouga;
			g_1st100000byouga = (float)g_1stChenge / 10;
		}
		if (g_HighScore >= 1000000)
		{
			g_1stChenge = g_1st100000byouga;
			g_1st1000000byouga = (float)g_1stChenge / 10;
		}
	}
	else
	{
		g_1stChenge = i;

		g_1stbyouga = (float)g_1stChenge / 10;

		if (g_HighScore >= 10)
		{
			g_1stChenge = g_1stbyouga;
			g_1st10byouga = (float)g_1stChenge / 10;
		}
		if (g_HighScore >= 100)
		{
			g_1stChenge = g_1st10byouga;
			g_1st100byouga = (float)g_1stChenge / 10;
		}
		if (g_HighScore >= 1000)
		{
			g_1stChenge = g_1st100byouga;
			g_1st1000byouga = (float)g_1stChenge / 10;
		}
		if (g_HighScore >= 10000)
		{
			g_1stChenge = g_1st1000byouga;
			g_1st10000byouga = (float)g_1stChenge / 10;
		}
		if (g_HighScore >= 100000)
		{
			g_1stChenge = g_1st10000byouga;
			g_1st100000byouga = (float)g_1stChenge / 10;
		}
		if (g_HighScore >= 1000000)
		{
			g_1stChenge = g_1st100000byouga;
			g_1st1000000byouga = (float)g_1stChenge / 10;
		}
	}
	//fp = fopen("1stscore.txt", "w");
 	
	fclose(fp);
	
}

//int PassHighScore(void)
//{
//	return g_HighScorePass;
//}

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