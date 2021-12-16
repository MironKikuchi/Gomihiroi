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
�������֐�
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

	// �N���A�J���[�𐅐F�ɕύX
	SetClearColor(100, 100, 200);
}

/*------------------------------------------------------------------------------
�I������������֐�
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
�X�V����������֐�
------------------------------------------------------------------------------*/
void UpdateGame(HWND hWnd)
{
	UpdatePuzzle(hWnd);
	UpdatePuzzle2(hWnd);
	UpdatePuzzle3(hWnd);
	UpdatePuzzle4(hWnd);
	UpdatePuzzle5(hWnd);
	//�S�Ă̈ړ��������I����Ă��瓖���蔻����s��
	//UpdateCollision();


}

/*------------------------------------------------------------------------------
�`�揈��������֐�
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

