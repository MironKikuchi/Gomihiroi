#pragma once

#include <Windows.h>

// 登録シーン一覧
enum SCENE
{
	SCENE_NONE,		//シーン処理なし
	SCENE_TITLE,	//タイトル
	SCENE_GAME,		//ゲーム
	SCENE_RESULT,	//リザルト
	

	SCENE_MAX		//最後だとわかる奴をいれる
};

void InitScene(SCENE index);
void UninitScene(void);
void UpdateScene(HWND hWnd);
void DrawScene(void);

void SetScene(SCENE index);
void CheckScene(void);
void ReviveScene(void);
