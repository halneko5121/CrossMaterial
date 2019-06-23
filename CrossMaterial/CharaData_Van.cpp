#include "CharaData_van.h"


C_CharaData_Van::C_CharaData_Van(void)
{
}

C_CharaData_Van::~C_CharaData_Van(void)
{
}
void C_CharaData_Van::Init()
{


	charadata_status.m_id		= VAN_ID;		//�L����ID	
	charadata_status.m_atk		= STATE_VAN_ATK;		//�U����				
	charadata_status.m_def		= STATE_VAN_DEF;		//�h���				
	charadata_status.m_mag		= STATE_VAN_MAG;		//���@�U����			
	charadata_status.m_res		= STATE_VAN_RES;		//���@��R��			
	charadata_status.m_mg		= STATE_VAN_MG;		//�����_�ł̃}�e���A���Q�[
	charadata_status.m_maxmg	= STATE_VAN_MAXMG;	//�ő�}�e���A���Q�[�W�i��
	charadata_status.m_agl		= STATE_VAN_AGL;		//����				
	charadata_status.m_dex		= STATE_VAN_DEX;		//������				
	charadata_status.m_hp		= STATE_VAN_HP;		//HP
	charadata_status.m_maxhp	= STATE_VAN_MAXHP;	//�ő�HP	
	charadata_status.m_ap		= STATE_VAN_AP;		//AP(�c��s����)
	charadata_status.m_maxap	= STATE_VAN_MAXAP;	//�ő�AP	
	charadata_status.m_ap_r		= STATE_VAN_AP_R;		//1�^�[��AP�񕜗�
	charadata_status.m_mov		= STATE_VAN_MOV;		//�ړ���
	charadata_status.m_atkrange	= STATE_VAN_RANGE;		//�U���͈�
	charadata_status.m_luk		= STATE_VAN_LUK;		//�N���e�B�J�����ɉe��
	charadata_status.m_mp		= STATE_VAN_MP;		//MP������
	charadata_status.m_skill_range1 = STATE_SPASE_RANGE;	//�K�E�Z1�͈̔�
	charadata_status.m_skill_range2 = STATE_SPASE_RANGE;	//�K�E�Z2�͈̔�

	charadata_battle.m_id				= VAN_ID;						//�L������ID
	charadata_battle.m_pos_chara_x		= STATE_VAN_X;					//�L�����̈ʒu���X
	charadata_battle.m_pos_chara_y		= STATE_VAN_Y;					//�L�����̈ʒu���Y
	charadata_battle.m_direction		= STATE_VAN_DIRECTION;			//�L��������(����O)
	charadata_battle.m_direction_enter	= STATE_VAN_DIRECTION_ENTER;	//�L��������(�I����)
	charadata_battle.m_correct			= STATE_VAN_CORRECT;			//�p�����[�^�␳�̒l�i�񕜋Z�̂Ƃ��g�p�j
	charadata_battle.m_kind_skillattack	= STATE_VAN_SKILLATTACK;		//����U�����
	charadata_battle.m_mp_battle		= STATE_VAN_MPGET;				//�L�����̎���MP�ʂƂ͕ʂɁA�w���̐퓬���Ɂx�l�������l��ۑ�
	charadata_battle.m_action_end		= false;							//�s���I�����Ă��邩�ۂ��̔���
	charadata_battle.m_battle_impossible= false;
}

void C_CharaData_Van::Draw()
{
}