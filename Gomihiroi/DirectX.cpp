#include "DirectX.h"
#include "main.h"


/*------------------------------------------------------------------------------
�O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static LPDIRECT3D9			g_pD3D = NULL;		//D3D�C���^�[�t�F�[�X
static LPDIRECT3DDEVICE9	g_pD3DDevice = NULL;//D3D�f�o�C�X�̃C���^�[�t�F�[�X
static DWORD				g_ClearColor;


/*------------------------------------------------------------------------------
D3D����������
------------------------------------------------------------------------------*/
bool Initialize(HWND hWnd)
{
	//D3D�C���^�[�t�F�[�X�̎擾
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	//�擾�Ɏ��s���Ă����ꍇ�͏I��������
	if (g_pD3D == NULL)
	{
		MessageBox(hWnd, "Direct3D�C���^�[�t�F�[�X�̎擾�Ɏ��s",
			"�G���[", MB_OK);

		return false;
	}

	D3DPRESENT_PARAMETERS d3dpp = {};

	d3dpp.BackBufferWidth = SCREEN_WIDTH;		//�o�b�N�o�b�t�@�̉���
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;		//�o�b�N�o�b�t�@�̍���
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;	//�o�b�N�o�b�t�@�̃t�H�[�}�b�g
	d3dpp.BackBufferCount = 1;					//�o�b�N�o�b�t�@�̐�
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	//�X���b�v���@
	d3dpp.Windowed = TRUE;						//�E�B���h�E���[�h�ݒ�
	d3dpp.EnableAutoDepthStencil = TRUE;		//�[�x�o�b�t�@�E�X�e���V���o�b�t�@�̎g�p
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;	//�[�x�o�b�t�@�E�X�e���V���o�b�t�@�̃t�H�[�}�b�g
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;//�t���X�N���[�����̃��t���b�V�����[�g�ݒ�
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;//���t���b�V�����[�g��Present�̊֌W

															 // Direct3D�f�o�C�X�̎擾
	if (FAILED(g_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&g_pD3DDevice)))
	{
		// �f�o�C�X�̍쐬�Ɏ��s
		MessageBox(
			hWnd,
			"Direct3D�f�o�C�X�̍쐬�Ɏ��s���܂���",
			"�G���[",
			MB_OK);
		return false;
	}

	//�A���t�@�u�����h�L��
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);	// �A���t�@�u�����f�B���O������ݒ�
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);	// �ŏ��̃A���t�@����
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);	// �Q�Ԗڂ̃A���t�@����

	return true;
}

/*------------------------------------------------------------------------------
D3D�f�o�C�X�̃Q�b�^�[
------------------------------------------------------------------------------*/
LPDIRECT3DDEVICE9 GetDevice()
{
	return g_pD3DDevice;
}

/*------------------------------------------------------------------------------
�o�b�t�@�̃N���A
------------------------------------------------------------------------------*/
void ClearBuffer(void)
{
	// ��ʂ̃N���A
	g_pD3DDevice->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		g_ClearColor,
		1.0f,
		0);
}

/*------------------------------------------------------------------------------
�o�b�t�@�N���A�J���[�̕ύX
------------------------------------------------------------------------------*/
void SetClearColor(BYTE r, BYTE g, BYTE b)
{
	g_ClearColor = D3DCOLOR_RGBA(r, g, b, 255);
}
