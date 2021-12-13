#include "DirectX.h"
#include "PuzzleBlock.h"
#include "input.h"
#include "main.h"
#include "sprite.h"
#include <stdio.h>


/*------------------------------------------------------------------------------
構造体宣言
------------------------------------------------------------------------------*/
typedef struct PUZZLE_T
{
	int		Isdisp = false;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 speed = { 0, 1 };
	D3DXVECTOR2 initspeed = { 0, -5.5 };

};


/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static PUZZLE_T g_PuzzleBlock1;
static int g_TextureIndex;
static int mouse = 0;

/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitPuzzle(void)
{
	g_PuzzleBlock1.pos.x = SCREEN_HALFWIDTH - 200;
	g_PuzzleBlock1.pos.y = 0;
	g_PuzzleBlock1.Isdisp = false;


	//フルパスfull pathではなくて
	//相対パスを指定する
	g_TextureIndex = LoadTexture("texture/enemy.png");

	g_PuzzleBlock1.Isdisp = true;
}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitPuzzle()
{

}

/*------------------------------------------------------------------------------
更新処理をする関数
------------------------------------------------------------------------------*/
void UpdatePuzzle(HWND hWnd)
{
	g_PuzzleBlock1.pos.y += g_PuzzleBlock1.speed.y;

	POINT mouse_p;
	//マウスの座標ゲッツ
	GetCursorPos(&mouse_p);
	//マウスの座標をスクリーンからクライアント(ウィンドウ)へ
	ScreenToClient(hWnd, &mouse_p);

	char str[256];
	sprintf_s(str, "PosX: %d PosY: %d \n", mouse_p.x, mouse_p.y);
	OutputDebugString(str);

	//画像のボタンの当たり判定
	if (mouse_p.x < (g_PuzzleBlock1.pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock1.pos.x - PUZZLEHALF_SIZE_X) &&
		mouse_p.y < (g_PuzzleBlock1.pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock1.pos.y - PUZZLEHALF_SIZE_Y) )
	{
		if (mouse == 1)
		{
			g_PuzzleBlock1.Isdisp = false;
		}
	}
	else
	{
		mouse = 0;
	}

}

/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/

void DrawPuzzle(void)
{


	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();
	

	// 頂点データ
	Vertex2D PuzzleBlock1[] = {
		{//左上
			D3DXVECTOR4((float)g_PuzzleBlock1.pos.x - PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1.pos.y - PUZZLEHALF_SIZE_Y, 0.0f, 1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,0.0f),
		},
		{//右上
			D3DXVECTOR4((float)g_PuzzleBlock1.pos.x + PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1.pos.y - PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,0.0f),
		},
		{//左下
			D3DXVECTOR4((float)g_PuzzleBlock1.pos.x - PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1.pos.y + PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,1.0f),
		},
		{//右下
			D3DXVECTOR4((float)g_PuzzleBlock1.pos.x + PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1.pos.y + PUZZLEHALF_SIZE_Y,0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,1.0f),
		}
	};

	//ポリゴンとテクスチャを対応させる
	LPDIRECT3DTEXTURE9 pTexture;
	//欲しいテクスチャの整理番号を伝える
	pTexture = GetTexture(g_TextureIndex);
	pDevice->SetTexture(0, pTexture);
	pDevice->SetFVF(FVF_VERTEX2D);


	if (g_PuzzleBlock1.Isdisp == true)
	{
		pDevice->DrawPrimitiveUP(
			D3DPT_TRIANGLESTRIP,
			2,
			PuzzleBlock1,
			sizeof(Vertex2D)
		);
	}

	
}

/*------------------------------------------------------------------------------
敵の有効フラグを渡す
------------------------------------------------------------------------------*/
bool IsActivePuzzle(void)
{
	return g_PuzzleBlock1.Isdisp;
}

/*------------------------------------------------------------------------------
敵の有効フラグを設定する
------------------------------------------------------------------------------*/
void SetActivePuzzle(int flag)
{
	g_PuzzleBlock1.Isdisp = flag;
}

bool PuzzleGetMouse(int index)
{
	mouse = index;
	return 0;
}