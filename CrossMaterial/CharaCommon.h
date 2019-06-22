#pragma once
/************************************************************************************
 *																					*
 *	役割：全キャラに共通した部分を一括して管理する。								*
 *																					*
 *	説明：全キャラの共通部分を管理する。											*
 *																					*
 *	作成日：2008年11月 8日															*
 *																					*
 *	更新日：2008年月 日																*
 *													by 三上　亘						*
 *																					*
 ************************************************************************************/
/*================================
	
		INCLUDEたち

=================================*/
#include "D_Battle.h"
#include "DirectGraphics.h"
#include <stdio.h>

/*================================
	
		Defineたち

=================================*/
enum MATERIAL_ATTRIBUTE		//マテリアルの属性
{
	SALAMANDER,				//火属性
	UNDINE,					//水属性
	SYLPH,					//風属性
	GNOME,					//土属性
};

/*================================
	
		structたち

=================================*/
struct CharaData_status
{
	//キャラ共通のもの(敵も味方も)ステータスの名前たちはIDにて判定し描画を切り替える
	//セーブする場合は各保存用の構造体を用意してそれに入れてください。
	int	 m_id;				//キャラID	
	int	 m_atk;				//攻撃力
	int  m_def;				//防御力
	int  m_mag;				//魔法攻撃力
	int  m_res;				//魔法抵抗力
	int  m_mg;				//現時点でのマテリアルゲージ（超必殺技に必要なゲージ）
	int  m_maxmg;			//最大マテリアルゲージ（超必殺技に必要なゲージ）
	int  m_agl;				//回避力
	int  m_dex;				//命中率
	int  m_hp;				//HP
	int	 m_maxhp;			//最大HP	
	int  m_ap;				//AP(行動力)
	int	 m_maxap;			//最大AP	
	int  m_ap_r;			//1ターンAP回復量
	int  m_mov;				//移動力
	int  m_atkrange;		//攻撃範囲
	int  m_luk;				//クリティカル率に影響
	int  m_mp;				//MP所持量
	int  m_attribute;		//敵の属性の種類判別（味方でいうところのマテリアル属性）
	int  m_skill_range1;	//特殊攻撃をする際の範囲1
	int  m_skill_range2;	//特殊攻撃をする際の範囲2
};		 

typedef struct CharaData_battle			//戦闘中にのみ必要なもの
{
	int  m_id;					//キャラのID
	int  m_pos_chara_x;			//キャラの位置情報X
	int  m_pos_chara_y;			//キャラの位置情報Y
	int  m_direction;			//キャラ向き(決定前)
	int  m_direction_enter;		//キャラ向き(選択時)
	int  m_correct;				//パラメータ補正の値（回復技のとき使用）
	int  m_kind_skillattack;	//特殊攻撃種類
	int  m_mp_battle;			//キャラの持つMP量とは別に、『その戦闘中に』獲得した値を保存
	bool m_action_end;			//行動終了しているか否かの判定
	bool m_battle_impossible;	//戦闘不能フラグ
}CharaData_battle;

//キャラクラス(キャラの基底クラス)
class C_CharaCommon
{
protected:
	CharaData_status charadata_status;
	CharaData_battle charadata_battle;
public:
	C_CharaCommon(void);
	virtual void Init() = 0;
	virtual void Draw() = 0;
	~C_CharaCommon(void);
	
	void SetCharaState(CharaData_status status) { charadata_status = status;}
	void SetCharaStateBattle(CharaData_battle status_battle) { charadata_battle = status_battle;}

	CharaData_status GetCharaState() { return charadata_status;}
	CharaData_battle GetCharaStateBattle() { return charadata_battle;}



};
