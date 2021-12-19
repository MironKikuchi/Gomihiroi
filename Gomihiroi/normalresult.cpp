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

static int g_NormalScoreFontTextureIndex;
static int g_NormalScoreNumberTextureIndex;
float g_Normalbyouga;
float g_Normal10byouga;
float g_Normal100byouga;
float g_Normal1000byouga;
float g_Normal10000byouga;
float g_Normal100000byouga;
float g_Normal1000000byouga;

static int g_n_1stScoreTextureIndex;
static int g_n_1stScoreNumberTextureIndex;
float g_n_1stbyouga;
float g_n_1st10byouga;
float g_n_1st100byouga;
float g_n_1st1000byouga;
float g_n_1st10000byouga;
float g_n_1st100000byouga;
float g_n_1st1000000byouga;

static int g_n_2ndScoreTextureIndex;
static int g_n_2ndScoreNumberTextureIndex;
float g_n_2ndbyouga;
float g_n_2nd10byouga;
float g_n_2nd100byouga;
float g_n_2nd1000byouga;
float g_n_2nd10000byouga;
float g_n_2nd100000byouga;
float g_n_2nd1000000byouga;

static int g_n_3rdScoreTextureIndex;
static int g_n_3rdScoreNumberTextureIndex;
float g_n_3rdbyouga;
float g_n_3rd10byouga;
float g_n_3rd100byouga;
float g_n_3rd1000byouga;
float g_n_3rd10000byouga;
float g_n_3rd100000byouga;
float g_n_3rd1000000byouga;

static int g_n_4thScoreTextureIndex;
static int g_n_4thScoreNumberTextureIndex;
float g_n_4thbyouga;
float g_n_4th10byouga;
float g_n_4th100byouga;
float g_n_4th1000byouga;
float g_n_4th10000byouga;
float g_n_4th100000byouga;
float g_n_4th1000000byouga;

static int g_n_5thScoreTextureIndex;
static int g_n_5thScoreNumberTextureIndex;
float g_n_5thbyouga;
float g_n_5th10byouga;
float g_n_5th100byouga;
float g_n_5th1000byouga;
float g_n_5th10000byouga;
float g_n_5th100000byouga;
float g_n_5th1000000byouga;

//タイトルに戻るボタン
static int g_ExitTextureIndex;

static int g_n_1stChenge = 0;
static int g_n_2stChenge = 0;
static int g_n_3stChenge = 0;
static int g_n_4stChenge = 0;
static int g_n_5stChenge = 0;

static int g_BGMIndex = 0;
static int g_NormalScore = 0;
static int g_NormalScorePass = 0;
static int mouse;


