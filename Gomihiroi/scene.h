#pragma once

#include <Windows.h>

// �o�^�V�[���ꗗ
enum SCENE
{
	SCENE_NONE,		//�V�[�������Ȃ�
	SCENE_TITLE,	//�^�C�g��
	SCENE_GAME,		//�Q�[��
	SCENE_RESULT,	//���U���g
	

	SCENE_MAX		//�Ōゾ�Ƃ킩��z�������
};

void InitScene(SCENE index);
void UninitScene(void);
void UpdateScene(HWND hWnd);
void DrawScene(void);

void SetScene(SCENE index);
void CheckScene(void);
void ReviveScene(void);
