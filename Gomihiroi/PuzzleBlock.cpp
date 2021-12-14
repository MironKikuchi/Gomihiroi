#include "DirectX.h"
#include "PuzzleBlock.h"
#include "input.h"
#include "main.h"
#include "sprite.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
static PUZZLE_T g_PuzzleBlock1[PUZZLECOUNT_SIZE];
static int g_TextureIndex;
static int mouse = 0;
static int Frame;
unsigned int nowtime = (unsigned int)time(NULL);

/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitPuzzle(void)
{
	for (int i = 0; i < _countof(g_PuzzleBlock1); i++)
	{
		g_PuzzleBlock1[i].pos.x = SCREEN_HALFWIDTH - 200;
		g_PuzzleBlock1[i].pos.y = 0;
		g_PuzzleBlock1[i].Isdisp = false;


		//フルパスfull pathではなくて
		//相対パスを指定する
		g_TextureIndex = LoadTexture("texture/enemy.png");

		g_PuzzleBlock1[i].Isdisp = true;
	}
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
	Frame += 1;
	if ((Frame % 120) == 0)
	{
		for (int i = 0; i < PUZZLECOUNT_SIZE; i++)
		{
			if (g_PuzzleBlock1[i].Isdisp == false)
			{
				g_PuzzleBlock1[i].Isdisp = true;
				break;
			}
		}
	}
	

	POINT mouse_p;
	//マウスの座標ゲッツ
	GetCursorPos(&mouse_p);
	//マウスの座標をスクリーンからクライアント(ウィンドウ)へ
	ScreenToClient(hWnd, &mouse_p);

	/*char str[256];
	sprintf_s(str, "PosX: %d PosY: %d \n", mouse_p.x, mouse_p.y);
	OutputDebugString(str);*/


	for (int i = 0; i < _countof(g_PuzzleBlock1); i++)
	{

		if (!g_PuzzleBlock1[i].Isdisp)
		{
			continue;
		}

		srand(nowtime);
		int randomposX = rand() % SCREEN_WIDTH + 1 * i;
		int randomposY = rand() % SCREEN_HEIGHT + 1 * i;
		g_PuzzleBlock1[i].pos.x = randomposX;
		g_PuzzleBlock1[i].pos.y = randomposY;
		

		//画像のボタンの当たり判定
		if (mouse_p.x < (g_PuzzleBlock1[i].pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock1[i].pos.x - PUZZLEHALF_SIZE_X) &&
			mouse_p.y < (g_PuzzleBlock1[i].pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock1[i].pos.y - PUZZLEHALF_SIZE_Y))
		{
			if (mouse == 1)
			{
				g_PuzzleBlock1[i].Isdisp = false;
				g_PuzzleBlock1[i].pos.y = 0;
			}
		}
		else
		{
			mouse = 0;
		}
		if (g_PuzzleBlock1[i].pos.x > SCREEN_WIDTH && g_PuzzleBlock1[i].pos.x < -5 &&
			g_PuzzleBlock1[i].pos.y > SCREEN_HEIGHT && g_PuzzleBlock1[i].pos.y < -5)
		{
			g_PuzzleBlock1[i].Isdisp = false;
			g_PuzzleBlock1[i].pos.y = 0;
		}
	}
	g_PuzzleBlock1[i].pos.y += g_PuzzleBlock1[i].speed.y;
}


/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/

void DrawPuzzle(void)
{

	for (int i = 0; i < _countof(g_PuzzleBlock1); i++)
	{
		if (!g_PuzzleBlock1[i].Isdisp)
		{
			continue;
		}

		LPDIRECT3DDEVICE9 pDevice;
		pDevice = GetDevice();


		// 頂点データ
		Vertex2D PuzzleBlock1[] = {
			{//左上
				D3DXVECTOR4((float)g_PuzzleBlock1[i].pos.x - PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1[i].pos.y - PUZZLEHALF_SIZE_Y, 0.0f, 1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,0.0f),
			},
			{//右上
				D3DXVECTOR4((float)g_PuzzleBlock1[i].pos.x + PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1[i].pos.y - PUZZLEHALF_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(1.0f,0.0f),
			},
			{//左下
				D3DXVECTOR4((float)g_PuzzleBlock1[i].pos.x - PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1[i].pos.y + PUZZLEHALF_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,1.0f),
			},
			{//右下
				D3DXVECTOR4((float)g_PuzzleBlock1[i].pos.x + PUZZLEHALF_SIZE_X, (float)g_PuzzleBlock1[i].pos.y + PUZZLEHALF_SIZE_Y,0.0f,1.0f),
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


		if (g_PuzzleBlock1[i].Isdisp == true)
		{
			pDevice->DrawPrimitiveUP(
				D3DPT_TRIANGLESTRIP,
				2,
				PuzzleBlock1,
				sizeof(Vertex2D)
			);
		}

	}
}

bool PuzzleGetMouse(int index)
{
	mouse = index;
	return 0;
}