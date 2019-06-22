#pragma once

/************************************************************************************
 *																					*
 *	役割：プロローグを管理します													*
 *																					*
 *	説明：世界観説明→詳細→あらすじ(本編に続く)→本編								*
 *																					*
 *	作成日：2008年 12月 5日															*
 *																					*
 *	更新日：2008年 2月 20日															*
 *													by	三上　亘					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include"Scene.h"

/*================================
	
		Defineたち

=================================*/
#define MAX_TEXTURE_PROLOGUE	(5)
//描画位置
#define POS_BG_PROLOGUE_X	(400.0f)
#define POS_BG_PROLOGUE_Y	(300.0f)

#define POS_WORLD1_LINE1_X	(50.0f)
#define POS_WORLD1_LINE1_Y	(200.0f)
#define POS_WORLD1_LINE2_X	(150.0f)
#define POS_WORLD1_LINE2_Y	(300.0f)
#define POS_WORLD1_LINE3_X	(250.0f)
#define POS_WORLD1_LINE3_Y	(400.0f)

#define POS_WORLD2_X		(80.0f)
#define POS_WORLD2_Y		(600.0f)

//文章切り替え系
//#define COUNT_CHANGE		(200)		//文章を切り替えていく速さ
#define R_SLIDE_SIZE		(90.0f)		//切り取る文章をずらす量(紹介1)
#define R_SLIDE_SIZE2		(150.0f)	//切り取る文章をずらす量(紹介2)
#define MAX_SLIDE			(19)		//切り取りスライドを行う回数(紹介1)
#define MAX_SLIDE2			(11)		//切り取りスライドを行う回数(紹介2)
#define FONTSIZE			(30.f)	
//文章フェード系
#define FADE_TIME			(300)		//フェードさせる速さ
#define FADE_SPEED_PRO		(5)			
#define MAX_ALPHA			(255)		//アルファ値最大
#define ALPHA_CHANGE		(10)		//アルファ値変化量(説明1)

//文章スライド
#define SLIDE_SPEED_WORLD2	(10.0f)		//スライドさせる速さ(説明詳細)
#define SLIDE_SPEED_PLOT	(0.5f)		//スライドさせる速さ(あらすじ)
#define WAIT_TIME			(400)		//スライドを止めておく時間
#define WAIT_POS			(250.0f)	//この位置まで来たらSTOP!
#define SLIDE_RETURN		(-150.0f)	//この位置まで来たらも一度下からおいで
#define NEXTSTORY_POS		(-1800.0f)	//この位置まで来たらもプロローグ終了。本編へ

enum TEXTURE_PROLOGUE		//TEXTURE(統合ファイル)の番号
{
	T_BG_PROLOGUE,			//背景
	T_WRITING,				//文章画像データ
	T_PRO_LOADING,

	T_MAX_PROLOGUE,
};

enum RECT_PROLOGUE			//矩形の番号
{
	R_BG_PROLOGUE,			//背景
	R_WORLD1_1LINE,			//世界観紹介(文章画像データ)
	R_WORLD1_2LINE,			//世界観紹介(文章画像データ)
	R_WORLD1_3LINE,			//世界観紹介(文章画像データ)
	R_WORLD2,				//世界観紹介詳細(文章画像データ)
	R_PLOT,					//あらすじ　(文章画像データ)
	R_PRO_LOADING,
	
	R_MAX_PROLOGUE,
};

enum SOUND_PROLOGUE
{
	S_WORLD1_2,
	S_PLOT,
};

class C_Prologue : public C_Scene
{
	private:
		int use_texture;			//使用する画像の枚数を格納する。
		int use_sound;
		int count_fade_pro;			//あらすじなどの文章のフェード処理
		int alpha;					//文章のアルファ値を変更する。
		int alpha2;					
		int rect_slide;				//文章を切り取る位置をスライドさせていく
		int count_wait;				//待ち時間

		float pos_slide;			//描画位置(yだけいじって上へ流します)

	public:
		C_Prologue(C_DGraphics* graphic);
		void Init();
		void Control(int* key);
		void Draw();
		void Sound();				//サウンドの管理
		void Release();

		void SlideRect();			//一行ずつ切り取り位置をずらす
		void FadeIn();				//フェードイン処理
		void FadeOut();				//フェードアウト処理
		void Slide();				//描画位置をスライド
		void ShortCutKey(int* key);
		void DebugKey(int* key);

		~C_Prologue();
};
