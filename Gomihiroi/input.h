#pragma once

#include <Windows.h>
// dinput.hをインクルードする前にこれを入れないと警告が出るので注意
#define DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>


/*------------------------------------------------------------------------------
関数のプロトタイプ宣言
------------------------------------------------------------------------------*/

// キーボード入力モジュールの初期化
//
// 戻り値：初期化出来なかった場合false
//
// 引数：hinstance ... インスタンスハンドル（WinMainの引数などで取得）
//       hWnd      ... ウィンドウハンドル
//
bool Keyboard_Initialize(HINSTANCE hInstance, HWND hWnd);

// キーボードモジュールの終了処理
void Keyboard_Finalize(void);

// キーボードモジュールの更新
// ※キーボード全体のキー状態の取得
//
void Keyboard_Update(void);

// キーボードのキー状態の取得
//
// Keyboard_Update()で取得したキーの状態を確認する関数群
//
// 戻り値：指定のキーが
//     Press   ... 押されている
//     Trigger ... 押した瞬間
//     Release ... 離した瞬間
// であった場合trueを返す
//
// 引数：nKey ... キー指定（DIK_〜というキー列挙）
//
bool Keyboard_IsPress(int nKey);
bool Keyboard_IsTrigger(int nKey);
bool Keyboard_IsRelease(int nKey);

bool GetMouse(int index);
//int PassMouse();