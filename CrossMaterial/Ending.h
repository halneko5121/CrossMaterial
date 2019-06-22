#pragma once

/************************************************************************************
 *																					*
 *	役割：エンディング画面の管理をします											*
 *																					*
 *	説明：少しずつ統合ファイルを変えつつスタッフロールをスクロールさせる			*
 *																					*
 *	作成日：2009年 2 月15日															*
 *																					*
 *	更新日：年 月 日																*
 *													by	三上　亘					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include "Scene.h"

/*================================
	
		Define

=================================*/
#define NEXTSCENE_POS	(350.f)			// ここまできたら次のシーン
#define SLIDE_SPEED		(1.f)		
#define MAX_STAFFNAME	(20)	
#define WAITTIME		(400)	

#define ALPHA_STOP		(100)
#define ALPHA_F_OUT		(2)
#define ALPHA_F_IN		(3)
#define LAST_ALPHA_IN	(2)
#define ALPHA_STOP		(100)

#define SP_SLIDE_POS	(1.5f)
#define SP_SLIDE_POS2	(1.5f)


enum TEXTURE_ENDING						// エンディング画面のテクスチャデータ
{
	T_END_BACK,							// 背景
	T_END_STAFFNAME1,					// スタッフ～ネ～ム
	T_END_STAFFNAME2,					// スタッフ～ネ～ム
	T_END_STAFFNAME3,					// スタッフ～ネ～ム
	T_END_STAFFNAME4,					// スタッフ～ネ～ム
	T_END_STAFFNAME5,					// スタッフ～ネ～ム
	T_END_STAFFNAME6,					// スタッフ～ネ～ム
	T_END_STAFFNAME7,					// スタッフ～ネ～ム
	T_END_STAFFNAME8,					// スタッフ～ネ～ム
	T_END_LASTMESSAGE,					
	T_END_LOADING,						// LOADING

	T_END_MAX,
};

enum RECT_END							// エンディングの矩形データ
{
	R_END_BACK,							// 背景
	R_END_STAFFNAME,					// スタッフ～ネ～ム
	R_END_LASTMESSAGE1,					
	R_END_LASTMESSAGE2,					
	R_END_LASTMESSAGE3_4,					
	R_END_LASTMESSAGE5,					
	R_END_LASTMESSAGE6,					
	R_END_LASTMESSAGE7,					
	R_END_LASTMESSAGE8,					

	R_END_LOADING,						// LOADING

	R_END_MAX,
};

enum END_SOUND_DATA						// Endingのサウンドデータ
{
	S_END_BGM,

	MAX_S_END,
};


class C_Ending : public C_Scene
{
private:

	int 	use_texture;		//使用する画像の枚数を格納する。

	int		alpha_staff;
	int		count_wait;			//ちょっと待って
	int		count_alpha;
	int		staffroll_1;
	int		staffroll_2;
	int		fade_flag;			//フェードイン、フェードアウトのフラグ
	int		stay_cnt;
	int		next_message;

	float	slide_pos;
	float	slide_pos2;				
	float 	alpha_back;			//アルファ値を変更する。

	bool	endflag;
	bool	lastflag;
	bool	lastmessage;
	bool	flag_slide_1;
	bool	flag_slide_2;
	bool	flag_lastfadein;
	bool	flag_nowloading;

private:
	void FadeControl();
	void FadeIn();
	void FadeOut();
	void Slide();
public:
	C_Ending(C_DGraphics *graphic);
	
	void Control(int* key);

	void Init();

	void Draw();

	void Sound();				//サウンドの管理

	void Release();

	~C_Ending(void);
};