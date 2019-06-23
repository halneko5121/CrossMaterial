#include "CharaData_Enemy4.h"

C_CharaData_Enemy4::C_CharaData_Enemy4(void)
{
}

C_CharaData_Enemy4::~C_CharaData_Enemy4(void)
{
}

void C_CharaData_Enemy4::Init()
{
	charadata_status.m_id				= LIZARD2_ID;						//�L����ID	
	charadata_status.m_atk				= STATE_LIZARD2_ATK;				//�U����								
	charadata_status.m_def				= STATE_LIZARD2_DEF;				//�h���								
	charadata_status.m_mag				= STATE_LIZARD2_MAG;				//���@�U����							
	charadata_status.m_res				= STATE_LIZARD2_RES;				//���@��R��							
	charadata_status.m_mg				= STATE_LIZARD2_MG;					//�����_�ł̃}�e���A���Q�[�W�i��	
	charadata_status.m_maxmg			= STATE_LIZARD2_MAXMG;				//�ő�}�e���A���Q�[�W�i���K�E�Z	
	charadata_status.m_agl				= STATE_LIZARD2_AGL;				//����							
	charadata_status.m_dex				= STATE_LIZARD2_DEX;				//������							
	charadata_status.m_hp				= STATE_LIZARD2_HP;					//HP
	charadata_status.m_maxhp			= STATE_LIZARD2_MAXHP;				//�ő�HP	
	charadata_status.m_ap				= STATE_LIZARD2_AP;					//AP(�c��s����)
	charadata_status.m_maxap			= STATE_LIZARD2_MAXAP;				//�ő�AP	
	charadata_status.m_ap_r				= STATE_LIZARD2_AP_R;				//1�^�[��AP�񕜗�
	charadata_status.m_mov				= STATE_LIZARD2_MOV;				//�ړ���
	charadata_status.m_atkrange			= STATE_LIZARD2_RANGE;				//�U���͈�
	charadata_status.m_luk				= STATE_LIZARD2_LUK;				//�N���e�B�J�����ɉe��
	charadata_status.m_mp				= STATE_LIZARD2_MP;
	charadata_status.m_attribute		= SALAMANDER;
	charadata_status.m_skill_range1		= STATE_SPASE_RANGE;				//�K�E�Z1�͈̔�
	charadata_status.m_skill_range2		= STATE_SPASE_RANGE;				//�K�E�Z2�͈̔�

	charadata_battle.m_id				= LIZARD2_ID;						//�L������ID
	charadata_battle.m_pos_chara_x		= STATE_LIZARD2_X;					//�L�����̈ʒu���X
	charadata_battle.m_pos_chara_y		= STATE_LIZARD2_Y;					//�L�����̈ʒu���Y
	charadata_battle.m_direction		= STATE_LIZARD2_DIRECTION;			//�L��������(����O)
	charadata_battle.m_direction_enter	= STATE_LIZARD2_DIRECTION_ENTER;	//�L��������(�I����)
	charadata_battle.m_correct			= STATE_LIZARD2_CORRECT;			//�p�����[�^�␳�̒l�i�񕜋Z�̂Ƃ��g�p�j
	charadata_battle.m_kind_skillattack	= STATE_LIZARD2_SKILLATTACK;		//����U�����
	charadata_battle.m_mp_battle		= STATE_LIZARD2_MPGET;				//�L�����̎���MP�ʂƂ͕ʂɁA�w���̐퓬���Ɂx�l�������l��ۑ�
	charadata_battle.m_action_end		= false;							//�s���I�����Ă��邩�ۂ��̔���
	charadata_battle.m_battle_impossible= false;
}
