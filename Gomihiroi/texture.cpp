#include "DirectX.h"

/*------------------------------------------------------------------------------
定数定義
------------------------------------------------------------------------------*/
#define MAX_TEXTURE_NUM 127


/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static LPDIRECT3DTEXTURE9	g_pTexture[MAX_TEXTURE_NUM] = { 0 };	//テクスチャ配列
static unsigned int g_TextureIndex = 0;

/*------------------------------------------------------------------------------
プレイヤーテクスチャの読み込み
------------------------------------------------------------------------------*/
int LoadTexture(char* fileName)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//読み込み最大数を超えていたら負の値を返す
	if (g_TextureIndex == MAX_TEXTURE_NUM)
	{
		return -1;
	}

	//ファイルからテクスチャを読み込む
	if (S_OK != D3DXCreateTextureFromFile(
		pDevice,
		fileName,
		&g_pTexture[g_TextureIndex])
		)
	{
		//読み込みに失敗した場合、負の値を返す
		return -1;
	}

	int retIndex = g_TextureIndex;

	//インデックスを一つ進める
	g_TextureIndex++;

	return retIndex;
}

void UninitTexture(void)
{
	for (int i = 0; i < (int)g_TextureIndex; i++)
	{
		if (g_pTexture[i] != NULL)
		{
			g_pTexture[i]->Release();
			g_pTexture[i] = NULL;
		}
	}
}

/*------------------------------------------------------------------------------
テクスチャのゲッター
------------------------------------------------------------------------------*/
LPDIRECT3DTEXTURE9 GetTexture(int index)
{
	//indexの不正値チェック(負の値)
	if (index < 0)
		return NULL;

	//indexの不正値チェック(最大数オーバー)
	if (index >= (int)g_TextureIndex)
		return NULL;

	return g_pTexture[index];
}