#pragma once

/************************************************************************************
 *																					*
 *	役割：シーンの基底クラス														*
 *																					*
 *	説明：シーンの基底クラス														*
 *																					*
 *	作成日：2008年 11月30日															*
 *																					*
 *	更新日：2009年 2月 20日															*
 *													by	早瀬 公彦					*
 *													更新　三上 亘					*
 ************************************************************************************/

/*================================

		INCLUDEたち

=================================*/
#include "Control.h"
#include "DirectGraphics.h"
#include "DirectSound.h"
#include "Define.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


class C_Scene
{
	protected:
		C_Control			*p_control;			//コントロールクラスへのポインタ
		
		C_DGraphics			*m_graphics;		//C_DGraphicsのオブジェクト名を指定
		
		LPDIRECT3DTEXTURE9	*m_pTexture;		//テクスチャデータ
	
		LPDIRECT3DTEXTURE9  *pChara;
		
		F_RECT *getRect;						//画像データのRect情報

		int					m_max_texture;		//テクスチャ枚数
		
		int					m_max_sound;		//サウンドデータ数
		
		int					m_scene_flag;		//現在のシーン名を判断する。

		int					*m_scene_number;	//シーン内の区切りを判断する。

		int					*m_scene_num[MAX_SCENE];//シーン内のどこから始めるか(ADVなら、ADVパートの何話かなど)(追加)
		
		int					m_count_fade;		//フェードの回数

		int					m_alpha_load;

		bool				m_flag_fade;		//フェードイン・アウトのフラグ
			
		char				**m_p_sound_file;	//サウンドファイル名
		
		char				*m_scene_name;		//現在のシーン名を指定する。
	
	public:

		virtual void Control(int *key) = 0;		//コントロール
		
		virtual void Draw()    = 0;				//描画

		virtual void Init()    = 0;				//初期化

		virtual void Sound()   = 0;				//サウンドの管理	

		virtual void Release() = 0;				//解放

		/************************************************************************************
		*	説明	：他のシーン移行時にかかる時間の間に『NowLoading』を点滅表示する		*
		*	引数	：なし																	*
		*	戻り値	：なし																	*
		*													by	三上　亘					*
		************************************************************************************/
		void NowLoading();	

		/************************************************************************************
		*	説明	：シーンを移行させる。『NowLoading』を点滅表示する						*
		*	引数	：int scene_flag　	移行先のシーンフラグ								*
		*	戻り値	：なし																	*
		*													by	三上　亘					*
		************************************************************************************/
		void NowLoading(int scene_flag);	

		/************************************************************************************
		*	説明	：シーン移行＋シーン内設定。『NowLoading』を点滅表示する				*
		*	引数	：int scene_flag　	移行先のシーンフラグ								*
		*			：int scene_number　移行シーン内の番号									*
		*	戻り値	：なし																	*
		*													by	三上　亘					*
		************************************************************************************/
		void NowLoading(int scene_flag, int scene_number);	

		/************************************************************************************
		 *	説明	：現在のシーンの中の順番(例:『ADVパート』の『1話』など)をセットする		*
		 *	引数	：int m_scene_flag		現在のシーン									*
		 *			  int *scene_number		シーンの順番									*
		 *	戻り値	：なし																	*
		 *													by	三上　亘					*
		 ************************************************************************************/
		void SetSceneNum(int m_scene_flag,int *m_scene_number) {m_scene_num[m_scene_flag] = m_scene_number;}

		/************************************************************************************
		 *	説明	：現在のシーンの中の順番(例:『ADVパート』の『1話』など)をとってくる		*
		 *	引数	：なし																	*
		 *	戻り値	：int scene_no															*
		 *													by	三上　亘					*
		 ************************************************************************************/
		int* GetSceneNum(int m_scene_flag)  {return m_scene_num[m_scene_flag];}	
		
		void SoundLoad(char *m_scene_name);					//サウンドデータを読み込む。

		void SetName(char* name) {m_scene_name = name;}		//シーン切り替え後のシーン名をセットしなおす。

		void SetFRect(F_RECT *get)	{getRect = get;}		//Rectの値をセットする。

		int GetSceneFlag() {return m_scene_flag;}			//m_scene_flagを取得する。

		void SetTextureData(LPDIRECT3DTEXTURE9 *get) {pChara = get;}	//テクスチャ情報をセットする。

		LPDIRECT3DTEXTURE9 *GetTexture() {return &m_pTexture[0];}			//テクスチャ情報を取得する。

};

		
