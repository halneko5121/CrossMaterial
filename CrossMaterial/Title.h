#pragma once

/************************************************************************************
 *																					*
 *	役割：タイトル画面の管理をします												*
 *																					*
 *	説明：タイトル画面のControlとRenderがあります									*
 *																					*
 *	作成日：2008年 8月 6日															*
 *																					*
 *	更新日：2009年 2月28日															*
 *													by	兼武　芳典					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include "Scene.h"
#include "PlayerCommon.h"

/*================================
	
		Define

=================================*/
#define TITLE_ALPHA_INCREASE		(5)		//アルファ値の増加量
#define	TITLE_MAX_ALPHA				(255)	//アルファ値の最大
#define D_T_MENU_C_Y				(430.0f)//選択肢のYの中心座標

//追加 3/10三上↓
#define DRAW_CURSOR_X				(0.1f)
#define DRAW_CURSOR_Y				(0.1f)
#define DRAW_BG_POS_X				(400.0f)//ゲーム画面の中心X
#define DRAW_BG_POS_Y				(300.0f)//ゲーム画面の中心Y
//追加 3/10三上↑

enum TEXTURE_DATA_TITLE		//タイトル画面のテクスチャデータ
{
	T_TITLE_BG,		//背景
	T_TITLE_FC,		//タイトルに使うフォント
	T_TITLE_CORSOR,
	T_TITLE_LOADING,

	T_TITLE_MAX,
};

enum RECT_DATA_TITLE	//タイトルの矩形データ
{
	R_TITLE_BG,		//背景
	R_TITLE_START,	//「START」の文字
	//R_TITLE_LOAD,	//「LOAD」の文字
	R_TITLE_END,	//「END」の文字
	//R_TITLE_SAVE1,	//「SAVE1」
	//R_TITLE_SAVE2,	//「SAVE2」
	//R_TITLE_SAVE3,	//「SAVE3」
	R_TITLE_ICON,	//アイコン
	R_TITLE_LOADING,//LOADING
	
	R_TITLE_MAX,
};

enum TITLE_SOUND_DATA	//タイトルのサウンドデータ
{
	S_TITLE_BGM,
	S_TITLE_SELECT,
	S_TITLE_ENTER,
	S_TITLE_CANCEL,

	MAX_S_TITLE,
};

enum MENU_SCENE
{
	M_START,
	//M_LOAD,
	M_END,

	M_MAX,
};

class C_Title : public C_Scene
{
private:
	C_PlayerCommon p_data;

	int use_texture;			//使用する画像の枚数を格納する。

	int alpha;					//アルファ値
	
	int alpha_count;			//アルファのカウント
	
	int menu_flag;				//メニューフラグ

	int f_menu_alpha;			//メニューフォントのアルファ値

	int title_draw_flag;		//SAVEのフォントのフラグ

	int fade_flag;				//フェードイン、フェードアウトのフラグ

	//追加
	float cursor_draw_x;
	float cursor_draw_y;
	float keep_pos_y;

	//int  m_count_fade_title;		//フェードの回数

	//bool m_flag_fade_title;		//フェードイン・アウトのフラグ

public:
	C_Title(C_DGraphics *graphic);//コンストラクタ

	~C_Title(void);				//デストラクタ

	void Control(int *key);

	void FadeControl();			//フェードコントロール

	void FadeIn();				//フェードイン

	void FadeOut();				//フェードアウト

	void MenuDraw();			//メニュー描画

	void SaveDraw();			//セーブデータ描画

	void CursorDraw();

	void Init();

	void Draw();

	void Sound();				//サウンドの管理

	void Release();

	/*********************************************************************************
	カーソルの描画管理
	関数名	:void DrawCursur()
	引数	:なし
	戻り値	:なし
	作成者	:三上
	更新日	:  年  月  日	更新内容:なし
	*********************************************************************************/
	void DrawCursor();

};