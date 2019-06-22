#pragma once
/************************************************************************************
 *																					*
 *	役割：スクリプトの管理をします													*
 *																					*
 *	説明：ADVパートにおける会話などなどをテキストで管理できる						*
 *																					*
 *	作成日：2008年 11月 24日														*
 *																					*
 *	更新日：2009年 2月	27日														*
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
#include "ScriptDefine.h"

/*================================
		Define
=================================*/
//ScriptDefine.hにて定義

class C_Script 
{
private:
	C_DGraphics			*graphics;				//DGraphicsクラスのインスタンス
	LPDIRECT3DTEXTURE9	*pTexture;				//テクスチャデータ	
	DFont				*pFont;					//Fontクラスへのポインタ
	F_RECT				rect_adventure[R_MAX_ADV];		//矩形情報
	C_FileControl		*pFcontrol;

	int use_texture;							//使用する画像の枚数を格納する。

	char **string_talk;							//会話文を格納するポインタ変数
	char **string_sound;						//サウンドファイル名を格納
	char **string_graphic;						//CGファイル名を格納
	char **string_cg_rect;						//CGファイルの矩形数値を格納
	char word_copy[KIND_MAX][MAX_STRING];		//スクリプトの種類別に文字列を格納する配列
	char draw_string[TALK_MAXLINE][MAX_STRING];

	int  now_scene;								//ADVの何のシーンか判別
	int	 setline;							    //現在の行の位置
	int  drawline;								//描画の行の位置。
	int  string_section[MAX_FOLDER];			//テキストファイルの行数を判断する。
	int	 flag_talkend;	     					//会話の終了を判断する。(何話目のか)	
	int  next_icon_y;
	int  roop_soundnum; int  keep_soundnum;						
	
	int  quake_x; int  quake_y;
	int	 kind_quake;
	int  count_quake;
	int  flag_quake_continue;

	int	 alpha;
	int  alpha_pendant;
	int	 alpha_fla;
	int  count_fla;	
	int  auto_wait;

	bool flag_nexticon;
	bool flag_stopline;	 						//TRUEになると、キー入力が行われるまで文字送りをストップする。
	bool flag_window_msg;						//会話ウィンドウの表示フラグ
	bool flag_quake_x; bool flag_quake_y;
	bool flag_flash;
	bool flag_pendant;
	bool flag_auto;
	bool flag_skip;

	float fade_b[MAX_CHARAPOS];					//bottom
	float fade_t[MAX_CHARAPOS];					//top
	float fade_l[MAX_CHARAPOS];					//left
	float fade_r[MAX_CHARAPOS];					//right
	float slide_char_x; 
	float slide_char2_x; 
	float convert_rev;
	float chara_height[2];

public:
	C_Script(C_DGraphics* graphic);
			
	void Control(int* key);						//コントロール

	void Draw();								//描画

	void Init(int text_num);					//データの初期化を行う。
	
	void Release();								//解放

	void DrawTalk();							//文章の描画

	/*********************************************************************************
	会話の終了を判断する
	関数名	:void TalkEnd(int* key)
	引数	:int* key				キー情報
	戻り値	:なし
	作成者	:三上
	更新日	:  年  月  日	更新内容:なし
	*********************************************************************************/
	void TalkEnd(int* key);					

	/*********************************************************************************
	//読み込んだ文章を描画用に渡す
	関数名	:void StringAdvanced(int* key)
	引数	:なし	戻り値	:なし
	作成者	:三上
	更新日	:  年  月  日	更新内容:なし
	*********************************************************************************/
	void StringAdvanced();

	/*********************************************************************************
	スクリプト(描画関係)のキーワードセット
	関数名	:void SetScript(int max_namedata, char* text_data[], int scriptnum, int* key);
	引数	:int max_namedata		検索したい名前の最大数
			:char* text_data[]		検索する文字が格納されたchar型へのポインタ	
			:int scriptnum			スクリプトの種類
			(今回 0:背景 1:現在地名＋枠 2:キャラ名 3:左位置のキャラ 4:右位置のキャラの操作)
			:int* key				キー情報
	戻り値	:なし
	作成者	:三上
	更新日	:  年  月  日	更新内容:なし
	*********************************************************************************/
	void SetScript(int max_namedata, char* text_data[], int scriptnum ,int * key);