/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitNormalResult(void)
{
	g_NormalResultButton.Pos.x = (NORMAL_RESULT_BUTTON_HALF_SIZE_X);
	g_NormalResultButton.Pos.y = (NORMAL_RESULT_BUTTON_HALF_SIZE_Y)+150;

	g_BgTextureIndex = LoadTexture("texture/Title.png");
	g_ResultTextureIndex = LoadTexture("texture/Result.png");

	//直近のハイスコアのフォントと数字
	g_NormalScoreFontTextureIndex = LoadTexture("texture/Normalscore.png");
	g_NormalScoreNumberTextureIndex = LoadTexture("texture/Newnumber.png");

	//1位のフォントとハイスコアの数字
	g_n_1stScoreTextureIndex = LoadTexture("texture/1st.png");
	g_n_1stScoreNumberTextureIndex = LoadTexture("texture/Newnumber.png");

	//2位のフォントとハイスコアの数字
	g_n_2ndScoreTextureIndex = LoadTexture("texture/2nd.png");
	g_n_2ndScoreNumberTextureIndex = LoadTexture("texture/Newnumber.png");

	//3位のフォントとハイスコアの数字
	g_n_3rdScoreTextureIndex = LoadTexture("texture/3rd.png");
	g_n_3rdScoreNumberTextureIndex = LoadTexture("texture/Newnumber.png");

	//4位のフォントとハイスコアの数字
	g_n_4thScoreTextureIndex = LoadTexture("texture/4th.png");
	g_n_4thScoreNumberTextureIndex = LoadTexture("texture/Newnumber.png");

	//5位のフォントとハイスコアの数字
	g_n_5thScoreTextureIndex = LoadTexture("texture/5th.png");
	g_n_5thScoreNumberTextureIndex = LoadTexture("texture/Newnumber.png");

	g_ExitTextureIndex = LoadTexture("texture/EXIT_BUTTON.png");

	/*g_BGMIndex = LoadSound("sound/bgm01.WAV");

	PlaySound(g_BGMIndex, -1);*/
}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitNormalResult(void)
{
	g_NormalScore = 0;
	g_Normalbyouga = 0.0f;
	g_Normal10byouga = 0.0f;
	g_Normal100byouga = 0.0f;
	g_Normal1000byouga = 0.0f;
	g_Normal10000byouga = 0.0f;
	g_Normal100000byouga = 0.0f;
	g_Normal1000000byouga = 0.0f;

	g_n_1stbyouga = 0.0f;
	g_n_1st10byouga = 0.0f;
	g_n_1st100byouga = 0.0f;
	g_n_1st1000byouga = 0.0f;
	g_n_1st10000byouga = 0.0f;
	g_n_1st100000byouga = 0.0f;
	g_n_1st1000000byouga = 0.0f;

	g_n_2ndbyouga = 0.0f;
	g_n_2nd10byouga = 0.0f;
	g_n_2nd100byouga = 0.0f;
	g_n_2nd1000byouga = 0.0f;
	g_n_2nd10000byouga = 0.0f;
	g_n_2nd100000byouga = 0.0f;
	g_n_2nd1000000byouga = 0.0f;

	g_n_3rdbyouga = 0.0f;
	g_n_3rd10byouga = 0.0f;
	g_n_3rd100byouga = 0.0f;
	g_n_3rd1000byouga = 0.0f;
	g_n_3rd10000byouga = 0.0f;
	g_n_3rd100000byouga = 0.0f;
	g_n_3rd1000000byouga = 0.0f;

	g_n_4thbyouga = 0.0f;
	g_n_4th10byouga = 0.0f;
	g_n_4th100byouga = 0.0f;
	g_n_4th1000byouga = 0.0f;
	g_n_4th10000byouga = 0.0f;
	g_n_4th100000byouga = 0.0f;
	g_n_4th1000000byouga = 0.0f;

	g_n_5thbyouga = 0.0f;
	g_n_5th10byouga = 0.0f;
	g_n_5th100byouga = 0.0f;
	g_n_5th1000byouga = 0.0f;
	g_n_5th10000byouga = 0.0f;
	g_n_5th100000byouga = 0.0f;
	g_n_5th1000000byouga = 0.0f;
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

	/*char str[256];
	sprintf_s(str, "PosX: %d PosY: %d \n", mouse_p.x, mouse_p.y);
	OutputDebugString(str);*/

	//リザルトボタンの当たり判定
	if (mouse_p.x < (SCREEN_HALFWIDTH + EXITBUTTON_SIZE_X) && mouse_p.x >= (SCREEN_HALFWIDTH - EXITBUTTON_SIZE_X) &&
		mouse_p.y < ((SCREEN_HALFHEIGHT - 100) + EXITBUTTON_SIZE_Y) && mouse_p.y >= ((SCREEN_HALFHEIGHT - 100) - EXITBUTTON_SIZE_Y))
	{
		if (mouse == 1)
		{
			SetScene(SCENE_TITLE);
			CheckScene();
		}
	}

	int NumberChenge = 0;



	NumberChenge = g_NormalScore;
	char str[256];
	sprintf_s(str, " %d \n", NumberChenge);
	OutputDebugString(str);

	g_Normalbyouga = (float)NumberChenge / 10;

	if (g_NormalScore >= 10)
	{
		NumberChenge = g_Normalbyouga;
		g_Normal10byouga = (float)NumberChenge / 10;
	}
	if (g_NormalScore >= 100)
	{
		NumberChenge = g_Normal10byouga;
		g_Normal100byouga = (float)NumberChenge / 10;
	}
	if (g_NormalScore >= 1000)
	{
		NumberChenge = g_Normal100byouga;
		g_Normal1000byouga = (float)NumberChenge / 10;
	}
	if (g_NormalScore >= 10000)
	{
		NumberChenge = g_Normal1000byouga;
		g_Normal10000byouga = (float)NumberChenge / 10;
	}
	if (g_NormalScore >= 100000)
	{
		NumberChenge = g_Normal10000byouga;
		g_Normal100000byouga = (float)NumberChenge / 10;
	}
	if (g_NormalScore >= 1000000)
	{
		NumberChenge = g_Normal100000byouga;
		g_Normal1000000byouga = (float)NumberChenge / 10;
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

	DrawSprite(g_ResultTextureIndex,
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT)-380,
		NORMAL_RESULT_FONT_SIZE_X, NORMAL_RESULT_FONT_SIZE_Y,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_ExitTextureIndex,
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT)-50,
		EXITBUTTON_SIZE_X, EXITBUTTON_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);



	//スコアの表示場所
	DrawSprite(g_NormalScoreFontTextureIndex,
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT)-250,
		NORMAL_SCORE_SIZE_X, NORMAL_SCORE_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_NormalScoreNumberTextureIndex,
		SCREEN_HALFWIDTH - 120, (SCREEN_HALFHEIGHT)-NORMAL_SCORE_NUMBER_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_Normal1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_NormalScoreNumberTextureIndex,
		SCREEN_HALFWIDTH - 80, (SCREEN_HALFHEIGHT)-NORMAL_SCORE_NUMBER_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_Normal100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_NormalScoreNumberTextureIndex,
		SCREEN_HALFWIDTH - 40, (SCREEN_HALFHEIGHT)-NORMAL_SCORE_NUMBER_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_Normal10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_NormalScoreNumberTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT - NORMAL_SCORE_NUMBER_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_Normal1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_NormalScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 40, (SCREEN_HALFHEIGHT)-NORMAL_SCORE_NUMBER_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_Normal100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_NormalScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 80, (SCREEN_HALFHEIGHT)-NORMAL_SCORE_NUMBER_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_Normal10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_NormalScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, (SCREEN_HALFHEIGHT)-NORMAL_SCORE_NUMBER_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_Normalbyouga, 0.0f,
		0.1f, 1.0f);



	//1位～5位までの表示場所
		//1st
	DrawSprite(g_n_1stScoreTextureIndex,
		SCREEN_HALFWIDTH - 150, (SCREEN_HALFHEIGHT)+NORMAL_1STFONT_POS_Y,
		NORMAL_RESULT_BUTTON_HALF_SIZE_X, NORMAL_RESULT_BUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_n_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT + NORMAL_1ST_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_1st1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 40, SCREEN_HALFHEIGHT + NORMAL_1ST_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_1st100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 80, SCREEN_HALFHEIGHT + NORMAL_1ST_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_1st10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_n_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + NORMAL_1ST_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_1st1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_n_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 160, SCREEN_HALFHEIGHT + NORMAL_1ST_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_1st100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 200, SCREEN_HALFHEIGHT + NORMAL_1ST_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_1st10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_1stScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 240, SCREEN_HALFHEIGHT + NORMAL_1ST_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_1stbyouga, 0.0f,
		0.1f, 1.0f);

	//////////////////////////////////////////////////////////////////////
		//2nd
	DrawSprite(g_n_2ndScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT)+NORMAL_2NDFONT_POS_Y,
		NORMAL_RESULT_BUTTON_HALF_SIZE_X, NORMAL_RESULT_BUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_n_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT + NORMAL_2ND_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_2nd1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 40, SCREEN_HALFHEIGHT + NORMAL_2ND_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_2nd100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 80, SCREEN_HALFHEIGHT + NORMAL_2ND_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_2nd10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_n_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + NORMAL_2ND_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_2nd1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_n_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 160, SCREEN_HALFHEIGHT + NORMAL_2ND_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_2nd100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 200, SCREEN_HALFHEIGHT + NORMAL_2ND_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_2nd10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_2ndScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 240, SCREEN_HALFHEIGHT + NORMAL_2ND_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_2ndbyouga, 0.0f,
		0.1f, 1.0f);
	//////////////////////////////////////////////////////////////////////
		//3rd
	DrawSprite(g_n_3rdScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT)+NORMAL_3RDFONT_POS_Y,
		NORMAL_RESULT_BUTTON_HALF_SIZE_X, NORMAL_RESULT_BUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_n_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT + NORMAL_3RD_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_3rd1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 40, SCREEN_HALFHEIGHT + NORMAL_3RD_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_3rd100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 80, SCREEN_HALFHEIGHT + NORMAL_3RD_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_3rd10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_n_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + NORMAL_3RD_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_3rd1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_n_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 160, SCREEN_HALFHEIGHT + NORMAL_3RD_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_3rd100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 200, SCREEN_HALFHEIGHT + NORMAL_3RD_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_3rd10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_3rdScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 240, SCREEN_HALFHEIGHT + NORMAL_3RD_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_3rdbyouga, 0.0f,
		0.1f, 1.0f);
	//////////////////////////////////////////////////////////////////////
		//4th
	DrawSprite(g_n_4thScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT)+NORMAL_4THFONT_POS_Y,
		NORMAL_RESULT_BUTTON_HALF_SIZE_X, NORMAL_RESULT_BUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_n_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT + NORMAL_4TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_4th1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 40, SCREEN_HALFHEIGHT + NORMAL_4TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_4th100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 80, SCREEN_HALFHEIGHT + NORMAL_4TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_4th10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_n_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + NORMAL_4TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_4th1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_n_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 160, SCREEN_HALFHEIGHT + NORMAL_4TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_4th100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 200, SCREEN_HALFHEIGHT + NORMAL_4TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_4th10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_4thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 240, SCREEN_HALFHEIGHT + NORMAL_4TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_4thbyouga, 0.0f,
		0.1f, 1.0f);
	//////////////////////////////////////////////////////////////////////
		//5th
	DrawSprite(g_n_5thScoreTextureIndex,
		(SCREEN_HALFWIDTH)-150, (SCREEN_HALFHEIGHT)+NORMAL_5THFONT_POS_Y,
		NORMAL_RESULT_BUTTON_HALF_SIZE_X, NORMAL_RESULT_BUTTON_HALF_SIZE_Y,
		0.0, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_n_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH, SCREEN_HALFHEIGHT + NORMAL_5TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_5th1000000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 40, SCREEN_HALFHEIGHT + NORMAL_5TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_5th100000byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 80, SCREEN_HALFHEIGHT + NORMAL_5TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_5th10000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_n_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 120, SCREEN_HALFHEIGHT + NORMAL_5TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_5th1000byouga, 0.0f,
		0.1f, 1.0f);

	DrawSprite(g_n_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 160, SCREEN_HALFHEIGHT + NORMAL_5TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_5th100byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 200, SCREEN_HALFHEIGHT + NORMAL_5TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_5th10byouga, 0.0f,
		0.1f, 1.0f);


	DrawSprite(g_n_5thScoreNumberTextureIndex,
		SCREEN_HALFWIDTH + 240, SCREEN_HALFHEIGHT + NORMAL_5TH_POS_Y,
		NORMAL_SCORE_NUMBER_SIZE_X, NORMAL_SCORE_NUMBER_SIZE_Y,
		g_n_5thbyouga, 0.0f,
		0.1f, 1.0f);
}

