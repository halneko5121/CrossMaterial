#pragma once

/************************************************************************************
 *																					*
 *	役割：BATTLEパートを管理します													*
 *																					*
 *	説明：BATTLEパートのControlとRenderがあります									*
 *																					*
 *	作成日：2008年 11月21日															*
 *																					*
 *	更新日：2008年 月日																*
 *													by	平野　努					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include<math.h>

#include "Scene.h"
#include "Stage.h"

#include "D_Battle.h"
#include "Define.h"

#include "DirectGraphics.h"

#include "Calculate.h"	//ダメージ計算クラス追加2/12(nisii)

#include "CharaData_Zion.h"
#include "CharaData_Van.h"
#include "CharaData_Rio.h"
#include "CharaData_Enemy1.h"
#include "CharaData_Enemy2.h"
#include "CharaData_Enemy3.h"
#include "CharaData_Enemy4.h"
#include "CharaData_Boss.h"

#include <cstdlib>
#include <new>
#include <memory>

using namespace std;

#include <crtdbg.h>
// crtdbg.h をインクルードしたあとに _CRTDBG_MAP_ALLOC を定義してやる
#define _CRTDBG_MAP_ALLOC
#define new  ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

/*================================
	
		Define

=================================*/
#define MAX_TEXTURE_BATTLE	(20)		//テクスチャーの数
#define TEXTURE_SIZE		(1024.f)	//テクスチャのサイズ
#define TEXTURE_SIZE2		(512.f)		//テクスチャのサイズ②

#define SIMPLEMAPTIP_X	(460.f)	//簡易ステータスX中心
#define SIMPLEMAPTIP_Y	(510.f)	//簡易ステータスY中心

#define SIMPLE_HAM_X	(138.f)	//簡易ステータス｢HP｣､｢AP｣､｢MG｣のＸの中心
#define SIMPLE_HAM_Y	(482.f)	//簡易ステータス｢HP｣､｢AP｣､｢MG｣のＹの中心

#define SIMPLE_AD_X	(280.f)	//簡易ステータス｢ATK｣､｢DEF｣のＸの中心
#define SIMPLE_AD_Y	(530.f)	//簡易ステータス｢ATK｣､｢DEF｣のＹの中心

#define SIMPLE_MR_X	(430.f)	//簡易ステータス｢MAG｣､｢RES｣のＸの中心
#define SIMPLE_MR_Y	(530.f)	//簡易ステータス｢MAG｣､｢RES｣のＹの中心

#define SIMPLE_INCREASE_Y	(22.5f)	//簡易ステータス｢DEF｣､｢RES｣の増加量

#define SIMPLE_CHARA_X		( 77.f)		//簡易ステータスのキャラ絵のX中心
#define SIMPLE_CHARA_Y		(526.f)		//簡易ステータスのキャラ絵のY中心

typedef struct _GetBattleData{	//戦闘用に必要なデータ
	CharaData_status status;	//計算用ステータス
	int direction;				//向き
}GetBattleData;

typedef struct _GetBattleDataVan{	//戦闘用に必要なデータ(ヴァン仕様)
	CharaData_status status;
	int direction;
	double hitDamagevan;
}GetBattleDataVan;

typedef struct _DrawBattleData{
	int damage;
	int move;
	bool act;
	float posX;
	float posY;
}DrawBattleData;
class C_Battle :	public C_Scene
{
private:
	C_Control *key;
	C_Stage *stage;

	GetBattleData getPlData;			//プレイヤーのデータ
	GetBattleData getEnemyData;			//敵のデータ

	double hitDamage;					//受けたダメージ
	DrawBattleData drawBattleData[3];	//描画用データ
	DrawBattleData drawBattleVanData[12][3];//ヴァン特殊攻撃時の描画用データ
	DrawBattleData drawSpZionData[17][3];	//シオン超必殺技の描画用データ
	bool hitInit;						//ダメージセット用フラグ
	bool battleDrawEnd;					//すべての描画が終わったら

	double recovery_point;

	COORDINATE keep_skillarea[12];

	bool AtkEfStart;

	GetBattleDataVan getEnemydatavan[12];
	GetBattleDataVan getenemydatazion[17];

