#include "DirectX.h"
#include "PuzzleBlock.h"
#include "input.h"
#include "main.h"
#include "sprite.h"
#include "score.h"
#include "timelimit.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*------------------------------------------------------------------------------
構造体宣言
------------------------------------------------------------------------------*/
typedef struct DUST_T
{
	int		Isdisp = false;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 speed = { 0, 1 };
	D3DXVECTOR2 initspeed = { 0, -5.5 };

};


/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static DUST_T g_DustBlock[DUSTCOUNT_SIZE];
static int g_TextureIndex;
static int mouse = 0;
static int Frame;
unsigned int DustNowTime = (unsigned int)time(NULL);

/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitDust(void)
{
	srand(DustNowTime);//初期化
	
	
	//フルパスfull pathではなくて
	//相対パスを指定する
	g_TextureIndex = LoadTexture("texture/Hokori.png");

	for (int i = 0; i < _countof(g_DustBlock); i++)
	{	
		SetRandomDustPos(i);
		g_DustBlock[i].Isdisp = false;
	}
}

/*------------------------------------------------------------------------------
ブロックのX軸をランダムでセッツ
------------------------------------------------------------------------------*/
void SetRandomDustPos(int index)
{
	int randomposX = rand() % SCREEN_WIDTH;
	g_DustBlock[index].pos.x = randomposX;
	g_DustBlock[index].pos.y = SCREEN_TOP;
}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitDust()
{
	srand(DustNowTime);
	for (int i = 0; i < _countof(g_DustBlock); i++)
	{
		SetRandomDustPos(i);
		g_DustBlock[i].Isdisp = false;
	}
}

/*------------------------------------------------------------------------------
更新処理をする関数
------------------------------------------------------------------------------*/
void UpdateDust(HWND hWnd)
{
	Frame += 1;
	if ((Frame % 30) == 0)
	{
		for (int i = 0; i < DUSTCOUNT_SIZE; i++)
		{
			if (g_DustBlock[i].Isdisp == false)
			{
				SetRandomDustPos(i);
				g_DustBlock[i].Isdisp = true;
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


	for (int i = 0; i < _countof(g_DustBlock); i++)
	{

		if (!g_DustBlock[i].Isdisp)
		{
			continue;
		}

		g_DustBlock[i].pos.y += g_DustBlock[i].speed.y;

		if (mouse == 1)
		{
			if (mouse_p.x < (g_DustBlock[i].pos.x + DUST_SIZE_X) && mouse_p.x >= (g_DustBlock[i].pos.x - DUST_SIZE_X) &&
				mouse_p.y < (g_DustBlock[i].pos.y + DUST_SIZE_Y) && mouse_p.y >= (g_DustBlock[i].pos.y - DUST_SIZE_Y))
			{
				g_DustBlock[i].Isdisp = false;
				g_DustBlock[i].pos.y = 0;
				UpdateScore(5);
			}
		}
		else
		{
			UpdateTime(0);
		}

		//画像のボタンの当たり判定
		// if (mouse_p.x < (g_DustBlock[i].pos.x +  DUST_SIZE_X) && mouse_p.x >= (g_DustBlock[i].pos.x -  DUST_SIZE_X) &&
		// 	mouse_p.y < (g_DustBlock[i].pos.y +  DUST_SIZE_Y) && mouse_p.y >= (g_DustBlock[i].pos.y -  DUST_SIZE_Y))
		// {
		// 	if (mouse == 1)
		// 	{
		// 		g_DustBlock[i].Isdisp = false;
		// 		g_DustBlock[i].pos.y = 0;
		// 	}
		// }
		// else
		// {
		// 	mouse = 0;
		// }

		//画像が下に行ったら初期値にする
		if (g_DustBlock[i].pos.y > SCREEN_HEIGHT + 20)
		{
			g_DustBlock[i].Isdisp = false;
			g_DustBlock[i].pos.y = SCREEN_TOP + 220;
		}
	}
	
	//画像のボタンの当たり判定
	/*if (mouse_p.x < (g_DustBlock[j].pos.x +  DUST_SIZE_X) && mouse_p.x >= (g_DustBlock[j].pos.x -  DUST_SIZE_X) &&
		mouse_p.y < (g_DustBlock[j].pos.y +  DUST_SIZE_Y) && mouse_p.y >= (g_DustBlock[j].pos.y -  DUST_SIZE_Y))
	{
		if (mouse == 1)
		{
			g_DustBlock[j].Isdisp = false;
			g_DustBlock[j].pos.y = 0;
		}
	}
	else
	{
		mouse = 0;
	}*/
}


/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/

void DrawDust(void)
{

	for (int i = 0; i < _countof(g_DustBlock); i++)
	{
		if (!g_DustBlock[i].Isdisp)
		{
			continue;
		}

		LPDIRECT3DDEVICE9 pDevice;
		pDevice = GetDevice();


		// 頂点データ
		Vertex2D PuzzleBlock1[] = {
			{//左上
				D3DXVECTOR4((float)g_DustBlock[i].pos.x -  DUST_SIZE_X, (float)g_DustBlock[i].pos.y -  DUST_SIZE_Y, 0.0f, 1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,0.0f),
			},
			{//右上
				D3DXVECTOR4((float)g_DustBlock[i].pos.x +  DUST_SIZE_X, (float)g_DustBlock[i].pos.y -  DUST_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(1.0f,0.0f),
			},
			{//左下
				D3DXVECTOR4((float)g_DustBlock[i].pos.x -  DUST_SIZE_X, (float)g_DustBlock[i].pos.y +  DUST_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,1.0f),
			},
			{//右下
				D3DXVECTOR4((float)g_DustBlock[i].pos.x +  DUST_SIZE_X, (float)g_DustBlock[i].pos.y +  DUST_SIZE_Y,0.0f,1.0f),
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


		if (g_DustBlock[i].Isdisp == true)
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

void DustSetMouse(int index)
{
	mouse = index;
}