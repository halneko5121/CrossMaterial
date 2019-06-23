#include "CharaData_Boss.h"

C_CharaData_Boss::C_CharaData_Boss(void)
{
}

C_CharaData_Boss::~C_CharaData_Boss(void)
{
}

void C_CharaData_Boss::Init()
{
	charadata_status.m_id				= LIZARD3_ID;						//�L����ID	
	charadata_status.m_atk				= STATE_LIZARD3_ATK;				//�U����								
	charadata_status.m_def				= STATE_LIZARD3_DEF;				//�h���								
	charadata_status.m_mag				= STATE_LIZARD3_MAG;				//���@�U����							
	charadata_status.m_res				= STATE_LIZARD3_RES;				//���@��R��							
	charadata_status.m_mg				= STATE_LIZARD3_MG;					//�����_�ł̃}�e���A���Q�[�W�i��	
	charadata_status.m_maxmg			= STATE_LIZARD3_MAXMG;				//�ő�}�e���A���Q�[�W�i���K�E�Z	
	charadata_status.m_agl				= STATE_LIZARD3_AGL;				//����							
	charadata_status.m_dex				= STATE_LIZARD3_DEX;				//������							
	charadata_status.m_hp				= STATE_LIZARD3_HP;					//HP
	charadata_status.m_maxhp			= STATE_LIZARD3_MAXHP;				//�ő�HP	
	charadata_status.m_ap				= STATE_LIZARD3_AP;					//AP(�c��s����)
	charadata_status.m_maxap			= STATE_LIZARD3_MAXAP;				//�ő�AP	
	charadata_status.m_ap_r				= STATE_LIZARD3_AP_R;				//1�^�[��AP�񕜗�
	charadata_status.m_mov				= STATE_LIZARD3_MOV;				//�ړ���
	charadata_status.m_atkrange			= STATE_LIZARD3_RANGE;				//�U���͈�
	charadata_status.m_luk				= STATE_LIZARD3_LUK;				//�N���e�B�J�����ɉe��
	charadata_status.m_mp				= STATE_LIZARD3_MP;					//MP������
	charadata_status.m_attribute		= SALAMANDER;
	charadata_status.m_skill_range1		= STATE_SPASE_RANGE;				//�K�E�Z1�͈̔�
	charadata_status.m_skill_range2		= STATE_SPASE_RANGE;				//�K�E�Z2�͈̔�

	charadata_battle.m_id				= LIZARD3_ID;						//�L������ID
	charadata_battle.m_pos_chara_x		= STATE_LIZARD3_X;					//�L�����̈ʒu���X
	charadata_battle.m_pos_chara_y		= STATE_LIZARD3_Y;					//�L�����̈ʒu���Y
	charadata_battle.m_direction		= STATE_LIZARD3_DIRECTION;			//�L��������(����O)
	charadata_battle.m_direction_enter	= STATE_LIZARD3_DIRECTION_ENTER;	//�L��������(�I����)
	charadata_battle.m_correct			= STATE_LIZARD3_CORRECT;			//�p�����[�^�␳�̒l�i�񕜋Z�̂Ƃ��g�p�j
	charadata_battle.m_kind_skillattack	= STATE_LIZARD3_SKILLATTACK;		//����U�����
	charadata_battle.m_mp_battle		= STATE_LIZARD3_MPGET;				//�L�����̎���MP�ʂƂ͕ʂɁA�w���̐퓬���Ɂx�l�������l��ۑ�
	charadata_battle.m_action_end		= false;
	charadata_battle.m_battle_impossible= false;
}
