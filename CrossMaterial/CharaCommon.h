#pragma once
/************************************************************************************
 *																					*
 *	�����F�S�L�����ɋ��ʂ����������ꊇ���ĊǗ�����B								*
 *																					*
 *	�����F�S�L�����̋��ʕ������Ǘ�����B											*
 *																					*
 *	�쐬���F2008�N11�� 8��															*
 *																					*
 *	�X�V���F2008�N�� ��																*
 *													by �O��@�j						*
 *																					*
 ************************************************************************************/
/*================================
	
		INCLUDE����

=================================*/
#include "D_Battle.h"
#include "DirectGraphics.h"
#include <stdio.h>

/*================================
	
		Define����

=================================*/
enum MATERIAL_ATTRIBUTE		//�}�e���A���̑���
{
	SALAMANDER,				//�Α���
	UNDINE,					//������
	SYLPH,					//������
	GNOME,					//�y����
};

/*================================
	
		struct����

=================================*/
struct CharaData_status
{
	//�L�������ʂ̂���(�G��������)�X�e�[�^�X�̖��O������ID�ɂĔ��肵�`���؂�ւ���
	//�Z�[�u����ꍇ�͊e�ۑ��p�̍\���̂�p�ӂ��Ă���ɓ���Ă��������B
	int	 m_id;				//�L����ID	
	int	 m_atk;				//�U����
	int  m_def;				//�h���
	int  m_mag;				//���@�U����
	int  m_res;				//���@��R��
	int  m_mg;				//�����_�ł̃}�e���A���Q�[�W�i���K�E�Z�ɕK�v�ȃQ�[�W�j
	int  m_maxmg;			//�ő�}�e���A���Q�[�W�i���K�E�Z�ɕK�v�ȃQ�[�W�j
	int  m_agl;				//����
	int  m_dex;				//������
	int  m_hp;				//HP
	int	 m_maxhp;			//�ő�HP	
	int  m_ap;				//AP(�s����)
	int	 m_maxap;			//�ő�AP	
	int  m_ap_r;			//1�^�[��AP�񕜗�
	int  m_mov;				//�ړ���
	int  m_atkrange;		//�U���͈�
	int  m_luk;				//�N���e�B�J�����ɉe��
	int  m_mp;				//MP������
	int  m_attribute;		//�G�̑����̎�ޔ��ʁi�����ł����Ƃ���̃}�e���A�������j
	int  m_skill_range1;	//����U��������ۂ͈̔�1
	int  m_skill_range2;	//����U��������ۂ͈̔�2
};		 

typedef struct CharaData_battle			//�퓬���ɂ̂ݕK�v�Ȃ���
{
	int  m_id;					//�L������ID
	int  m_pos_chara_x;			//�L�����̈ʒu���X
	int  m_pos_chara_y;			//�L�����̈ʒu���Y
	int  m_direction;			//�L��������(����O)
	int  m_direction_enter;		//�L��������(�I����)
	int  m_correct;				//�p�����[�^�␳�̒l�i�񕜋Z�̂Ƃ��g�p�j
	int  m_kind_skillattack;	//����U�����
	int  m_mp_battle;			//�L�����̎���MP�ʂƂ͕ʂɁA�w���̐퓬���Ɂx�l�������l��ۑ�
	bool m_action_end;			//�s���I�����Ă��邩�ۂ��̔���
	bool m_battle_impossible;	//�퓬�s�\�t���O
}CharaData_battle;

//�L�����N���X(�L�����̊��N���X)
class C_CharaCommon
{
protected:
	CharaData_status charadata_status;
	CharaData_battle charadata_battle;
public:
	C_CharaCommon(void);
	virtual void Init() = 0;
	virtual void Draw() = 0;
	~C_CharaCommon(void);
	
	void SetCharaState(CharaData_status status) { charadata_status = status;}
	void SetCharaStateBattle(CharaData_battle status_battle) { charadata_battle = status_battle;}

	CharaData_status GetCharaState() { return charadata_status;}
	CharaData_battle GetCharaStateBattle() { return charadata_battle;}



};
