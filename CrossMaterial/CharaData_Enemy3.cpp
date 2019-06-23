#include "CharaData_Enemy3.h"

C_CharaData_Enemy3::C_CharaData_Enemy3(void)
{	
}

C_CharaData_Enemy3::~C_CharaData_Enemy3(void)
{
}

void C_CharaData_Enemy3::Init()
{
	charadata_status.m_id				= LIZARD1_ID;						//�L����ID	
	charadata_status.m_atk				= STATE_LIZARD1_ATK;				//�U����								
	charadata_status.m_def				= STATE_LIZARD1_DEF;				//�h���								
	charadata_status.m_mag				= STATE_LIZARD1_MAG;				//���@�U����							
	charadata_status.m_res				= STATE_LIZARD1_RES;				//���@��R��							
	charadata_status.m_mg				= STATE_LIZARD1_MG;					//�����_�ł̃}�e���A���Q�[�W�i��	
	charadata_status.m_maxmg			= STATE_LIZARD1_MAXMG;				//�ő�}�e���A���Q�[�W�i���K�E�Z	
	charadata_status.m_agl				= STATE_LIZARD1_AGL;				//����							
	charadata_status.m_dex				= STATE_LIZARD1_DEX;				//������							
	charadata_status.m_hp				= STATE_LIZARD1_HP;					//HP
	charadata_status.m_maxhp			= STATE_LIZARD1_MAXHP;				//�ő�HP	
	charadata_status.m_ap				= STATE_LIZARD1_AP;					//AP(�c��s����)
	charadata_status.m_maxap			= STATE_LIZARD1_MAXAP;				//�ő�AP	
	charadata_status.m_ap_r				= STATE_LIZARD1_AP_R;				//1�^�[��AP�񕜗�
	charadata_status.m_mov				= STATE_LIZARD1_MOV;				//�ړ���
	charadata_status.m_atkrange			= STATE_LIZARD1_RANGE;				//�U���͈�
	charadata_status.m_luk				= STATE_LIZARD1_LUK;				//�N���e�B�J�����ɉe��
	charadata_status.m_mp				= STATE_LIZARD1_MP;
	charadata_status.m_attribute		= GNOME;
	charadata_status.m_skill_range1		= STATE_SPASE_RANGE;				//�K�E�Z1�͈̔�
	charadata_status.m_skill_range2		= STATE_SPASE_RANGE;				//�K�E�Z2�͈̔�

	charadata_battle.m_id				= LIZARD1_ID;						//�L������ID
	charadata_battle.m_pos_chara_x		= STATE_LIZARD1_X;					//�L�����̈ʒu���X
	charadata_battle.m_pos_chara_y		= STATE_LIZARD1_Y;					//�L�����̈ʒu���Y
	charadata_battle.m_direction		= STATE_LIZARD1_DIRECTION;			//�L��������(����O)
	charadata_battle.m_direction_enter	= STATE_LIZARD1_DIRECTION_ENTER;	//�L��������(�I����)
	charadata_battle.m_correct			= STATE_LIZARD1_CORRECT;			//�p�����[�^�␳�̒l�i�񕜋Z�̂Ƃ��g�p�j
	charadata_battle.m_kind_skillattack	= STATE_LIZARD1_SKILLATTACK;		//����U�����
	charadata_battle.m_mp_battle		= STATE_LIZARD1_MPGET;				//�L�����̎���MP�ʂƂ͕ʂɁA�w���̐퓬���Ɂx�l�������l��ۑ�
	charadata_battle.m_action_end		= false;							//�s���I�����Ă��邩�ۂ��̔���
	charadata_battle.m_battle_impossible= false;
}
