#include "DirectX.h"
#include "PuzzleBlock.h"
#include "input.h"
#include "main.h"
#include "sprite.h"
//#include "collision.h"
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
	//COLBOX	colBox;



};


/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static PUZZLE_T g_PuzzleBlock1;
static PUZZLE_T g_PuzzleBlock2;
static PUZZLE_T g_PuzzleBlock3;
static PUZZLE_T g_PuzzleBlock4;
static PUZZLE_T g_PuzzleBlock5;

static int g_TextureIndex;
static int g_DustTextureIndex;
static int g_BananaTextureIndex;
static int g_GomiTextureIndex;
static int g_ReizoukoTextureIndex;
static int mouse = 0;

/*------------------------------------------------------------------------------
初期化関数
------------------------------------------------------------------------------*/
void InitPuzzle(void)
{
	g_PuzzleBlock1.pos.x = SCREEN_HALFWIDTH - 200;
	g_PuzzleBlock1.pos.y = 0;
	g_PuzzleBlock1.Isdisp = false;

	g_PuzzleBlock2.pos.x = SCREEN_HALFWIDTH - 100;
	g_PuzzleBlock2.pos.y = 0;
	g_PuzzleBlock2.Isdisp = false;

	g_PuzzleBlock3.pos.x = SCREEN_HALFWIDTH;
	g_PuzzleBlock3.pos.y = 0;
	g_PuzzleBlock3.Isdisp = false;

	g_PuzzleBlock4.pos.x = SCREEN_HALFWIDTH + 100;
	g_PuzzleBlock4.pos.y = 0;
	g_PuzzleBlock4.Isdisp = false;

	g_PuzzleBlock5.pos.x = SCREEN_HALFWIDTH; +200;
	g_PuzzleBlock5.pos.y = 0;
	g_PuzzleBlock5.Isdisp = false;


	//フルパスfull pathではなくて
	//相対パスを指定する
	g_TextureIndex = LoadTexture("texture/enemy.png");
	g_DustTextureIndex = LoadTexture("texture/Hokori.jpg");
	g_BananaTextureIndex = LoadTexture("texture/banana_peel.png");
	g_GomiTextureIndex = LoadTexture("texture/Gomi.png");
	g_ReizoukoTextureIndex = LoadTexture("texture/REIZOUKO.png");

	/*g_PuzzleBlock1.colBox.width =  PUZZLE_SIZE_X;
	g_PuzzleBlock1.colBox.height =  PUZZLE_SIZE_Y;*/

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
	g_PuzzleBlock2.pos.y += g_PuzzleBlock2.speed.y;
	g_PuzzleBlock3.pos.y += g_PuzzleBlock3.speed.y;
	g_PuzzleBlock4.pos.y += g_PuzzleBlock4.speed.y;
	g_PuzzleBlock5.pos.y += g_PuzzleBlock5.speed.y;

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

	//画像のボタンの当たり判定
	if (mouse_p.x < (g_PuzzleBlock2.pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock2.pos.x - PUZZLEHALF_SIZE_X) &&
		mouse_p.y < (g_PuzzleBlock2.pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock2.pos.y - PUZZLEHALF_SIZE_Y))
	{
		if (mouse == 1)
		{
			g_PuzzleBlock1.Isdisp = false;
		}
	}

	//画像のボタンの当たり判定
	if (mouse_p.x < (g_PuzzleBlock3.pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock3.pos.x - PUZZLEHALF_SIZE_X) &&
		mouse_p.y < (g_PuzzleBlock3.pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock3.pos.y - PUZZLEHALF_SIZE_Y))
	{
		if (mouse == 1)
		{
			g_PuzzleBlock1.Isdisp = false;
		}
	}

	//画像のボタンの当たり判定
	if (mouse_p.x < (g_PuzzleBlock4.pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock4.pos.x - PUZZLEHALF_SIZE_X) &&
		mouse_p.y < (g_PuzzleBlock4.pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock4.pos.y - PUZZLEHALF_SIZE_Y))
	{
		if (mouse == 1)
		{
			g_PuzzleBlock1.Isdisp = false;
		}
	}

	//画像のボタンの当たり判定
	if (mouse_p.x < (g_PuzzleBlock5.pos.x + PUZZLEHALF_SIZE_X) && mouse_p.x >= (g_PuzzleBlock5.pos.x - PUZZLEHALF_SIZE_X) &&
		mouse_p.y < (g_PuzzleBlock5.pos.y + PUZZLEHALF_SIZE_Y) && mouse_p.y >= (g_PuzzleBlock5.pos.y - PUZZLEHALF_SIZE_Y))
	{
		if (mouse == 1)
		{
			g_PuzzleBlock1.Isdisp = false;
		}
	}


	/*g_PuzzleBlock1.colBox.posx = g_PuzzleBlock1.pos.x;
	g_PuzzleBlock1.colBox.posy = g_PuzzleBlock1.pos.y;*/

	/*if (g_PuzzleBlock1.dispSwitch == 0)
	{
		OutputDebugString("0が入ってるよ");
		g_PuzzleBlock1.colBox.posx = -64;
		g_PuzzleBlock1.colBox.posy = -64;
		g_PuzzleBlock1.colBox.width = 0;
		g_PuzzleBlock1.colBox.height = 0;
	}*/

}

/*------------------------------------------------------------------------------
描画処理をする関数
------------------------------------------------------------------------------*/

void DrawPuzzle(void)
{
	/*if (g_Enemy.dispSwitch == 1)
	{
		pDevice->DrawPrimitiveUP(
			D3DPT_TRIANGLESTRIP,
			2,
			v,
			sizeof(Vertex2D)
		);
	}
	DrawSprite(g_DustTextureIndex,
		SCREEN_HALFWIDTH,SCREEN_HALFHEIGHT,
		PUZZLE_SIZE_X, PUZZLE_SIZE_Y,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_BananaTextureIndex,
		SCREEN_HALFWIDTH - 150,SCREEN_HALFHEIGHT,
		PUZZLE_SIZE_X, PUZZLE_SIZE_Y,
		0.0f, 0.0f,
		1.0f, 1.0f);

	DrawSprite(g_TextureIndex,
		SCREEN_HALFWIDTH + 150, SCREEN_HALFHEIGHT,
		PUZZLE_SIZE_X, PUZZLE_SIZE_Y,
		0.0f, 0.0f,
		1.0f, 1.0f);*/

	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	// 頂点データ
	Vertex2D v[] = {
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

	Vertex2D v[] = {
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

	if (g_PuzzleBlock1.Isdisp == 1)
	{
		pDevice->DrawPrimitiveUP(
			D3DPT_TRIANGLESTRIP,
			2,
			v,
			sizeof(Vertex2D)
		);
	}
}

/*------------------------------------------------------------------------------
敵のバウンディングボックスを渡す
------------------------------------------------------------------------------*/
/*COLBOX GetColBoxPuzzle(void)
{
	return (g_PuzzleBlock1.colBox);
}*/

//D3DXVECTOR2 PuzzlePosition(void)
//{
//	return (g_PuzzleBlock1.pos);
//}

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