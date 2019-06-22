#pragma once

/************************************************************************************
 *																					*
 *	役割：ロゴ画面の管理をする														*
 *																					*
 *	説明：ロゴ画面のControlとRenderがあります										*
 *																					*
 *	作成日：2008年 8月 6日															*
 *																					*
 *	更新日：2009年 2月 5日															*
 *													by	兼武　芳典					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include"Scene.h"

/*================================
	
		Defineたち

=================================*/
#define LOGO_END_COUNT			(220)		//ロゴ終了カウント
#define TEXTURE_SIZE_LOGO		(1024.0f)	//テクスチャのサイズ
#define MAX_TEXTURE_LOGO		(4)			//ロゴ画面で使うテクスチャの数

enum TEXTURE_LOGO
{
	T_TEAM_LOGO,

	MAX_LOGO_TEXTURE,
};

enum DATA_LOGO
{
	D_TEAM_LOGO,	

	MAX_STAGE_DATA,
};

enum LOGO_SOUND_DATA	//ロゴのサウンドデータ
{
	S_LOGO_1,
	S_LOGO_2,
	S_LOGO_3,
	S_LOGO_4,
	S_LOGO_5,

	MAX_S_LOGO,
};
class C_Logo : public C_Scene
{
	private:
		int use_texture;	//使用する画像の枚数を格納する。

		int time_count;		//ロゴのタイムカウント。
	
		int alpha;			//ロゴのアルファ値を変更する。

		int randum_voice;

		bool flag_soundstop;
	
	public:
		C_Logo(C_DGraphics *in_graphics);//コンストラクタ
		
		~C_Logo();	//デストラクタ
		
		void Init();

		void Control(int* key);			//コントロール
		
		void Draw();						//描画
		
		void Sound();						//サウンドの管理
		
		void Release();						//解放
		
		void FadeControl(); 				//フェード処理

};