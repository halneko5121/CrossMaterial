#pragma once

/************************************************************************************
 *																					*
 *	役割：ADVパートを管理する														*
 *																					*
 *	説明：スクリプトの実行、スクリプト.cppの終了結果のよって次のシーンに飛ばします　*
 *																					*
 *	作成日：2008年 12月 10日														*
 *																					*
 *	更新日：2008年 2月	20日														*
 *													by	三上　亘					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include "Scene.h"
#include "Script.h"
#include "Define.h"

/*================================
	
		Defineたち

=================================*/
#define MAX_TEXTURE_ADV			(4)			//ロゴ画面で使うテクスチャの数

//描画位置

//文章フェード系
#define MAX_ALPHA			(255)		//アルファ値最大
#define ALPHA_CHANGE		(10)		//アルファ値変化量(説明1)
#define ALPHA_CHANGE2		(5)			//アルファ値変化量(あらすじ)

enum TEXTURE_DATA_ADV					//ADV画面のテクスチャデータ
{
	T_ADV_LOADING,

	T_ADV_MAX,
};

enum RECT_DATA_ADV						//ADVの矩形データ
{
	R_ADV_LOADING,						
	
	R_ADV_MAX,
};

class C_Adventure : public C_Scene
{
	private:
		C_Script	*pScript;
		int use_texture;				//使用する画像の枚数を格納する。
		int alpha;						//アルファ値を変更する。
		int flag_end;
	public:
		C_Adventure(C_DGraphics *graphic);
		void Control(int * key);
		void Draw();
		void Sound();				
		void Release();
		void Init();
		void SetInit();

		~C_Adventure();
};
