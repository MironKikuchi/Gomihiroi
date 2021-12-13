#include <d3dx9.h>
#include <math.h>
#include "DirectX.h"
#include "texture.h"

typedef struct Vertex2D_tag
{
	D3DXVECTOR4 position;
	D3DCOLOR color;
	D3DXVECTOR2 texcoord;
} Vertex2D;
#define FVF_VERTEX2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)

static D3DCOLOR g_Color = D3DCOLOR_RGBA(255, 255, 255, 255);



void DrawSprite(int texture_index, float posx, float posy, float width, float height)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	if (!pDevice) return;

	float w = width / 2;
	float h = height / 2;

	Vertex2D vertexes[] = {
		{ D3DXVECTOR4(posx - w - 0.5f, posy - h - 0.5f, 0.0f, 1.0f), g_Color, D3DXVECTOR2(0.0f, 0.0f) },
		{ D3DXVECTOR4(posx + w - 0.5f, posy - h - 0.5f, 0.0f, 1.0f), g_Color, D3DXVECTOR2(1.0f, 0.0f) },
		{ D3DXVECTOR4(posx - w - 0.5f, posy + h - 0.5f, 0.0f, 1.0f), g_Color, D3DXVECTOR2(0.0f, 1.0f) },
		{ D3DXVECTOR4(posx + w - 0.5f, posy + h - 0.5f, 0.0f, 1.0f), g_Color, D3DXVECTOR2(1.0f, 1.0f) },
	};

	pDevice->SetFVF(FVF_VERTEX2D);
	pDevice->SetTexture(0, GetTexture(texture_index));

	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertexes, sizeof(Vertex2D));
}

void DrawSprite(int texture_index, float posx, float posy, float width, float height, float tx, float ty, float tw, float th)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	if (!pDevice) return;

	float w = width / 2;
	float h = height / 2;

	float u[2], v[2];
	u[0] = (float)tx;
	v[0] = (float)ty;
	u[1] = (float)(tx + tw);
	v[1] = (float)(ty + th);

	Vertex2D vertexes[] = {
		{ D3DXVECTOR4(posx - w - 0.5f, posy - h - 0.5f, 0.0f, 1.0f), g_Color, D3DXVECTOR2(u[0], v[0]) },
		{ D3DXVECTOR4(posx + w - 0.5f, posy - h - 0.5f, 0.0f, 1.0f), g_Color, D3DXVECTOR2(u[1], v[0]) },
		{ D3DXVECTOR4(posx - w - 0.5f, posy + h - 0.5f, 0.0f, 1.0f), g_Color, D3DXVECTOR2(u[0], v[1]) },
		{ D3DXVECTOR4(posx + w - 0.5f, posy + h - 0.5f, 0.0f, 1.0f), g_Color, D3DXVECTOR2(u[1], v[1]) },
	};

	pDevice->SetFVF(FVF_VERTEX2D);
	pDevice->SetTexture(0, GetTexture(texture_index));
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertexes, sizeof(Vertex2D));
}

void DrawSpriteColor(int texture_index, float posx, float posy, float width, float height, float tx, float ty, float tw, float th, D3DXCOLOR color)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	if (!pDevice) return;

	float w = width / 2;
	float h = height / 2;

	float u[2], v[2];
	u[0] = (float)tx;
	v[0] = (float)ty;
	u[1] = (float)(tx + tw);
	v[1] = (float)(ty + th);

	Vertex2D vertexes[] = {
		{ D3DXVECTOR4(posx - w - 0.5f, posy - h - 0.5f, 0.0f, 1.0f), color, D3DXVECTOR2(u[0], v[0]) },
		{ D3DXVECTOR4(posx + w - 0.5f, posy - h - 0.5f, 0.0f, 1.0f), color, D3DXVECTOR2(u[1], v[0]) },
		{ D3DXVECTOR4(posx - w - 0.5f, posy + h - 0.5f, 0.0f, 1.0f), color, D3DXVECTOR2(u[0], v[1]) },
		{ D3DXVECTOR4(posx + w - 0.5f, posy + h - 0.5f, 0.0f, 1.0f), color, D3DXVECTOR2(u[1], v[1]) },
	};

	pDevice->SetFVF(FVF_VERTEX2D);
	pDevice->SetTexture(0, GetTexture(texture_index));
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertexes, sizeof(Vertex2D));
}