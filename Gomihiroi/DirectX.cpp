#include "DirectX.h"
#include "main.h"


/*------------------------------------------------------------------------------
グローバル変数の定義
------------------------------------------------------------------------------*/
static LPDIRECT3D9			g_pD3D = NULL;		//D3Dインターフェース
static LPDIRECT3DDEVICE9	g_pD3DDevice = NULL;//D3Dデバイスのインターフェース
static DWORD				g_ClearColor;


/*------------------------------------------------------------------------------
D3D初期化処理
------------------------------------------------------------------------------*/
bool Initialize(HWND hWnd)
{
	//D3Dインターフェースの取得
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	//取得に失敗していた場合は終了させる
	if (g_pD3D == NULL)
	{
		MessageBox(hWnd, "Direct3Dインターフェースの取得に失敗",
			"エラー", MB_OK);

		return false;
	}

	D3DPRESENT_PARAMETERS d3dpp = {};

	d3dpp.BackBufferWidth = SCREEN_WIDTH;		//バックバッファの横幅
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;		//バックバッファの高さ
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;	//バックバッファのフォーマット
	d3dpp.BackBufferCount = 1;					//バックバッファの数
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	//スワップ方法
	d3dpp.Windowed = TRUE;						//ウィンドウモード設定
	d3dpp.EnableAutoDepthStencil = TRUE;		//深度バッファ・ステンシルバッファの使用
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;	//深度バッファ・ステンシルバッファのフォーマット
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;//フルスクリーン時のリフレッシュレート設定
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;//リフレッシュレートとPresentの関係

															 // Direct3Dデバイスの取得
	if (FAILED(g_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&g_pD3DDevice)))
	{
		// デバイスの作成に失敗
		MessageBox(
			hWnd,
			"Direct3Dデバイスの作成に失敗しました",
			"エラー",
			MB_OK);
		return false;
	}

	//アルファブレンド有効
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);	// アルファブレンディング処理を設定
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);	// 最初のアルファ引数
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);	// ２番目のアルファ引数

	return true;
}

/*------------------------------------------------------------------------------
D3Dデバイスのゲッター
------------------------------------------------------------------------------*/
LPDIRECT3DDEVICE9 GetDevice()
{
	return g_pD3DDevice;
}

/*------------------------------------------------------------------------------
バッファのクリア
------------------------------------------------------------------------------*/
void ClearBuffer(void)
{
	// 画面のクリア
	g_pD3DDevice->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		g_ClearColor,
		1.0f,
		0);
}

/*------------------------------------------------------------------------------
バッファクリアカラーの変更
------------------------------------------------------------------------------*/
void SetClearColor(BYTE r, BYTE g, BYTE b)
{
	g_ClearColor = D3DCOLOR_RGBA(r, g, b, 255);
}