	//追加2/13(nisii)
	bool charaAttack;			//キャラアタック時
	int  charaAttackCnt;		//キャラアタックカウント
	int  keepAttackCnt;			//最初のカウントを保存
	int atkDeray;
	static const int  deray[8][4];			//攻撃のディレイ
	//追加ここまで
	bool charaSkillatk;			//キャラスキル攻撃時
	bool SkillEfStart;

	static const int deray_skill[4];	//特殊攻撃(地砕塵のディレイ)
	static const int deray_wait[8][4];

	int charaAttackEfCnt;

	bool flag_battle_status_draw;
	int cnt_draw;

	C_Calculate *damegeCulc;	//ダメージ計算クラス追加2/12(nisii)
	C_CharaData_Zion	*zion;
	C_CharaData_Van		*van;
	C_CharaData_Rio		*rio;
	C_CharaData_Enemy1	*enemy1;
	C_CharaData_Enemy2	*enemy2;
	C_CharaData_Enemy3	*enemy3;
	C_CharaData_Enemy4	*enemy4;
	C_CharaData_Boss	*boss;

	CharaData_status *status;
	CharaData_battle *status_battle;

	bool flag_zion_num_end;

	bool flag_sp_draw_off;

	int use_texture;			//使用する画像の枚数を格納する。

	int time_cnt;				//時間操作をする時使用
	int flag_turn;				//PLAYER PHASE・ENEMY PHASEを管理

	int phase_shift;			//PLAYER PHASE・ENEMY PHASEを描画する時矩形の切り替えをする
	int flag_turn_player;		//PLAYER TURN中キャラ　シオン・ヴァン・リオを管理
	int flag_turn_enemy;		//ENEMY  TURN中　敵						   を管理

	int flag_any_end;			//簡単な段階を知らせるフラグ(例:バトルでのカーソル移動・コマンド移動など)
	int battle_change;			//バトル　開始前・戦闘中・終了後を管理
	int flag_char_commando;		//コマンドを選択しているか判断(移動しようとＺを押してなど)

	DWORD area_shift;			//エリアの切り替え(移動エリアの場合と攻撃エリアの場合の色をかえる)

	int x_temporarily;			//仮
	int y_temporarily;			//仮
	int locate_cursor_commando;	//カーソルの位置(コマンド)
	float fade;					//PLAYER TURNを表示時に使用
	int flag_change_keep;		//現在どのシーンのカーソル操作をやっているかを保存する

	int flag_char_selected[3];
	int keep_field_id[10];		//43などフィールド上でのIDを保存する(キャラ別)

	COORDINATE locate_cursor_field;	//カーソルの位置(フィールド)
	COORDINATE keep_posi;
	COORDINATE deleat_posi;

	int material_set[3];

	int cnt_death;

	int cursor_color;

	int direction;

	int keep_char_select;		//キャラのID保存(シオンなのかヴァンなのかサハギンなのか)
	int keep_id;				//キャラのID保存(サハギンの１体目なのかシオンなのかリザードマンの２体目なのかなど)

	int keep_direction;

	int draw_direction;			//向きを保存する

	int flag_atk;
	int flag_skill;

	double attribute_advantage;

	int atk_draw;
	//ステータス描画に使用
	int font_center_x;	//DrawCCの固定フォントのＸ座標の中心
	int add_font_canter_y;	//DrawCCの固定フォントのＹ座標の中心の合計
	int font_center_y;	//DrawCCの固定フォントのＹ座標の中心	
	int font_increase_y;	//Y座標の固定フォントの中心の矩形増加量
	int font_standard;	//固定フォントの差する時の基準
	int num_center_x;	//DrawCCの数字のＸ座標の中心
	int add_num_canter_y;	//DrawCCの数字のＹ座標の中心の合計
	int num_center_y;	//DrawCCの数字のＹ座標の中心	
	int num_increase_y;	//Y座標の数字のフォントの中心の矩形増加量
	int num_standard;	//数字の差する時の基準
	int indicate;		//表示キャラ
	int mrx_increase_left;//マトリクスleft矩形データの増加量
	int mrx_increase_right;//マトリクスright矩形データの増加量
	int mrx_center_x;	//文字の大きさによって中心を合わせる
	int mrl_increase_left;//マテリアル名left矩形データの増加量
	int mrl_increase_right;//マテリアル名right矩形データの増加量
	int mrl_center_x;	//文字の大きさによって中心を合わせる
	int set_material;	//セットしているマテリアル
	int mrl_magic_1;	//マテリアル技名１
	int magic1_center_x;//技名x中心座標
	int mrl_detail_1;	//マテリアル技１の詳細
	int mrl_detail1_center_x;	//マテリアル詳細技1の中心座標
	int mrl_magic_2;	//マテリアル技名２
	int magic2_center_x;//技名x中心座標
	int mrl_detail_2;	//マテリアル技２の詳細
	int mrl_detail2_center_x;	//マテリアル詳細技1の中心座標
	int chara_no;		//キャラクターNo.
	int flag_status_draw;

