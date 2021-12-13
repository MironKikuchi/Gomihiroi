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
�������֐�
------------------------------------------------------------------------------*/
void InitGame(void)
{
	g_BgTextureIndex = LoadTexture("texture/car_road.png");
	InitPuzzle();
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

}

/*------------------------------------------------------------------------------
�X�V����������֐�
------------------------------------------------------------------------------*/
void UpdateGame(HWND hWnd)
{
	UpdatePuzzle(hWnd);


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
}