void NormalResultSetMouse(int index)
{
	mouse = index;
}

void SetNormalScore(int index)
{
	g_NormalScore = index;
	SaveNormalScore(g_NormalScore);
}

void SaveNormalScore(int score)
{
	int i;
	FILE* fp;
	fp = fopen("1stscore.txt", "r");
	fscanf(fp, "%d", &i);

	
	fclose(fp);
	g_n_1stChenge = i;

	NormalScoreJudge(i);

	g_n_1stbyouga = (float)g_n_1stChenge / 10;

	if (g_NormalScore >= 10)
	{
		g_n_1stChenge = g_n_1stbyouga;
		g_n_1st10byouga = (float)g_n_1stChenge / 10;
	}
	if (g_NormalScore >= 100)
	{
		g_n_1stChenge = g_n_1st10byouga;
		g_n_1st100byouga = (float)g_n_1stChenge / 10;
	}
	if (g_NormalScore >= 1000)
	{
		g_n_1stChenge = g_n_1st100byouga;
		g_n_1st1000byouga = (float)g_n_1stChenge / 10;
	}
	if (g_NormalScore >= 10000)
	{
		g_n_1stChenge = g_n_1st1000byouga;
		g_n_1st10000byouga = (float)g_n_1stChenge / 10;
	}
	if (g_NormalScore >= 100000)
	{
		g_n_1stChenge = g_n_1st10000byouga;
		g_n_1st100000byouga = (float)g_n_1stChenge / 10;
	}
	if (g_NormalScore >= 1000000)
	{
		g_n_1stChenge = g_n_1st100000byouga;
		g_n_1st1000000byouga = (float)g_n_1stChenge / 10;
	}
	//fclose(fp);
}

//int PassNormalScore(void)
//{
//
//	return g_NormalScorePass;
//}