	int flag_geme_end;
	double fade2;
	int fade3;
	int cursor_locate_x;
	double cursor_locate_y;

	//int topography_effect;
	int flag_simple_chara;		//簡易キャラクターステータス描画
	int chara_id;				//キャラクターのid
	int landform;				//地形の情報
	int simple_num_x;		//簡易ステータスxの数字の位置
	int simple_num_y;		//簡易ステータスyの数字の位置
	int sim_num_standard;	//基準
	int simple_chara_name;
	int chara_now_area;		//キャラクターが居るマップチップ情報
	double test_point;		//値が帰ってるか確認テスト

	int locate_cursor_skill;
	int cut_out;
	int flag_skill_ef[3];
	int keep_skill_ef_id[3];
	int charaRecoveryCnt;
	int charaSkillCnt;

	int sound_in;

	int flag_field_show;	//バトル開始前にフィールド全体を見せる

	float status_enemy;

	int charaWaitZion;		//シオンの待機描画切り替えをする
	int charaWaitVan;		//ヴァンの待機描画切り替えをする
	int charaWaitRio;		//リオの待機描画切り替えをする
	int charaWaitSahagin1;	//サハギン１の待機描画切り替えをする
	int charaWaitSahagin2;	//サハギン２の待機描画切り替えをする
	int charaWaitLizardman1;//リザードマン１の待機描画切り替えをする
	int charaWaitLizardman2;//リザードマン２の待機描画切り替えをする
	int charaWaitBoss;		//フードの男の待機描画切り替えをする

	int fade_in_out;

	int cnt_turn;
	bool flag_use_skill[3];

	float telop;
	float telop2;
	int flag_material_seted[3];
	int flag_sp_extra;
	bool flag_sp_extra_draw;
	int fade_color;
	bool fade_end;
	bool sp_end_extra;
	//奥義用
	int cnt_ex_alltime;	//奥義中の時間経過をカウント
	int fade_black;		//ブラックアウト時カラーを黒くするのに使用
	int fade_out_black;	//ブラックアウト時のフェードアウトなどに使用
	bool flag_black;	//ブラックアウトが完了した時に使うフラグ
	
	//ボイス反映用
	bool flag_voice;
	int  voice_change;
	bool flag_voice_attack;
	int  voice_change_attack;
	bool flag_sound_ef;
	int  sound_ef_change_attack;
	bool flag_voice_ex;
	int  voice_change_ex;
	bool flag_sound_ex;
	int  sound_ef_change_ex;
	bool flag_sound_sp;
	int  sound_ef_change_sp;
	bool flag_sound_in;
	bool flag_sound_cursor;
	bool flag_voice_setumei;
	int  voice_change_setumei;

	//AI用
	int selectionId;
	int flag_enemy_atk;
	int enemyAttackCnt;
	//アドベンチャー
	int m_key_cnt;
public:
	C_Battle(C_DGraphics *in_graphics);
	void Control(int* key);
	void Draw();
	void Sound();						//サウンドの管理
	void Release();
	void Init();

	void AttackEffectDraw(int i,int j);	//攻撃時のエフェクト描画


	void BattleStatusMake();			//バトルで使うステータスを生成
	void BattleMaterial(int* key);		//バトル開始前マテリアルセット
	void BattleCondition(int* key);		//バトル開始前
	void BattleCombat(int* key);		//バトル中
	void BattleCombatSystem(int* key);	//バトル中のコマンドなどの処理
	void BattleClear(int* key);			//バトルクリア後

	void DamegeExtra();
	void DamegeExtraZion();

