#include "scene.h"
#include "title.h"
#include "game.h"



/*------------------------------------------------------------------------------
�O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static SCENE g_SceneIndex = SCENE_GAME;
static SCENE g_ScenePrevIndex = g_SceneIndex;
static SCENE g_SceneNextIndex = g_SceneIndex;


/*------------------------------------------------------------------------------
�������֐�
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
�I������������֐�
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
�X�V����������֐�
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
�`�揈��������֐�
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
�V�[���J�ڂ�v������֐�
------------------------------------------------------------------------------*/
void SetScene(SCENE index)
{
	//�J�ڐ�V�[����ݒ肷��
	g_SceneNextIndex = index;
}

/*------------------------------------------------------------------------------
�J�ڂ�v��������ꍇ�ɃV�[����؂�ւ���֐�
------------------------------------------------------------------------------*/
void CheckScene(void)
{
	//���݂̃V�[���ƑJ�ڐ�V�[��������Ă�����
	if (g_SceneIndex != g_SceneNextIndex)
	{
		//���݂̃V�[�����I��������
		UninitScene();

		//�J�ڐ�V�[���̏������������s��
		InitScene(g_SceneNextIndex);
		DrawScene();
	}
}

/*------------------------------------------------------------------------------
GAMEOVER���Ɍ��݂̃V�[����ǂݍ��ފ֐�
------------------------------------------------------------------------------*/
void ReviveScene(void)
{
	UninitScene();
	InitScene(g_ScenePrevIndex);
	DrawScene();
}