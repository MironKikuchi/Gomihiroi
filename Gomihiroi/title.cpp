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
�\���̐錾
------------------------------------------------------------------------------*/
typedef struct
{
	D3DXVECTOR3 Pos;

}TITLE_T;


/*------------------------------------------------------------------------------
�O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static TITLE_T g_TitleButton;

static int g_BgTextureIndex;
static int g_TitleTextureIndex;
static int g_StartTextureIndex;
static int g_ExitTextureIndex;
static int g_BGMIndex = 0;
static int mouse;


/*------------------------------------------------------------------------------
�������֐�
------------------------------------------------------------------------------*/
void InitTitle(void)
{
	g_TitleButton.Pos.x = (TITLEBG_HALF_SIZE_X);
	g_TitleButton.Pos.y = (TITLEBG_HALF_SIZE_Y) + 150;

	g_BgTextureIndex = LoadTexture("texture/Title.png");
	g_TitleTextureIndex = LoadTexture("texture/TitleFont.png");
	g_StartTextureIndex = LoadTexture("texture/PLAY_BUTTON.png");
	g_ExitTextureIndex = LoadTexture("texture/EXIT_BUTTON.png");

	/*g_BGMIndex = LoadSound("sound/bgm01.WAV");

	PlaySound(g_BGMIndex, -1);*/
}

/*------------------------------------------------------------------------------
�I������������֐�
------------------------------------------------------------------------------*/
void UninitTitle(void)
{

}

/*------------------------------------------------------------------------------
�X�V����������֐�
------------------------------------------------------------------------------*/
void UpdateTitle(HWND hWnd)
{
	POINT mouse_p;
	//�}�E�X�̍��W�Q�b�c
	GetCursorPos(&mouse_p);
	//�}�E�X�̍��W���X�N���[������N���C�A���g(�E�B���h�E)��
	ScreenToClient(hWnd, &mouse_p);

	char str[256];
	sprintf_s(str, "PosX: %d PosY: %d \n", mouse_p.x, mouse_p.y);
	OutputDebugString(str);

	//�^�C�g���̃{�^���̓����蔻��
	if (mouse_p.x < (SCREEN_HALFWIDTH + TITLEBUTTON_HALF_SIZE_X) && mouse_p.x >= (SCREEN_HALFWIDTH - TITLEBUTTON_HALF_SIZE_X) &&
		mouse_p.y < (SCREEN_HALFHEIGHT + TITLEBUTTON_HALF_SIZE_Y) + 300 && mouse_p.y >= (SCREEN_HALFHEIGHT - TITLEBUTTON_HALF_SIZE_Y) + 300)
	{
		if (mouse == 1)
		{
			SetScene(SCENE_GAME);
			CheckScene();
		}
	}

}

/*------------------------------------------------------------------------------
�`�揈��������֐�
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
		(SCREEN_HALFWIDTH), (SCREEN_HALFHEIGHT) + 300,
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