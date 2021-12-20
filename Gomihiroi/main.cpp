#include <Windows.h>
#include <stdio.h>
#include "main.h"
#include "title.h"
#include "DirectX.h"
#include "input.h"
#include "scene.h"
#include "texture.h"
#include "game.h"
#include "PuzzleBlock.h"
#include "PuzzleBlock2.h"
#include "PuzzleBlock3.h"
#include "PuzzleBlock4.h"
#include "PuzzleBlock5.h"
#include "timelimit.h"
#include "highscoreresult.h"
#include "normalresult.h"
//#include "sound.h"
//#include "fade.h"
//#include "goalscene.h"


#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")


/*------------------------------------------------------------------------------
定数定義
------------------------------------------------------------------------------*/
#define CLASS_NAME     "GameWindow"
#define WINDOW_CAPTION "Gomihiroi"


/*------------------------------------------------------------------------------
プロトタイプ宣言
------------------------------------------------------------------------------*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void Update(HWND hWnd);
void Draw(void);

/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static int g_MouseCursorPos_x;
static int g_MouseCursorPos_y;


/*------------------------------------------------------------------------------
メイン関数
------------------------------------------------------------------------------*/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//ウィンドウクラスの登録
	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = CLASS_NAME;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	RegisterClass(&wc);

	//ウィンドウスタイルの作成
	DWORD window_style = WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
	//ウィンドウサイズの矩形を作成
	RECT window_rect = { 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };
	//ウィンドウスタイルに合わせて矩形を調整する
	AdjustWindowRect(&window_rect, window_style, FALSE);

	//調整された矩形からウィンドウサイズを再作成する
	int window_width = window_rect.right - window_rect.left;
	int window_height = window_rect.bottom - window_rect.top;

	//デスクトップの解像度を取得
	int desktop_width = GetSystemMetrics(SM_CXSCREEN);
	int desktop_height = GetSystemMetrics(SM_CYSCREEN);

	//ウィンドウの位置（左上）をデスクトップのどこに移動させれば
	//中央に表示されるかを計算する
	//（※デスクトップの外に出ていきそうであれば左上の隅にセットする）
	int window_x = max((desktop_width - window_width) / 2, 0);
	int window_y = max((desktop_height - window_height) / 2, 0);

	//ウィンドウの作成
	HWND hWnd = CreateWindow(
		CLASS_NAME,			//Windowsに登録する名前
		WINDOW_CAPTION,		//タイトルに表示する文字列
		window_style,		//ウィンドウのスタイル
		window_x,			//X位置中心点
		window_y,			//Y位置中心点
		window_width,		//横幅 width
		window_height,		//高さ height
		NULL,				//親ウィンドウの指定（HWND）
		NULL,				//メニューのハンドル
		hInstance,			//インスタンスのハンドル
		NULL				//追加の拡張領域（特に使わないのでNULLを指定）
	);
	//ウィンドウが作成できたかチェックする
	if (hWnd == NULL) {
		return 0;
	}

	//作成したウィンドウを画面に表示する
	ShowWindow(hWnd, nCmdShow);
	//ウィンドウ内の更新
	UpdateWindow(hWnd);

	////初期化
	Initialize(hWnd);
	Keyboard_Initialize(hInstance, hWnd);

	//InitSound(hWnd);

	//InitFade();


	//シーンの初期化（タイトルからスタート
	//SceneFadeIn(SCENE_GAME1_1);
	InitScene(SCENE_GAME);

	//デバッグ文字列の初期化
	//InitDebugProc();

	//ゲームの初期化
	//InitGame();

	//メッセージループ
	MSG msg = {};
	while (WM_QUIT != msg.message)
	{
		//Windowsからメッセージが来た場合はメッセージを処理する
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			//ゲームの処理をここに書いていく
			Update(hWnd);
			Draw();
			DrawScene();
		}
	}

	//シーンの終了処理
	UninitScene();

	
	Keyboard_Finalize();
	UninitTexture();
	//UninitSound();

	return (int)msg.wParam;
}

/*------------------------------------------------------------------------------
プロシージャ
------------------------------------------------------------------------------*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN://キーが押されたメッセージ
		if (wParam == VK_ESCAPE)
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0);//WM_CLOSEメッセージを自分に送る
		}
		break;


	case WM_LBUTTONDOWN:
		//マウス左ボタン押下
	/*	g_MouseCursorPos_x = LOWORD(lParam);
		g_MouseCursorPos_y = HIWORD(lParam);*/
		//return MousePointerPos();

	case WM_LBUTTONUP:
		//マウス左ボタン離した
		return 0;


	case WM_CLOSE:// ウィンドウを閉じるメッセージ
		if (MessageBox(hWnd, "終了してよろしいですか？", "確認",
			MB_OKCANCEL | MB_DEFBUTTON2) == IDOK)
		{
			DestroyWindow(hWnd); //指定のウィンドウにWM_DESTROYを送る
		}
		return 0;

	case WM_DESTROY: //ウィンドウ破棄メッセージ
		PostQuitMessage(0); // WM_QUITメッセージを送る
		return 0;
	}

	//その他のメッセージはWindowsに任せる
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
int onClick = 0;
int OldClick = 0;
int RespondToMouse = 0;
/*------------------------------------------------------------------------------
ゲームの更新
------------------------------------------------------------------------------*/
void Update(HWND hWnd)
{
	
	Keyboard_Update();
	
	//左クリックされたか？
	//int onClick = (GetKeyState(VK_LBUTTON) & 0x80) ? 1 : 0;
	if ((onClick = GetKeyState(VK_LBUTTON) & 0x80) && RespondToMouse == 0)
	{
		onClick = 1;
		TitleSetMouse(onClick);
		DustSetMouse(onClick);
		BananaSetMouse(onClick);
		BookSetMouse(onClick);
		TrashSetMouse(onClick);
		FridgeSetMouse(onClick);
		HighResultSetMouse(onClick);
		NormalResultSetMouse(onClick);
		PrevMouse(onClick);
	}
	else if(onClick = GetKeyState(VK_LBUTTON) & 0x80)
	{
		onClick = 0;
		TitleSetMouse(onClick);
		DustSetMouse(onClick);
		BananaSetMouse(onClick);
		BookSetMouse(onClick);
		TrashSetMouse(onClick);
		FridgeSetMouse(onClick);
		HighResultSetMouse(onClick);
		NormalResultSetMouse(onClick);
	}
	else
	{
		PrevMouse(0);
	}

	UpdateScene(hWnd);
}

/*------------------------------------------------------------------------------
ゲームの描画
------------------------------------------------------------------------------*/
void Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	// 画面のクリア
	pDevice->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_RGBA(100, 80, 200, 255),
		1.0f,
		0);

	// 描画の開始
	pDevice->BeginScene();

	// ゲームの描画処理



	DrawScene();

	// 描画の終了
	pDevice->EndScene();

	// バックバッファをフリップ
	pDevice->Present(
		NULL,
		NULL,
		NULL,
		NULL
	);
}

void PrevMouse(int index)
{
	RespondToMouse = index;
}

/*------------------------------------------------------------------------------
Debug print
------------------------------------------------------------------------------*/
void DebugPrint(int i) {
	char str[256];
	sprintf_s(str, ": %d \n", i);
	OutputDebugString(str);
}
void DebugPrint(float f) {
	char str[256];
	sprintf_s(str, ": %f \n", f);
	OutputDebugString(str);
}
void DebugPrint(bool b) {
	char str[256];
	sprintf_s(str, ": %d \n", b);
	OutputDebugString(str);
}
void DebugPrint(char s[]) {
	OutputDebugString(s);
}