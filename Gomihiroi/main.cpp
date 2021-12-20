#include <Windows.h>
#include <stdio.h>
#include "main.h"
#include "title.h"
#include "DirectX.h"
#include "input.h"
#include "scene.h"
#include "texture.h"
#include "game.h"
#include "PuzzleBlock.h"
#include "PuzzleBlock2.h"
#include "PuzzleBlock3.h"
#include "PuzzleBlock4.h"
#include "PuzzleBlock5.h"
#include "timelimit.h"
#include "highscoreresult.h"
#include "normalresult.h"
//#include "sound.h"
//#include "fade.h"
//#include "goalscene.h"


#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")


/*------------------------------------------------------------------------------
�萔��`
------------------------------------------------------------------------------*/
#define CLASS_NAME     "GameWindow"
#define WINDOW_CAPTION "Gomihiroi"


/*------------------------------------------------------------------------------
�v���g�^�C�v�錾
------------------------------------------------------------------------------*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void Update(HWND hWnd);
void Draw(void);

/*------------------------------------------------------------------------------
�O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static int g_MouseCursorPos_x;
static int g_MouseCursorPos_y;


/*------------------------------------------------------------------------------
���C���֐�
------------------------------------------------------------------------------*/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//�E�B���h�E�N���X�̓o�^
	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = CLASS_NAME;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	RegisterClass(&wc);

	//�E�B���h�E�X�^�C���̍쐬
	DWORD window_style = WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
	//�E�B���h�E�T�C�Y�̋�`���쐬
	RECT window_rect = { 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };
	//�E�B���h�E�X�^�C���ɍ��킹�ċ�`�𒲐�����
	AdjustWindowRect(&window_rect, window_style, FALSE);

	//�������ꂽ��`����E�B���h�E�T�C�Y���č쐬����
	int window_width = window_rect.right - window_rect.left;
	int window_height = window_rect.bottom - window_rect.top;

	//�f�X�N�g�b�v�̉𑜓x���擾
	int desktop_width = GetSystemMetrics(SM_CXSCREEN);
	int desktop_height = GetSystemMetrics(SM_CYSCREEN);

	//�E�B���h�E�̈ʒu�i����j���f�X�N�g�b�v�̂ǂ��Ɉړ��������
	//�����ɕ\������邩���v�Z����
	//�i���f�X�N�g�b�v�̊O�ɏo�Ă��������ł���΍���̋��ɃZ�b�g����j
	int window_x = max((desktop_width - window_width) / 2, 0);
	int window_y = max((desktop_height - window_height) / 2, 0);

	//�E�B���h�E�̍쐬
	HWND hWnd = CreateWindow(
		CLASS_NAME,			//Windows�ɓo�^���閼�O
		WINDOW_CAPTION,		//�^�C�g���ɕ\�����镶����
		window_style,		//�E�B���h�E�̃X�^�C��
		window_x,			//X�ʒu���S�_
		window_y,			//Y�ʒu���S�_
		window_width,		//���� width
		window_height,		//���� height
		NULL,				//�e�E�B���h�E�̎w��iHWND�j
		NULL,				//���j���[�̃n���h��
		hInstance,			//�C���X�^���X�̃n���h��
		NULL				//�ǉ��̊g���̈�i���Ɏg��Ȃ��̂�NULL���w��j
	);
	//�E�B���h�E���쐬�ł������`�F�b�N����
	if (hWnd == NULL) {
		return 0;
	}

	//�쐬�����E�B���h�E����ʂɕ\������
	ShowWindow(hWnd, nCmdShow);
	//�E�B���h�E���̍X�V
	UpdateWindow(hWnd);

	////������
	Initialize(hWnd);
	Keyboard_Initialize(hInstance, hWnd);

	//InitSound(hWnd);

	//InitFade();


	//�V�[���̏������i�^�C�g������X�^�[�g
	//SceneFadeIn(SCENE_GAME1_1);
	InitScene(SCENE_GAME);

	//�f�o�b�O������̏�����
	//InitDebugProc();

	//�Q�[���̏�����
	//InitGame();

	//���b�Z�[�W���[�v
	MSG msg = {};
	while (WM_QUIT != msg.message)
	{
		//Windows���烁�b�Z�[�W�������ꍇ�̓��b�Z�[�W����������
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			//�Q�[���̏����������ɏ����Ă���
			Update(hWnd);
			Draw();
			DrawScene();
		}
	}

	//�V�[���̏I������
	UninitScene();

	
	Keyboard_Finalize();
	UninitTexture();
	//UninitSound();

	return (int)msg.wParam;
}

