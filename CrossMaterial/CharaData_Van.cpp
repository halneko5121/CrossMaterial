#include "CharaData_van.h"


C_CharaData_Van::C_CharaData_Van(void)
{
}

C_CharaData_Van::~C_CharaData_Van(void)
{
}
void C_CharaData_Van::Init()
{


	charadata_status.m_id		= VAN_ID;		//キャラID	
	charadata_status.m_atk		= STATE_VAN_ATK;		//攻撃力				
	charadata_status.m_def		= STATE_VAN_DEF;		//防御力				
	charadata_status.m_mag		= STATE_VAN_MAG;		//魔法攻撃力			
	charadata_status.m_res		= STATE_VAN_RES;		//魔法抵抗力			
	charadata_status.m_mg		= STATE_VAN_MG;		//現時点でのマテリアルゲー
	charadata_status.m_maxmg	= STATE_VAN_MAXMG;	//最大マテリアルゲージ（超
	charadata_status.m_agl		= STATE_VAN_AGL;		//回避力				
	charadata_status.m_dex		= STATE_VAN_DEX;		//命中率				
	charadata_status.m_hp		= STATE_VAN_HP;		//HP
	charadata_status.m_maxhp	= STATE_VAN_MAXHP;	//最大HP	
	charadata_status.m_ap		= STATE_VAN_AP;		//AP(残り行動力)
	charadata_status.m_maxap	= STATE_VAN_MAXAP;	//最大AP	
	charadata_status.m_ap_r		= STATE_VAN_AP_R;		//1ターンAP回復量
	charadata_status.m_mov		= STATE_VAN_MOV;		//移動力
	charadata_status.m_atkrange	= STATE_VAN_RANGE;		//攻撃範囲
	charadata_status.m_luk		= STATE_VAN_LUK;		//クリティカル率に影響
	charadata_status.m_mp		= STATE_VAN_MP;		//MP所持量
	charadata_status.m_skill_range1 = STATE_SPASE_RANGE;	//必殺技1の範囲
	charadata_status.m_skill_range2 = STATE_SPASE_RANGE;	//必殺技2の範囲

	charadata_battle.m_id				= VAN_ID;						//キャラのID
	charadata_battle.m_pos_chara_x		= STATE_VAN_X;					//キャラの位置情報X
	charadata_battle.m_pos_chara_y		= STATE_VAN_Y;					//キャラの位置情報Y
	charadata_battle.m_direction		= STATE_VAN_DIRECTION;			//キャラ向き(決定前)
	charadata_battle.m_direction_enter	= STATE_VAN_DIRECTION_ENTER;	//キャラ向き(選択時)
	charadata_battle.m_correct			= STATE_VAN_CORRECT;			//パラメータ補正の値（回復技のとき使用）
	charadata_battle.m_kind_skillattack	= STATE_VAN_SKILLATTACK;		//特殊攻撃種類
	charadata_battle.m_mp_battle		= STATE_VAN_MPGET;				//キャラの持つMP量とは別に、『その戦闘中に』獲得した値を保存
	charadata_battle.m_action_end		= false;							//行動終了しているか否かの判定
	charadata_battle.m_battle_impossible= false;
}

void C_CharaData_Van::Draw()
{
}