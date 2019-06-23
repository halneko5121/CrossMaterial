#include "CharaData_Rio.h"

C_CharaData_Rio::C_CharaData_Rio(void)
{
}

C_CharaData_Rio::~C_CharaData_Rio(void)
{
}

void C_CharaData_Rio::Draw()
{
}

void C_CharaData_Rio::Init()
{
	charadata_status.m_id		= RIO_ID;		//�L����ID	
	charadata_status.m_atk		= STATE_RIO_ATK;		//�U����								
	charadata_status.m_def		= STATE_RIO_DEF;		//�h���								
	charadata_status.m_mag		= STATE_RIO_MAG;		//���@�U����							
	charadata_status.m_res		= STATE_RIO_RES;		//���@��R��							
	charadata_status.m_mg		= STATE_RIO_MG;		//�����_�ł̃}�e���A���Q�[�W�i��	
	charadata_status.m_maxmg	= STATE_RIO_MAXMG;	//�ő�}�e���A���Q�[�W�i���K�E�Z	
	charadata_status.m_agl		= STATE_RIO_AGL;		//����							
	charadata_status.m_dex		= STATE_RIO_DEX;		//������							
	charadata_status.m_hp		= STATE_RIO_HP;		//HP
	charadata_status.m_maxhp	= STATE_RIO_MAXHP;	//�ő�HP	
	charadata_status.m_ap		= STATE_RIO_AP;		//AP(�c��s����)
	charadata_status.m_maxap	= STATE_RIO_MAXAP;	//�ő�AP	
	charadata_status.m_ap_r		= STATE_RIO_AP_R;		//1�^�[��AP�񕜗�
	charadata_status.m_mov		= STATE_RIO_MOV;		//�ړ���
	charadata_status.m_atkrange	= STATE_RIO_RANGE;		//�U���͈�
	charadata_status.m_luk		= STATE_RIO_LUK;		//�N���e�B�J�����ɉe��
	charadata_status.m_mp		= STATE_RIO_MP;		//MP������
	charadata_status.m_skill_range1 = STATE_SPASE_RANGE;	//�K�E�Z1�͈̔�
	charadata_status.m_skill_range2 = STATE_SPASE_RANGE;	//�K�E�Z2�͈̔�

	charadata_battle.m_id				= RIO_ID;						//�L������ID
	charadata_battle.m_pos_chara_x		= STATE_RIO_X;					//�L�����̈ʒu���X
	charadata_battle.m_pos_chara_y		= STATE_RIO_Y;					//�L�����̈ʒu���Y
	charadata_battle.m_direction		= STATE_RIO_DIRECTION;			//�L��������(����O)
	charadata_battle.m_direction_enter	= STATE_RIO_DIRECTION_ENTER;	//�L��������(�I����)
	charadata_battle.m_correct			= STATE_RIO_CORRECT;			//�p�����[�^�␳�̒l�i�񕜋Z�̂Ƃ��g�p�j
	charadata_battle.m_kind_skillattack	= STATE_RIO_SKILLATTACK;		//����U�����
	charadata_battle.m_mp_battle		= STATE_RIO_MPGET;				//�L�����̎���MP�ʂƂ͕ʂɁA�w���̐퓬���Ɂx�l�������l��ۑ�
	charadata_battle.m_action_end		= false;						//�s���I�����Ă��邩�ۂ��̔���
	charadata_battle.m_battle_impossible= false;
}
