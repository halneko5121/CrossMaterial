#include "CharaData_Enemy4.h"

C_CharaData_Enemy4::C_CharaData_Enemy4(void)
{
}

C_CharaData_Enemy4::~C_CharaData_Enemy4(void)
{
}

void C_CharaData_Enemy4::Init()
{
	charadata_status.m_id				= LIZARD2_ID;						//キャラID	
	charadata_status.m_atk				= STATE_LIZARD2_ATK;				//攻撃力								
	charadata_status.m_def				= STATE_LIZARD2_DEF;				//防御力								
	charadata_status.m_mag				= STATE_LIZARD2_MAG;				//魔法攻撃力							
	charadata_status.m_res				= STATE_LIZARD2_RES;				//魔法抵抗力							
	charadata_status.m_mg				= STATE_LIZARD2_MG;					//現時点でのマテリアルゲージ（超	
	charadata_status.m_maxmg			= STATE_LIZARD2_MAXMG;				//最大マテリアルゲージ（超必殺技	
	charadata_status.m_agl				= STATE_LIZARD2_AGL;				//回避力							
	charadata_status.m_dex				= STATE_LIZARD2_DEX;				//命中率							
	charadata_status.m_hp				= STATE_LIZARD2_HP;					//HP
	charadata_status.m_maxhp			= STATE_LIZARD2_MAXHP;				//最大HP	
	charadata_status.m_ap				= STATE_LIZARD2_AP;					//AP(残り行動力)
	charadata_status.m_maxap			= STATE_LIZARD2_MAXAP;				//最大AP	
	charadata_status.m_ap_r				= STATE_LIZARD2_AP_R;				//1ターンAP回復量
	charadata_status.m_mov				= STATE_LIZARD2_MOV;				//移動力
	charadata_status.m_atkrange			= STATE_LIZARD2_RANGE;				//攻撃範囲
	charadata_status.m_luk				= STATE_LIZARD2_LUK;				//クリティカル率に影響
	charadata_status.m_mp				= STATE_LIZARD2_MP;
	charadata_status.m_attribute		= SALAMANDER;
	charadata_status.m_skill_range1		= STATE_SPASE_RANGE;				//必殺技1の範囲
	charadata_status.m_skill_range2		= STATE_SPASE_RANGE;				//必殺技2の範囲

	charadata_battle.m_id				= LIZARD2_ID;						//キャラのID
	charadata_battle.m_pos_chara_x		= STATE_LIZARD2_X;					//キャラの位置情報X
	charadata_battle.m_pos_chara_y		= STATE_LIZARD2_Y;					//キャラの位置情報Y
	charadata_battle.m_direction		= STATE_LIZARD2_DIRECTION;			//キャラ向き(決定前)
	charadata_battle.m_direction_enter	= STATE_LIZARD2_DIRECTION_ENTER;	//キャラ向き(選択時)
	charadata_battle.m_correct			= STATE_LIZARD2_CORRECT;			//パラメータ補正の値（回復技のとき使用）
	charadata_battle.m_kind_skillattack	= STATE_LIZARD2_SKILLATTACK;		//特殊攻撃種類
	charadata_battle.m_mp_battle		= STATE_LIZARD2_MPGET;				//キャラの持つMP量とは別に、『その戦闘中に』獲得した値を保存
	charadata_battle.m_action_end		= false;							//行動終了しているか否かの判定
	charadata_battle.m_battle_impossible= false;
}