/*------------------------------------------------------------------------------
�v���V�[�W��
------------------------------------------------------------------------------*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN://�L�[�������ꂽ���b�Z�[�W
		if (wParam == VK_ESCAPE)
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0);//WM_CLOSE���b�Z�[�W�������ɑ���
		}
		break;


	case WM_LBUTTONDOWN:
		//�}�E�X���{�^������
	/*	g_MouseCursorPos_x = LOWORD(lParam);
		g_MouseCursorPos_y = HIWORD(lParam);*/
		//return MousePointerPos();

	case WM_LBUTTONUP:
		//�}�E�X���{�^��������
		return 0;


	case WM_CLOSE:// �E�B���h�E����郁�b�Z�[�W
		if (MessageBox(hWnd, "�I�����Ă�낵���ł����H", "�m�F",
			MB_OKCANCEL | MB_DEFBUTTON2) == IDOK)
		{
			DestroyWindow(hWnd); //�w��̃E�B���h�E��WM_DESTROY�𑗂�
		}
		return 0;

	case WM_DESTROY: //�E�B���h�E�j�����b�Z�[�W
		PostQuitMessage(0); // WM_QUIT���b�Z�[�W�𑗂�
		return 0;
	}

	//���̑��̃��b�Z�[�W��Windows�ɔC����
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
int onClick = 0;
int OldClick = 0;
int RespondToMouse = 0;
/*------------------------------------------------------------------------------
�Q�[���̍X�V
------------------------------------------------------------------------------*/
void Update(HWND hWnd)
{
	
	Keyboard_Update();
	
	//���N���b�N���ꂽ���H
	//int onClick = (GetKeyState(VK_LBUTTON) & 0x80) ? 1 : 0;
	if ((onClick = GetKeyState(VK_LBUTTON) & 0x80) && RespondToMouse == 0)
	{
		onClick = 1;
		TitleSetMouse(onClick);
		DustSetMouse(onClick);
		BananaSetMouse(onClick);
		BookSetMouse(onClick);
		TrashSetMouse(onClick);
		FridgeSetMouse(onClick);
		HighResultSetMouse(onClick);
		NormalResultSetMouse(onClick);
		PrevMouse(onClick);
	}
	else if(onClick = GetKeyState(VK_LBUTTON) & 0x80)
	{
		onClick = 0;
		TitleSetMouse(onClick);
		DustSetMouse(onClick);
		BananaSetMouse(onClick);
		BookSetMouse(onClick);
		TrashSetMouse(onClick);
		FridgeSetMouse(onClick);
		HighResultSetMouse(onClick);
		NormalResultSetMouse(onClick);
	}
	else
	{
		PrevMouse(0);
	}

	UpdateScene(hWnd);
}

/*------------------------------------------------------------------------------
�Q�[���̕`��
------------------------------------------------------------------------------*/
void Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	// ��ʂ̃N���A
	pDevice->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_RGBA(100, 80, 200, 255),
		1.0f,
		0);

	// �`��̊J�n
	pDevice->BeginScene();

	// �Q�[���̕`�揈��



	DrawScene();

	// �`��̏I��
	pDevice->EndScene();

	// �o�b�N�o�b�t�@���t���b�v
	pDevice->Present(
		NULL,
		NULL,
		NULL,
		NULL
	);
}

void PrevMouse(int index)
{
	RespondToMouse = index;
}

/*------------------------------------------------------------------------------
Debug print
------------------------------------------------------------------------------*/
void DebugPrint(int i) {
	char str[256];
	sprintf_s(str, ": %d \n", i);
	OutputDebugString(str);
}
void DebugPrint(float f) {
	char str[256];
	sprintf_s(str, ": %f \n", f);
	OutputDebugString(str);
}
void DebugPrint(bool b) {
	char str[256];
	sprintf_s(str, ": %d \n", b);
	OutputDebugString(str);
}
void DebugPrint(char s[]) {
	OutputDebugString(s);
}