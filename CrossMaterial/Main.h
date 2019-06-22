/************************************************************************************
 *																					*
 *	役割：メイン																	*
 *																					*
 *	説明：所謂メイン																*
 *																					*
 *	作成日：2008年8月7日															*
 *																					*
 *	更新日：2008年 月 日															*
 *													by 早瀬 公彦					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDEたち

=================================*/
#include <windows.h>
#include <d3d9.h>
#include <d3dx9tex.h>
#include <math.h>

#include "GameManage.h"

/*================================
	
		DEFINEたち

=================================*/
#define TITLE 	TEXT("CrossMaterial")

#define MEMORY_CHECK
/*================================
	
		pragma comment

=================================*/
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib" )
#pragma comment(lib, "d3dx9.lib")


C_GameManage *game_manage;		//GameManageのオブジェクト名を指定 

IDirect3D9*			pDirect3D;	// DirectXを読みこむ為にはIDirect3D9という型でないと動かない
IDirect3DDevice9*	pD3Device;			
LPDIRECT3DTEXTURE9  pTexture[2];
//C_DGraphics*		graphics;

D3DPRESENT_PARAMETERS d3dpp;