/************************************************************************************
 *																					*
 *	�����F���C��																	*
 *																					*
 *	�����F�������C��																*
 *																					*
 *	�쐬���F2008�N8��7��															*
 *																					*
 *	�X�V���F2008�N �� ��															*
 *													by ���� ���F					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE����

=================================*/
#include <windows.h>
#include <d3d9.h>
#include <d3dx9tex.h>
#include <math.h>

#include "GameManage.h"

/*================================
	
		DEFINE����

=================================*/
#define TITLE 	TEXT("CrossMaterial")

#define MEMORY_CHECK
/*================================
	
		pragma comment

=================================*/
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib" )
#pragma comment(lib, "d3dx9.lib")


C_GameManage *game_manage;		//GameManage�̃I�u�W�F�N�g�����w�� 

IDirect3D9*			pDirect3D;	// DirectX��ǂ݂��ވׂɂ�IDirect3D9�Ƃ����^�łȂ��Ɠ����Ȃ�
IDirect3DDevice9*	pD3Device;			
LPDIRECT3DTEXTURE9  pTexture[2];
//C_DGraphics*		graphics;

D3DPRESENT_PARAMETERS d3dpp;