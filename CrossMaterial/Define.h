#pragma once

/************************************************************************************
 *																					*
 *	役割：ゲーム全体のdefineの定義													*
 *																					*
 *	説明：																			*
 *																					*
 *	作成日：2008年 12月 5日															*
 *																					*
 *	更新日：2008年 2月 20日															*
 *													by	三上　亘　その他			*
 *																					*
 ************************************************************************************/

#define DEBUG


#define MAX_STRING	( 64)		//ファイルの最大文字数を指定	
#define MAX_ARGB	(255) 	
#define	MAX_ALPHA	(255)		//アルファ値の最大


enum SCENE_NUM		//シーンの番号
{
	LOGO,			//ロゴ
	TITLE,			//タイトル
	PROLOGUE,		//プロローグ
	ADV_SCENE,		//アドベンチャーパート
	BATTLE_SCENE,	//バトルパート
	GAMEOVER,		//ゲームオーバー
	ENDING,

	MAX_SCENE,
};

//ADV内シーン
enum TEXT_STORY
{
	TEXT_PROLOGUE,							//プロローグ
	TEXT_STORY3_1,							//第三話(1)
	TEXT_STORY3_2,							//第三話(2)
	TEXT_STORY3_3,							//第三話(3)
	TEXT_BATTLE_BEFORE,						//戦闘前のシーン
	TEXT_EPILOGUE,							//エピローグ
	TEXT_ENDING_1,							//エンディング(スタッフロールなど)

	MAX_TEXTNAME,
};

//プロローグ内シーン
enum SCENE_PROLOGUE
{
	SCENE_WORLD1,						//世界観説明1
	SCENE_WORLD2,						//世界観説明2(細かい紹介)
	SCENE_PLOT,							//ADVのプロローグが終わった後。本編へ繋げるあらすじシーン
};

enum KEY_TYPE	//キー情報を判断する。
{
	NO_PUSH,	
	UP_PUSH,
	DOWN_PUSH,
	LEFT_PUSH,
	RIGHT_PUSH,
	UP_PRESS,
	DOWN_PRESS,
	LEFT_PRESS,
	RIGHT_PRESS,
	Z_PUSH,
	X_PUSH,
	A_PUSH,
	C_PUSH,
	S_PUSH,

	KEY_MAX,
};