	/*********************************************************************************
	描画スクリプト(セットされたキーワードに応じた処理を行う)
	関数名	:void DrawScript(int max_data, char* text_data[], int scriptnum);			
	引数	:int max_data			検索したい名前の最大数
			:char* text_data[]		検索する文字が格納されたchar型へのポインタ	
			:int scriptnum			スクリプトの種類(今回 0:背景 1:現在地名＋枠 2:キャラ名 3:左位置のキャラ 4:右位置のキャラの操作)
			:int* key				キー情報
	戻り値	:なし
	作成者	:三上
	更新日	:  年  月  日	更新内容:なし
	*********************************************************************************/
	void DrawScript(int max_data, char* text_data[], int scriptnum);			

	/*********************************************************************************
	キャラの描画(ヒットした番号に応じたキャラの描画を行う)
	関数名	:void DrawChara(int scriptnum, int i);
	引数	:int scriptnum			スクリプトの種類
			:int i　				ヒットしたキャラ名の番号	
	戻り値	:なし
	作成者	:三上
	更新日	:  年  月  日	更新内容:なし
	*********************************************************************************/
	void DrawChara(int scriptnum, int i);

//	void S_SoundLoad();							//サウンドの読み込み
	void S_SoundPlay_or_Stop();					//サウンドデータの再生・停止処理

	void CharaSlide();								

	void IventCheck(int *key);

	void NextIcon();

	void AutoTalk(int *key);					
	void SkipTalk(int* key);
	void SetCharaFont();						//キャラごとにフォント変え

	void WordCheck(int *key);					//各キーワードをチェックする
	void WordCheckDraw(int* key);
	void WordCheckWindow();
	void WordCheckSound();

	int GetFlagTalkEnd(){return flag_talkend;}	//終了のフラグを返してやる

	/*********************************************************************************
	for文で検索単語を検索しヒットした番号に応じたフェードを行う
	関数名	:void FadeControl(int script_i);
	引数	:int script_i			スクリプトの種類
	戻り値	:なし
	作成者	:三上
	更新日	:  年  月  日	更新内容:なし
	*********************************************************************************/
	void FadeControl(int script_i);
	void FadeIn();	
	void FadeOut();
	void FadeRect_Top();				//矩形のTopをいじる		
	void FadeRect_Bottom();				//〃Bottomをいじる
	void FadeRect_Right();				//〃Rightをいじる
	void FadeRect_Left();				//〃Leftをいじる

	/*********************************************************************************
	for文で検索単語を検索しヒットした番号に応じた画面効果を行う
	関数名	:voidScreenAction(int script_i);
	引数	:int script_i			スクリプトの種類
	戻り値	:なし
	作成者	:三上
	更新日	:  年  月  日	更新内容:なし
	*********************************************************************************/
	void ScreenAction(int script_i);			

	/*********************************************************************************
	画面の縦揺れor横揺れ
	関数名	:void ActionQuake(int kind_quake);
	引数	:int kind_quake		1:横揺れ	2:縦揺れ
	戻り値	:なし
	作成者	:三上
	更新日	:  年  月  日	更新内容:なし
	*********************************************************************************/
	void ActionQuake(int kind_quake);			
	void ActionPendant();
	void ActionFlash();							
	
	/*********************************************************************************
	int型数字をchar型数字に分解してテキスト内の数字の検索(for文で回す)
	関数名	:void ConvertNum(int j, char* search);
	引数	:int j				検索する数字
			:char* search		数字をchar数字へ
	戻り値	:なし
	作成者	:三上
	更新日	:  年  月  日	更新内容:なし
	*********************************************************************************/
	void ConvertNum(int j, char* search);

	/*********************************************************************************
	反転時に描画位置をずらして絵の見切りを防止
	関数名	:void ConvertRev(int scriptnum);
	引数	:int scriptnum		スクリプトの種類
	戻り値	:なし
	作成者	:三上
	更新日	:  年  月  日	更新内容:なし
	*********************************************************************************/
	void ConvertRev(int scriptnum);

	void LineUpHeight(int scriptnum);

	int GetSection(int kind_folder){ return string_section[kind_folder]; }	//テキストの行数を返します

	~C_Script(void);

};