	//追加2/12(nisii)
	void BattleProcess(void);			//バトル中の処理（戦闘など）
	void BattleDataSet(void);			//交戦中の敵とプレイヤーのデータをセット
	void BattleEndProcess(void);		//バトル終了処理
	void BattleProcessDraw(void);		//バトル中の描画
	float BattleDrawConvert(int id , bool x = false);		//バトル中の描画位置修正
	//追加ここまで
	void BattleSkill(int* key);			//特殊攻撃時スキル選択
	void SkillProcess();				//特殊攻撃の処理
	void BattleSkillDraw();				//特殊攻撃時描画
	void SkillDetailDraw();				//特殊攻撃を選んだ際の描画
	void BattleDataSetVan();			//ヴァンの特殊攻撃の効果範囲が違うため
	void BattleDataSetZion();
	void BattleEndProcessVan();			//ヴァンは範囲でしぬため
	void CharaSkillDraw(int i,int j);				//特殊攻撃・回復などの描画

	//敵AI
	void EnemyAi(int* key);
	void EnemyMove();
	void EnemyAttack();
	void EnemyBattleProcess();
	void EnemyBattleDataSet();
	//
	void BattleMaterialDraw();			//バトル開始前マテリアルセット描画
	void BattleConditionDraw();			//バトル開始前描画
	void BattleCombatDraw();			//バトル中描画
	void BattleClearDraw();				//バトルクリア後描画

	void PlayerTurn(int* key);					//PLAYER TURN時の処理まとめ
	void EnemyTurn(int* key);					//ENEMY TURN時の処理まとめ

	void FieldDraw();

	void CursorControlField(int* key);	//カーソル操作(現在の縦，現在の横，フィールド情報)
	void CursorControl(int* key,int max_cursor);	//カーソル操作(個数,どのシーンなのか,Zキーが押されたかどうかを判定する変数)

	void StatusBackGroundDraw();//ステータスの背景
	void StatusFontDraw();		//フォントの描画
	void StatusDataDraw();		//数値の描画(進むことによって変化する)
	void StatusCharaDraw();		//キャラ描画（属性、マトリクス、マテリアル）
	void SimpleStatusDraw();	//簡易ステータスの地形描画
	void CheckField();			//マップチップによって描画処理
	void SimpleCharaStatusDraw();	//簡易ステータスのキャラデータの描画
	void SimpleDrawFlag();			//簡易ステータスのキャラクターのＩＤによる処理
	void SimpleCharaDraw();			//簡易ステータスのキャラ描画

	void ApRecovery();	//ターンが終了したらAPを回復させる

	// ユニットデータ
	void SetStatus();		//各キャラステータスをステータス構造体配列に格納する
	void InitStatus();		//各キャラステータスを初期化する

	bool GetTurnEndflag();	//行動終了しているかのフラグ

	void ChageActEnd();		//ターンが変わる際行動終了フラグを戻す

	void SetDamageVan();

	void CursorSelectChara(int* key);
	void CharSeach(int keep_cursor_posi_id,bool select_player);

	bool SelectedCommando();

	//奥義
	void BattleSpExtra();		//奥義処理
	void BattleSpExtradraw();	//奥義描画(共通部分)
	void SpExZionDraw();		//奥義描画(シオン)
	void SpExVanDraw();			//奥義描画(ヴァン)
	void SpExRioDraw();			//奥義描画(リオ)

public:
	int StatusSeachPosi(int x,int y);	//座標からその位置にいるキャラのステータスを探す(各位置版
	int StatusSeachPosi(COORDINATE no);	//座標からその位置にいるキャラのステータスを探す(構造体版

	int StatusSeachId(int id);		//ステータスバトルをIDから検索する

	double TopographyEffect();			//地形効果の倍率を返す

	int UseMoveAP();				//キャラクターの移動消費APの値を返す
	
	int UseNormalAttackAP();		//キャラクターの通常攻撃消費APの値を返す。

	int UseSpecialAP1();		//キャラクターの特殊攻撃消費APの値を返す

	int UseSpecialAP2();		//キャラクターの特殊効果消費APの値を返す

	int UseDefenseAP();				//キャラクターの防御消費APの値を返す

	void SahaginAITEST(int* key);			//サハギンのAIテスト

	void SetDamage(int id, int damage) { status[ id ].m_hp -= damage; }
	void SetRecovery(int id,int recovery);
	bool DeathCheck(int id)	{ return status[ id ].m_hp <= 0; }
	void InitBattleData();

	void CursorUp();
	void CursorDown();
	void CursorLeft();
	void CursorRight();
public:
	~C_Battle();
};
