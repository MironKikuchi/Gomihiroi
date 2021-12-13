#pragma once

#include <d3dx9.h>
// ウィンドウのサイズ
#define SCREEN_WIDTH  450	//幅
#define SCREEN_HEIGHT 800	//高さ
#define SCREEN_HALFWIDTH  225	//幅
#define SCREEN_HALFHEIGHT 400	//高さ

//620 924

// ２Dポリゴン頂点構造体
typedef struct Vertex2D_tag
{
	D3DXVECTOR4 position; // 頂点座標（座標変換済み頂点）
	D3DCOLOR	color;
	D3DXVECTOR2 texCoord;
} Vertex2D;
#define FVF_VERTEX2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1) // ２Dポリゴン頂点フォーマット

int MousePointerPos();