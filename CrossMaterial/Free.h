#pragma once
/************************************************************************************
 *																					*
 *	役割：FREEパートを管理します													*
 *																					*
 *	説明：FREEパートのControlとRenderがあります										*
 *																					*
 *	作成日：2009年 3月	9日															*
 *																					*
 *	更新日：    年  月　 日															*
 *													by	三上　亘					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include <stdio.h>
#include <string.h>
#include "Define.h"

#include "DirectGraphics.h"
#include "DirectFont.h"
#include "DirectSound.h"
#include "FileControl.h"
#include "Control.h"
#include "Script.h"

/*================================
	
		Defineたち

=================================*/

enum FREE_STATE
{
	BASE,
	CLASS,
	MATERIAL,
	MPSET,
	STATE,
	SAVE,
};

enum TEXTURE_FREE						// エンディング画面のテクスチャデータ
{
	T_FREE_BG,							// 背景
	T_FREE_LOADING,						// LOADING

	T_FREE_MAX,
};

enum RECT_FREE							//矩形データ
{
	R_FREE_BG,							// 背景
	R_FREE_LOADING,						// LOADING

	R_FREE_MAX,
};

enum FREE_SOUND_DATA						// タイトルのサウンドデータ
{
	S_FREE_BGM,

	MAX_S_FREE,
};

class C_Free 
{
private:
	C_DGraphics			*graphics;				//DGraphicsクラスのインスタンス
	LPDIRECT3DTEXTURE9	*pTexture;				//テクスチャデータ	
	DFont				*pFont;					//Fontクラスへのポインタ
	C_Script			*pScript;
//	F_RECT				rect_adventure[R_MAX_ADV];		//矩形情報

	int			cursor_locate;

	int 		use_texture;		//使用する画像の枚数を格納する。
	int 		*scene_check;		//シーン内の区切りを判断する


public:
	C_Free(C_DGraphics *graphic);
	void Init();
	void Control(int * key);
	void Draw();
	void Sound();				//サウンドの管理
	void Release();

	void FreeBase();	//基本
	void FreeClass();	//教室
	void FreeMaterial();//マテリアル
	void FreeMpset();	//ＭＰセット
	void FreeState();	//ステータス表示
	void FreeSave();	//セーブ
public:
	C_Free(void);	
	~C_Free(void);
};
