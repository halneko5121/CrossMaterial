/************************************************************************************
 *																					*
 *	�����F���C��																	*
 *																					*
 *	�����F���x�ǂ����A���C���ł��I													*
 *																					*
 *	�쐬���F2008�N11��30��															*
 *																					*
 *	�X�V���F2008�N �� ��															*
 *													by ���� ���F					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE����

=================================*/
#include "Main.h"


void Render()		//�`����s��
{
	if(!pD3Device) 
	{
		MessageBox(NULL,TEXT("pD3Device��������܂���"),NULL,MB_OK);
		
		return;
	}	

	//��ʂ̏���
	pD3Device->Clear(0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0x00, 0x00, 0x00),1.0,0);
														//���`�悳��ĂȂ������̐F�w��

	//�`��̊J�n
	pD3Device->BeginScene();

	game_manage->Draw();		

	//�`��̏I��
	pD3Device->EndScene();

	pD3Device->Present(NULL,NULL,NULL,NULL);
}

//-------------------------------------------------------------
//
//	���b�Z�[�W����
//
//-------------------------------------------------------------

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg) 
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_KEYDOWN:
			switch(wp){
			case VK_ESCAPE :
				PostQuitMessage(0);
				break;
			}
	}

	return DefWindowProc(hWnd , msg , wp , lp);
}

//-------------------------------------------------------------
//
//	���C�����[�`��
//
//-------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	HWND hWnd;
	WNDCLASS winc;
	D3DDISPLAYMODE d3ddm;	//�f�B�X�v���C�̏�Ԃ�n���B�i�\���́j

	//DirectX�@�I�u�W�F�N�g����
	pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);
	
	//Windows���̐ݒ�
	winc.style 			= CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc	= WndProc;
	winc.cbClsExtra		= winc.cbWndExtra = 0;
	winc.hInstance		= hInstance;
	winc.hIcon			= LoadIcon(NULL , IDI_APPLICATION);
	winc.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	winc.lpszMenuName	= NULL;
	winc.lpszClassName	= TEXT("CrossMaterial");

	//Display Mode �̐ݒ�
	pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT,&d3ddm);
	ZeroMemory(&d3dpp,sizeof(D3DPRESENT_PARAMETERS));
	d3dpp.BackBufferFormat = d3ddm.Format;
	d3dpp.BackBufferCount  = 1;
	d3dpp.SwapEffect       = D3DSWAPEFFECT_DISCARD;

#ifdef DEBUG
	d3dpp.Windowed		   = TRUE;

#else
	d3dpp.Windowed		   = FALSE;
	d3dpp.BackBufferHeight = 600;
	d3dpp.BackBufferWidth  = 800;

#endif
	//Windows���̐ݒ�
	winc.style 			= CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc	= WndProc;
	winc.cbClsExtra		= winc.cbWndExtra = 0;
	winc.hInstance		= hInstance;
	winc.hIcon			= LoadIcon(NULL , IDI_APPLICATION);
	winc.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName	= NULL;
	winc.lpszClassName	= TEXT("Human Game College");
	//Windows�̓o�^
	if (!RegisterClass(&winc)) return 0;

#ifdef TEXT
	RECT windowSize;

	windowSize.top = 0;
	windowSize.bottom = 600;
	windowSize.left = 0;
	windowSize.right = 800;

	//�����Ƃ��킹�Ă����֐�
	AdjustWindowRect(&windowSize,WS_OVERLAPPEDWINDOW,false);

	windowSize.right = windowSize.right - windowSize.left;
	windowSize.bottom = windowSize.bottom - windowSize.top;
	windowSize.top = 0;
	windowSize.left = 0;

	//Windows�̐���
	hWnd = CreateWindow(
		TEXT("Human Game College") , 
		TITLE , 
		WS_OVERLAPPEDWINDOW | WS_VISIBLE ,
		CW_USEDEFAULT ,		// x
		CW_USEDEFAULT ,		// y
		windowSize.right ,				// Width
		windowSize.bottom ,				// Height
		NULL , NULL , hInstance , NULL
	);

#else
	RECT windowSize;

	windowSize.top	  = 0;
	windowSize.bottom = 600;
	windowSize.left   = 0;
	windowSize.right  = 800;

	//�����Ƃ��킹�Ă����֐�
	AdjustWindowRect(&windowSize,WS_OVERLAPPEDWINDOW,false);

	windowSize.right = windowSize.right - windowSize.left;
	windowSize.bottom = windowSize.bottom - windowSize.top;
	windowSize.top = 0;
	windowSize.left = 0;

	hWnd = CreateWindowEx(0,
		TEXT("CrossMaterial"),
		NULL,
		WS_POPUP | WS_VISIBLE ,
		0,
		0,
		windowSize.right,				// Width
		windowSize.bottom ,				// Height
		NULL,NULL,hInstance,NULL);

#endif
	if (!hWnd) return 0;

	pDirect3D->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&d3dpp, &pD3Device);
	
    //�`������̐ݒ�
	pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	pD3Device->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
	pD3Device->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
	//pD3Device->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_ONE);
	pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	pD3Device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	InitDinput(hWnd);	//DirectInput������
	InitDSound(hWnd);	//DirectSound������
	
	game_manage = new C_GameManage(pD3Device);	//GameManage�̃C���X�^���X�𐶐�����

#ifdef MEMORY_CHECK
//	::_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
#endif

	ZeroMemory(&msg, sizeof(msg));


	while (msg.message != WM_QUIT) 
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			static DWORD oldTime = timeGetTime();
					
			DWORD nowTime = timeGetTime();		//���ݎ������擾

			if(nowTime - oldTime >= 1000/60)	//1000�ň�b�A�܂�U�b�������ꍇ
			{
				game_manage->Control();

				Render();

				oldTime = nowTime;				//�Â����ԂɌ��ݎ�������
			}
		}
	}

	delete game_manage;

	return (int)msg.wParam;
}
