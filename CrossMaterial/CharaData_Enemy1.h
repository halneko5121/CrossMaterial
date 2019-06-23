#pragma once
/************************************************************************************
 *																					*
 *	�����F�T�n�M��(�G��1)�̊e�X�e�[�^�X���Ǘ�����B									*
 *																					*
 *	�����F�T�n�M��(�G��1)�̊e�X�e�[�^�X���Ǘ�����B									*
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
#define STATE_SAHAGIN1_ATK		(10)
#define STATE_SAHAGIN1_DEF		(1)
#define STATE_SAHAGIN1_MAG		(10)
#define STATE_SAHAGIN1_RES		(15)
#define STATE_SAHAGIN1_MG		(0)
#define STATE_SAHAGIN1_MAXMG	(0)
#define STATE_SAHAGIN1_AGL		(10)
#define STATE_SAHAGIN1_DEX		(20)
#define STATE_SAHAGIN1_HP		(32)
#define STATE_SAHAGIN1_MAXHP	(32)
#define STATE_SAHAGIN1_AP		(8)
#define STATE_SAHAGIN1_MAXAP	(8)
#define STATE_SAHAGIN1_AP_R		(5)
#define STATE_SAHAGIN1_MOV		(2)
#define STATE_SAHAGIN1_RANGE	(1)
#define STATE_SAHAGIN1_LUK		(2)
#define STATE_SAHAGIN1_MP		(0)
//�o�g���p�����[�^
#define STATE_SAHAGIN1_X					(0)
#define STATE_SAHAGIN1_Y					(0)
#define STATE_SAHAGIN1_DIRECTION			(LEFT_FLONT)
#define STATE_SAHAGIN1_DIRECTION_ENTER		(0)
#define STATE_SAHAGIN1_CORRECT				(50)
#define STATE_SAHAGIN1_SKILLATTACK			(2)
#define STATE_SAHAGIN1_MPGET				(0)
/*================================
	
		struct����

=================================*/


class C_CharaData_Enemy1 :	public C_EnemyCommon
{
public:
	C_CharaData_Enemy1(void);
	void Init();
	void Draw(){};
	~C_CharaData_Enemy1(void);
};
