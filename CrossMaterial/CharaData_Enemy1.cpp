#include "CharaData_Enemy1.h"

C_CharaData_Enemy1::C_CharaData_Enemy1(void)
{

}

C_CharaData_Enemy1::~C_CharaData_Enemy1(void)
{
}
void C_CharaData_Enemy1::Init()
{
	charadata_status.m_id				= SAHAGIN1_ID;						//�L����ID	
	charadata_status.m_atk				= STATE_SAHAGIN1_ATK;				//�U����								
	charadata_status.m_def				= STATE_SAHAGIN1_DEF;				//�h���								
	charadata_status.m_mag				= STATE_SAHAGIN1_MAG;				//���@�U����							
	charadata_status.m_res				= STATE_SAHAGIN1_RES;				//���@��R��							
	charadata_status.m_mg				= STATE_SAHAGIN1_MG;				//�����_�ł̃}�e���A���Q�[�W�i��	
	charadata_status.m_maxmg			= STATE_SAHAGIN1_MAXMG;				//�ő�}�e���A���Q�[�W�i���K�E�Z	
	charadata_status.m_agl				= STATE_SAHAGIN1_AGL;				//����							
	charadata_status.m_dex				= STATE_SAHAGIN1_DEX;				//������							
	charadata_status.m_hp				= STATE_SAHAGIN1_HP;				//HP
	charadata_status.m_maxhp			= STATE_SAHAGIN1_MAXHP;				//�ő�HP	
	charadata_status.m_ap				= STATE_SAHAGIN1_AP;				//AP(�c��s����)
	charadata_status.m_maxap			= STATE_SAHAGIN1_MAXAP;				//�ő�AP	
	charadata_status.m_ap_r				= STATE_SAHAGIN1_AP_R;				//1�^�[��AP�񕜗�
	charadata_status.m_mov				= STATE_SAHAGIN1_MOV;				//�ړ���
	charadata_status.m_atkrange			= STATE_SAHAGIN1_RANGE;				//�U���͈�
	charadata_status.m_luk				= STATE_SAHAGIN1_LUK;				//�N���e�B�J�����ɉe��
	charadata_status.m_mp				= STATE_SAHAGIN1_MP;				//MP������
	charadata_status.m_attribute		= GNOME; 
	charadata_status.m_skill_range1		= STATE_SPASE_RANGE;				//�K�E�Z1�͈̔�
	charadata_status.m_skill_range2		= STATE_SPASE_RANGE;				//�K�E�Z2�͈̔�

	charadata_battle.m_id				= SAHAGIN1_ID;						//�L������ID
	charadata_battle.m_pos_chara_x		= STATE_SAHAGIN1_X;					//�L�����̈ʒu���X
	charadata_battle.m_pos_chara_y		= STATE_SAHAGIN1_Y;					//�L�����̈ʒu���Y
	charadata_battle.m_direction		= STATE_SAHAGIN1_DIRECTION;			//�L��������(����O)
	charadata_battle.m_direction_enter	= STATE_SAHAGIN1_DIRECTION_ENTER;	//�L��������(�I����)
	charadata_battle.m_correct			= STATE_SAHAGIN1_CORRECT;			//�p�����[�^�␳�̒l�i�񕜋Z�̂Ƃ��g�p�j
	charadata_battle.m_kind_skillattack	= STATE_SAHAGIN1_SKILLATTACK;		//����U�����
	charadata_battle.m_mp_battle		= STATE_SAHAGIN1_MPGET;				//�L�����̎���MP�ʂƂ͕ʂɁA�w���̐퓬���Ɂx�l�������l��ۑ�
	charadata_battle.m_action_end		= false;	
	charadata_battle.m_battle_impossible= false;
}