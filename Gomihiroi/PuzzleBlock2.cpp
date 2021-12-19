#include "DirectX.h"
#include "PuzzleBlock2.h"
#include "input.h"
#include "main.h"
#include "sprite.h"
#include "score.h"
#include "level.h"
#include "timelimit.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*------------------------------------------------------------------------------
構造体宣言
------------------------------------------------------------------------------*/
typedef struct BANANA_T
{
	int		Isdisp = false;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 speed = { 0, 1 };
	D3DXVECTOR2 initspeed = { 0, -5.5 };

};


/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static BANANA_T g_Banana[BANANACOUNT_SIZE];
static int g_TextureIndex;
static int mouse = 0;
static int Frame;
unsigned int BananaNowTime = (unsigned int)time(NULL);

/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitBanana(void)
{
	srand(BananaNowTime);//初期化

	//フルパスfull pathではなくて
	//相対パスを指定する
	g_TextureIndex = LoadTexture("texture/Banana.png");

	for (int i = 0; i < _countof(g_Banana); i++)
	{
		SetRandomBananaPos(i);
		g_Banana[i].Isdisp = false;
	}
}

/*------------------------------------------------------------------------------
ブロックのX軸をランダムでセッツ
------------------------------------------------------------------------------*/
void SetRandomBananaPos(int index)
{
	int randomposX = rand() % SCREEN_WIDTH;
	g_Banana[index].pos.x = randomposX;
	g_Banana[index].pos.y = SCREEN_TOP;
}

/*------------------------------------------------------------------------------
終了処理をする関数
------------------------------------------------------------------------------*/
void UninitBanana()
{
	srand(BananaNowTime);
	for (int i = 0; i < _countof(g_Banana); i++)
	{
		SetRandomBananaPos(i);
		g_Banana[i].Isdisp = false;
	}
}

/*------------------------------------------------------------------------------
更新処理をする関数
------------------------------------------------------------------------------*/
void UpdateBanana(HWND hWnd)
{
	Frame += 1;
	if ((Frame % 180) == 0)
	{
		for (int i = 0; i < BANANACOUNT_SIZE; i++)
		{
			if (g_Banana[i].Isdisp == false)
			{
				SetRandomBananaPos(i);
				g_Banana[i].Isdisp = true;
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


	for (int i = 0; i < _countof(g_Banana); i++)
	{

		if (!g_Banana[i].Isdisp)
		{
			continue;
		}

		g_Banana[i].pos.y += g_Banana[i].speed.y;

		//画像がクリックされたら
		if (mouse == 1 && GetLevel() >= LEVEL_BANANA)
		{
			if (mouse_p.x < (g_Banana[i].pos.x + BANANA_SIZE_X) && mouse_p.x >= (g_Banana[i].pos.x - BANANA_SIZE_X) &&
				mouse_p.y < (g_Banana[i].pos.y + BANANA_SIZE_Y) && mouse_p.y >= (g_Banana[i].pos.y - BANANA_SIZE_Y))
			{
				g_Banana[i].Isdisp = false;
				g_Banana[i].pos.y = 0;
				UpdateScore(10);
			}
		}
		else if (mouse == 1 && GetLevel() < LEVEL_BANANA)
		{
			if (mouse_p.x < (g_Banana[i].pos.x + BANANA_SIZE_X) && mouse_p.x >= (g_Banana[i].pos.x - BANANA_SIZE_X) &&
				mouse_p.y < (g_Banana[i].pos.y + BANANA_SIZE_Y) && mouse_p.y >= (g_Banana[i].pos.y - BANANA_SIZE_Y))
			{
				UpdateTime(1);
			}
		}

		//画像が下に行ったら初期値にする
		if (g_Banana[i].pos.y > SCREEN_HEIGHT - 220)
		{
			g_Banana[i].Isdisp = false;
			g_Banana[i].pos.y = SCREEN_TOP;
		}
	}

}


/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/

void DrawBanana(void)
{

	for (int i = 0; i < _countof(g_Banana); i++)
	{
		if (!g_Banana[i].Isdisp)
		{
			continue;
		}

		LPDIRECT3DDEVICE9 pDevice;
		pDevice = GetDevice();


		// 頂点データ
		Vertex2D PuzzleBlock2[] = {
			{//左上
				D3DXVECTOR4((float)g_Banana[i].pos.x - BANANA_SIZE_X, (float)g_Banana[i].pos.y - BANANA_SIZE_Y, 0.0f, 1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,0.0f),
			},
			{//右上
				D3DXVECTOR4((float)g_Banana[i].pos.x + BANANA_SIZE_X, (float)g_Banana[i].pos.y - BANANA_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(1.0f,0.0f),
			},
			{//左下
				D3DXVECTOR4((float)g_Banana[i].pos.x - BANANA_SIZE_X, (float)g_Banana[i].pos.y + BANANA_SIZE_Y,0.0f,1.0f),
				D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
				D3DXVECTOR2(0.0f,1.0f),
			},
			{//右下
				D3DXVECTOR4((float)g_Banana[i].pos.x + BANANA_SIZE_X, (float)g_Banana[i].pos.y + BANANA_SIZE_Y,0.0f,1.0f),
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


		if (g_Banana[i].Isdisp == true)
		{
			pDevice->DrawPrimitiveUP(
				D3DPT_TRIANGLESTRIP,
				2,
				PuzzleBlock2,
				sizeof(Vertex2D)
			);
		}

	}
}

void BananaSetMouse(int index)
{
	mouse = index;
}