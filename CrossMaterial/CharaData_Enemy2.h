#pragma once
/************************************************************************************
 *																					*
 *	�����F�T�n�M���㋉(�G��2)�̊e�X�e�[�^�X���Ǘ�����B									*
 *																					*
 *	�����F�T�n�M���㋉(�G��2)�̊e�X�e�[�^�X���Ǘ�����B									*
 *																					*
 *	�쐬���F2008�N11�� 9��															*
 *																					*
 *	�X�V���F2008�N �� ��															*
 *													by �O��@�j						*
 *																					*
 ************************************************************************************/
/*================================
	
		INCLUDE����

=================================*/
#include "Enemycommon.h"

/*================================
	
		Define����

=================================*/
//Enemy1(�G��1)�̊e�p�����[�^				
#define STATE_SAHAGIN2_ATK		(20)
#define STATE_SAHAGIN2_DEF		(2)
#define STATE_SAHAGIN2_MAG		(20)
#define STATE_SAHAGIN2_RES		(15)
#define STATE_SAHAGIN2_MG		(0)
#define STATE_SAHAGIN2_MAXMG	(0)
#define STATE_SAHAGIN2_AGL		(25)
#define STATE_SAHAGIN2_DEX		(20)
#define STATE_SAHAGIN2_HP		(40)
#define STATE_SAHAGIN2_MAXHP	(40)
#define STATE_SAHAGIN2_AP		(8)
#define STATE_SAHAGIN2_MAXAP	(8)
#define STATE_SAHAGIN2_AP_R		(5)
#define STATE_SAHAGIN2_MOV		(2)
#define STATE_SAHAGIN2_RANGE	(1)
#define STATE_SAHAGIN2_LUK		(3)
#define STATE_SAHAGIN2_MP		(0)
//�o�g���p�����[�^
#define STATE_SAHAGIN2_X					(0)
#define STATE_SAHAGIN2_Y					(0)
#define STATE_SAHAGIN2_DIRECTION			(LEFT_FLONT)
#define STATE_SAHAGIN2_DIRECTION_ENTER		(0)
#define STATE_SAHAGIN2_CORRECT				(50)
#define STATE_SAHAGIN2_SKILLATTACK			(2)
#define STATE_SAHAGIN2_MPGET				(0)
/*================================
	
		struct����

=================================*/


class C_CharaData_Enemy2 :	public C_EnemyCommon
{
public:
	C_CharaData_Enemy2(void);
	void Init();
	void Draw(){};
	~C_CharaData_Enemy2(void);
};
