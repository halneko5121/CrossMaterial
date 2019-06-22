#include "CharaData_Zion.h"


C_CharaData_Zion::C_CharaData_Zion(void)
{	 
}

C_CharaData_Zion::~C_CharaData_Zion(void)
{
}
void C_CharaData_Zion::Init()
{
	//第二話ができたりSAVEが作れたらSAVEDATAを代入するようにしないといけない
	charadata_status.m_id		= ZION_ID;				//キャラID	
	charadata_status.m_atk		= STATE_ZION_ATK;		//攻撃力								
	charadata_status.m_def		= STATE_ZION_DEF;		//防御力								
	charadata_status.m_mag		= STATE_ZION_MAG;		//魔法攻撃力							
	charadata_status.m_res		= STATE_ZION_RES;		//魔法抵抗力							
	charadata_status.m_mg		= STATE_ZION_MG;		//現時点でのマテリアルゲージ（超	
	charadata_status.m_maxmg	= STATE_ZION_MAXMG;	//最大マテリアルゲージ（超必殺技	
	charadata_status.m_agl		= STATE_ZION_AGL;		//回避力							
	charadata_status.m_dex		= STATE_ZION_DEX;		//命中率							
	charadata_status.m_hp		= STATE_ZION_HP;		//HP
	charadata_status.m_maxhp	= STATE_ZION_MAXHP;	//最大HP	
	charadata_status.m_ap		= STATE_ZION_AP;		//AP(残り行動力)
	charadata_status.m_maxap	= STATE_ZION_MAXAP;	//最大AP	
	charadata_status.m_ap_r		= STATE_ZION_AP_R;	//1ターンAP回復量
	charadata_status.m_mov		= STATE_ZION_MOV;		//移動力
	charadata_status.m_atkrange	= STATE_ZION_RANGE;		//攻撃範囲
	charadata_status.m_luk		= STATE_ZION_LUK;		//クリティカル率に影響
	charadata_status.m_mp		= STATE_ZION_MP;		//MP所持量
	charadata_status.m_skill_range1 = STATE_SPASE_RANGE;	//必殺技1の範囲
	charadata_status.m_skill_range2 = STATE_SPASE_RANGE;	//必殺技2の範囲

	charadata_battle.m_id				= ZION_ID;						//キャラのID
	charadata_battle.m_pos_chara_x		= STATE_ZION_X;					//キャラの位置情報X
	charadata_battle.m_pos_chara_y		= STATE_ZION_Y;					//キャラの位置情報Y
	charadata_battle.m_direction		= STATE_ZION_DIRECTION;			//キャラ向き(決定前)
	charadata_battle.m_direction_enter	= STATE_ZION_DIRECTION_ENTER;	//キャラ向き(選択時)
	charadata_battle.m_correct			= STATE_ZION_CORRECT;			//パラメータ補正の値（回復技のとき使用）
	charadata_battle.m_kind_skillattack	= STATE_ZION_SKILLATTACK;		//特殊攻撃種類
	charadata_battle.m_mp_battle		= STATE_ZION_MPGET;				//キャラの持つMP量とは別に、『その戦闘中に』獲得した値を保存
	charadata_battle.m_action_end		= false;	
	charadata_battle.m_battle_impossible= false;
}
void C_CharaData_Zion::Draw()
{	

}