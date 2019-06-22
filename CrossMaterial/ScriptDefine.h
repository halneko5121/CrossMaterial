#pragma once
/************************************************************************************
 *																					*
 *	役割：スクリプトのDefine定義をします											*
 *																					*
 *	説明：																			*
 *																					*
 *	作成日：2009年 2月 28日															*
 *																					*
 *	更新日：	年 2月   日															*
 *													by	三上　亘					*
 *																					*
 ************************************************************************************/

/*================================
		Define
=================================*/
#define _AFTER
#define STOP			("SKIPSTOP")

#define MAX_TALK_STRING (500)
#define MAX_CHARAFACE	(10)				//キャラの表情最大10
#define MAX_CHARAFILE_T	(9)					//キャラ(ADV)の統合ファイル最大9
#define MAX_BGNAME		(10)				//背景の名前最大10

//速さ関係
#define SPEED_UP		(10)
#define SPEED_DOWN		(10)
#define SPEED_FLASH		(30)
#define SPEED_QUAKE		(30)
#define SPEED_SLIDE		(20)

#define COUNT_QUAKE		(15)				
#define RETURN_QUAKE_Y	(30)
#define FLASH_WAIT		(15)
//文字列関係
#define TALK_CONVERT_NUM		(48)				//48は文字の'0'です
#define TALK_CHANGEPLACE		("PLACE:")			
#define TALK_CHARA_LEFT			("LEFT")			
#define TALK_CHARA_RIGHT		("RIGHT")			
#define TALK_MSGWINDOW			("MSGWINDOW:")	
#define TALK_TEXTNAME			("TEXT:")	
#define TALK_SOUNDLOAD			("SOUNDLOAD:")		
#define TALK_SOUNDRELEASE		("SOUNDRELEASE:")	
#define TALK_SOUNDPLAY			("SOUNDPLAY:")		
#define TALK_SOUNDSTOP			("SOUNDSTOP:")
#define TALK_FADE				("FADE:")
#define TALK_REVERSE			("REV")		//キャラの向きの反転
#define TALK_WORD				("TALK:")	//これがあった場合会話文変更

#define TALK_MAXLINE			(3)			//会話表示の最大行数
#define TALK_NEXTLINE			(1)			//次に読み込むテキストのプラスの数
#define TALK_FONTSIZE			(30)		//会話表示の時の一文字のサイズ

#define STRING_TALK				(4)
#define FLAG_CONTINUE			(7)					
#define DELAY_TIME				(6)
#define WAIT_TIME_AUTO			(100)
#define WAIT_TIME_SKIP			(3)

//矩形を合わせる
#define R_CONVERT_PLACE			(16)		//矩形番号を合わせる数
#define R_CONVERT_CHARANAME		(6)			//矩形番号を合わせる数
#define CONVERT_FADE			(3)			//フェード左右を合わせる数
#define CONVERT_REV				(20.f)		//反転したときに絵が切れないように
#define CONVERT_REV_ROZE		(100.f)		//クララ用
#define T_HEIGHT				(500.0f)	//キャラ絵のサイズ
#define T_WIDE					(350.0f)	//〃

#define COMAND_STRING_F_OUT		(19)		//PLACE:※:FADEOUT:STOPで19文字　　※(場所)
//#define COMAND_STRING_F_IN		(18)		//PLACE:※:FADEIN:STOP で18文字　　※(場所)

//描画位置
#define TALK_POS_X				(80)				//会話の描画開始位置X座標
#define TALK_POS_X2				(740)				//会話の描画終了位置X座標
#define TALK_POS_Y				(425)				//会話の描画開始位置Y座標
#define TALK_POS_Y2				(560)				//会話の描画終了位置Y座標
#define TALK_SPACE				(15)				//一文一文の間隔
#define NEXTICON_X				(700.0f)
#define NEXTICON_Y				(510.0f)

#define POS_BG_ADVETURE_X		(400.0f)
#define POS_BG_ADVETURE_Y		(300.0f)
#define POS_CHARA_X				(-60.0f)
#define POS_CHARA_Y				(100.0f)
#define POS_CHARA2_X			(510.0f)
#define POS_CHARA2_Y			(100.0f)
#define POS_CONSOR_X			(20.0f)
#define POS_CONSOR_Y			(20.0f)
#define POS_MSGWINDOW_X			(400.0f)
#define POS_MSGWINDOW_Y			(500.0f)
#define POS_BLACK_X				(405.0f)
#define POS_BLACK_Y				(490.0f)

