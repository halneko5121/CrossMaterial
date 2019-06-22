#pragma once

/************************************************************************************
 *																					*
 *	役割：ステージの管理をします													*
 *																					*
 *	説明：MAPTIP・field関係の管理													*
 *																					*
 *	作成日：2008年 11月 24日														*
 *																					*
 *	更新日：2008年 月日																*
 *													by	平野　努					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include <stdio.h>
#include <string.h>

#include "D_Battle.h"

#include "DirectGraphics.h"
#include "Define.h"
/*================================
	
		Define

=================================*/
#define MAX_TEXTURE_STAGE		(20)			//テクスチャーの数

#define TEXTURE_SIZE_X			(512.0f)		//統合ファイルのサイズX
#define TEXTURE_SIZE_Y			(512.0f)		//統合ファイルのサイズY

#define SLIDE_X					(50)			//ｘをスライドさせる量
#define SLIDE_Y					(25)			//ｙをスライドさせる量

#define CENTER_POSITION_X			(400.0f)	//MAPTIPの初期配置位置X
#define CENTER_POSITION_Y		(300.0f)		//MAPTIPの初期配置位置Y

#define MAX_MAPTIP				(400)			//MAPTIPの総数
#define BLANK					(0)

enum MAPTIP_ID				//どのMAPTIPかを判断
{
	MAPTIP_BLANK,
	MAPTIP_CACTUS1,		//サボテン1
	MAPTIP_CACTUS2,			//サボテン2
	MAPTIP_ROCK1,			//岩石1
	MAPTIP_ROCK2,			//岩石2
	MAPTIP_SAND1,			//砂地1
	MAPTIP_SAND2,			//砂地2
	MAPTIP_SAND3,			//砂地3
	MAPTIP_SAND4,			//砂地4
	MAPTIP_GREEN1,			//草地1
	MAPTIP_GREEN2,			//草地1
	MAPTIP_GREEN3,			//草地1
	MAPTIP_GREEN4,			//草地1
	MAPTIP_CHOICE,			//移動・攻撃可能範囲表示のMAPTIP
};

enum FLAG_STAGE				//MAPTIPの生成量を話数によって変更		
{				
	STAGE_FIRST,
	STAGE_SECOND,
	STAGE_LAST
};

enum FLAG_STORY				//何話目かの判断
{
	ACTION_CHOICE,			//行動可能範囲表示の時使用
	STORY_FIRST,			
	STORY_SECOND,
	STORY_LAST

};

enum UNIT_ID{
	U_BLANK_AREA	=  0,
	U_ZION			= 10,
	U_VAN			= 20,
	U_RIO			= 30,
	U_SAHAGIN1		= 40,
	U_SAHAGIN2		= 50,
	U_LIZARDMAN1	= 60,
	U_LIZARDMAN2	= 70,
	U_LIZARDMAN3	= 80,
	U_BOSS			= 90,
};

/*================================
	
		Struct

=================================*/


class C_Stage
{
private:
	//MAPTIP関係
	int maptip_wide;									//話数によってMAPTIPの生成を変更(横)	
	int maptip_length;									//話数によってMAPTIPの生成を変更(縦)
	
	FIELD_POS field[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];//MAPTIPのx座標y座標を保存
	//バトルフィールドの値を保存
	int field_maptip[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];
	int field_character[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];

	FIELD_POS field_pos[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];	//
	
	int maptip_x;										//どれだけ
	int maptip_y;											
	int flag_story;										//何話目か判断		

	int char_max;

	int area_distance;			//範囲を保存(distance 距離)
	int keep_id;
	//2/12追加(nisii)
	int keep_cmd;				//選ばれていたコマンドを保存

	int char_position_x_keep;	//キャラ位置をキープしておく(ｘ)
	int char_position_y_keep;	//上に同じ(ｙ)

	int area_info[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];		//移動可能位置を入れる

	int player_max;
	int enemy_max;
public:
	void Control(int * key);

	void FieldControl(int x,int y);		//マップチップの描画位置を決める

	void Draw();
	void Sound();						//サウンドの管理
	void Release();

	/************************************************************************************
	 *	説明	：MAPTIPの配列の数を話数に応じて決める									*
	 *	引数	：なし																	*
	 *	戻り値	：なし																	*
	 *													by	三上　亘					*
	 ************************************************************************************/
	void Init();						

	/************************************************************************************
	 *	説明	：//MAPTIPを配列にSETする。マップチップなどをTEXTから読み込み			*
	 *	引数	：なし																	*
	 *	戻り値	：なし																	*
	 *													by	三上　亘					*
	 ************************************************************************************/
	void SetMaptip();

	void AreaSeach(int char_position_x,int char_position_y,int unit_id,int distance,int char_commando);			//移動できるエリアを算出(仮)
	void AreaDeleat();				//移動できるエリアの初期化・消す

	int IdSeach(int x,int y);		//そのIDがどのキャラなのかを判別する

	int GameStateSeach();	//ゲームの状況(ゲームオーバー・ゲームクリア)を算出結果を出す
	
public:
	int GetMaptipXData()		{return maptip_x;}
	int GetMaptipYData()		{return maptip_y;}

	int GetFieldMaptipData(int x,int y)	{return field_maptip[x][y];}			//フィールドに何があるかを取得(各ポジション版)
	int GetFieldMaptipData(COORDINATE no)	{return field_maptip[no.x][no.y];}		//フィールドに何があるかを取得(構造体版)

	FIELD_POS GetFieldPositionData(int x,int y)	{return field[x][y];}		//フィールドの表示位置を取得(各ポジション版)
	FIELD_POS GetFieldPositionData(COORDINATE no)	{return field[no.x][no.y];}		//フィールドの表示位置を取得(構造体版)

	int GetAreaInfoData(int x,int y)	{return area_info[x][y];}				//各工程のエリアを取得

	int GetEnemyMax()	{return enemy_max;}
	void DecEnemy(int dec)		{enemy_max -= dec;}
	int GetPlayerMax()	{return player_max;}
	int GetCharMaxData()	{return char_max;}										//キャラの最大数を取得する

	int GetFieldCharacterData(int x,int y)	{return field_character[x][y];}	//フィールドにキャラがいるかを取得(各ポジション版)
	
	void SetFieldCharacterData(COORDINATE no,int data)	{field_character[no.x][no.y] = data;}	//キャラデータを更新(入れる)
	void SetFieldCharacterData(int x,int y,int data)	{field_character[x][y] = data;}
public:
	C_Stage(void);
	~C_Stage(void);
};

