#include "CharaData_Zion.h"


C_CharaData_Zion::C_CharaData_Zion(void)
{	 
}

C_CharaData_Zion::~C_CharaData_Zion(void)
{
}
void C_CharaData_Zion::Init()
{
	//���b���ł�����SAVE����ꂽ��SAVEDATA��������悤�ɂ��Ȃ��Ƃ����Ȃ�
	charadata_status.m_id		= ZION_ID;				//�L����ID	
	charadata_status.m_atk		= STATE_ZION_ATK;		//�U����								
	charadata_status.m_def		= STATE_ZION_DEF;		//�h���								
	charadata_status.m_mag		= STATE_ZION_MAG;		//���@�U����							
	charadata_status.m_res		= STATE_ZION_RES;		//���@��R��							
	charadata_status.m_mg		= STATE_ZION_MG;		//�����_�ł̃}�e���A���Q�[�W�i��	
	charadata_status.m_maxmg	= STATE_ZION_MAXMG;	//�ő�}�e���A���Q�[�W�i���K�E�Z	
	charadata_status.m_agl		= STATE_ZION_AGL;		//����							
	charadata_status.m_dex		= STATE_ZION_DEX;		//������							
	charadata_status.m_hp		= STATE_ZION_HP;		//HP
	charadata_status.m_maxhp	= STATE_ZION_MAXHP;	//�ő�HP	
	charadata_status.m_ap		= STATE_ZION_AP;		//AP(�c��s����)
	charadata_status.m_maxap	= STATE_ZION_MAXAP;	//�ő�AP	
	charadata_status.m_ap_r		= STATE_ZION_AP_R;	//1�^�[��AP�񕜗�
	charadata_status.m_mov		= STATE_ZION_MOV;		//�ړ���
	charadata_status.m_atkrange	= STATE_ZION_RANGE;		//�U���͈�
	charadata_status.m_luk		= STATE_ZION_LUK;		//�N���e�B�J�����ɉe��
	charadata_status.m_mp		= STATE_ZION_MP;		//MP������
	charadata_status.m_skill_range1 = STATE_SPASE_RANGE;	//�K�E�Z1�͈̔�
	charadata_status.m_skill_range2 = STATE_SPASE_RANGE;	//�K�E�Z2�͈̔�

	charadata_battle.m_id				= ZION_ID;						//�L������ID
	charadata_battle.m_pos_chara_x		= STATE_ZION_X;					//�L�����̈ʒu���X
	charadata_battle.m_pos_chara_y		= STATE_ZION_Y;					//�L�����̈ʒu���Y
	charadata_battle.m_direction		= STATE_ZION_DIRECTION;			//�L��������(����O)
	charadata_battle.m_direction_enter	= STATE_ZION_DIRECTION_ENTER;	//�L��������(�I����)
	charadata_battle.m_correct			= STATE_ZION_CORRECT;			//�p�����[�^�␳�̒l�i�񕜋Z�̂Ƃ��g�p�j
	charadata_battle.m_kind_skillattack	= STATE_ZION_SKILLATTACK;		//����U�����
	charadata_battle.m_mp_battle		= STATE_ZION_MPGET;				//�L�����̎���MP�ʂƂ͕ʂɁA�w���̐퓬���Ɂx�l�������l��ۑ�
	charadata_battle.m_action_end		= false;	
	charadata_battle.m_battle_impossible= false;
}
void C_CharaData_Zion::Draw()
{	

}