#define POS_NOWPLACE_X			(160.0f)
#define POS_NOWPLACE_Y			(40.0f)
#define POS_CHARANAME_X			(50.0f)
#define POS_CHARANAME_Y			(370.0f)

#define POS_CHARA1_STOP			-(T_WIDE + POS_CHARA_X + CONVERT_REV)
#define POS_CHARA2_STOP			 (T_WIDE + POS_CHARA_X + CONVERT_REV)

enum POS
{
	LEFT,
	RIGHT,
};


enum TEXTURE_ADV		//TEXTUREの番号
{	
	T_BG_BEDROOM,
	T_BG_LIVING_HIRU,
	T_BG_LIVING_NIGHT,
	T_BG_LIVING_DIE,
	T_BG_CLASSROOM,
	T_BG_BACKYARD,
	T_BG_WASTELAND,
	T_BG_BLOOD,
	T_BG_FLASH,

	T_MAX_BG,

	T_CHARA_VAN = T_MAX_BG,
	T_CHARA_CULALA,
	T_CHARA_ROZETTA,
	T_CHARA_RIDDLE,
	T_CHARA_ZION_1,
	T_CHARA_ZION_2,
	T_CHARA_RIO_1,
	T_CHARA_RIO_2,
	T_CHARA_MAGNA_1,

	T_MAX_CHARA,
	MAX_CHARA = (T_MAX_CHARA - T_MAX_BG),
 
	T_CONSOR_ADV = T_MAX_CHARA,
	T_BLACK,
	T_POWER,
	
	T_MAX_ADV,
};

enum RECT_ADV			//矩形の番号
{
	R_BG_ADV,			//背景
	R_CHARA_FACE1,		//1.通常 6.驚き
	R_CHARA_FACE2,		//2.怒   7.困り
	R_CHARA_FACE3,		//3.哀   8.焦り
	R_CHARA_FACE4,		//4.楽   9.呆れ
	R_CHARA_FACE5,		//5.喜   10.(仮)

	MAX_KINDFACE,

	//キャラ名
	R_NAME_CULIS = MAX_KINDFACE,		//クリス
	R_NAME_VAN,							//ヴァン
	R_NAME_CULALA,						//クララ
	R_NAME_RIZETTE,						//ロゼッタ
	R_NAME_RIDDLE,						//???
	R_NAME_FATHER,						//父
	R_NAME_MATHER,						//母
	R_NAME_XION,						//シオン
	R_NAME_RIO,							//リオ
	R_NAME_MAGNA,						//マグナ

	R_MAX_CHARANAME,
	MAX_CHARANAME = (R_MAX_CHARANAME - MAX_KINDFACE),

	//現在地名
	R_PLACE_TEARENTE = R_MAX_CHARANAME,	//テアレンテの街
	DUMMY1,
	DUMMY2,
	DUMMY3,
	R_PLACE_CLASSROOM,	//教室
	R_PLACE_BACKYARD,	//裏庭
	R_PLACE_WASTELAND,	//荒野

	R_MAX_PLACENAME,
	MAX_PLACENAME = (R_MAX_PLACENAME - R_MAX_CHARANAME),

	//コンソ系
	R_CONSOR_PLACE = R_MAX_PLACENAME,		//現在地の
	R_CONSOR_MSGWINDOW,	//メッセージウィンドウ
	R_BLACK,			//文字を見やすくするための
	R_ROZE1,			
	R_ROZE2,			
	R_ROZE3,
	R_NEXTICON_1,
	R_NEXTICON_2,
	R_NEXTICON_3,
	R_NEXTICON_4,

	R_MAX_ADV,		
};

enum SCRIPT_KIND		//スクリプトに与えるデータの種類
{
	S_KIND_BG,			//背景のスクリプト設定	
	S_KIND_NOWPLACE,	//『現在地』の〃
	S_KIND_CHARANAME,	//キャラ名の〃
	S_KIND_CHARA_LEFT,	//キャラの種類左側〃
	S_KIND_CHARA_RIGHT,	//キャラの種類右側〃

	KIND_MAX,
};

enum FADE_CHARAPOS		//フェードさせるキャラ位置
{
	CHARA_LEFT,
	CHARA_RIGHT,

	MAX_CHARAPOS,
};

enum CHARANAME
{
	NAME_CULIS,					//クリス
	NAME_VAN,					//ヴァン
	NAME_CULALA,				//クララ
	NAME_RIZETTE,				//ロゼッタ
	NAME_RIDDLE,				//???
	NAME_FATHER,				//父
	NAME_MATHER,				//母
	NAME_XION,					//シオン
	NAME_RIO,					//リオ
	NAME_MAGNA,					//マグナ

	MAX_CHARNAME,
};