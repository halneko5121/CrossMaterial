#pragma once
/************************************************************************************
 *																					*
 *	�����F�V�I���̊e�X�e�[�^�X���Ǘ�����B											*
 *																					*
 *	�����F�V�I���̊e�X�e�[�^�X���Ǘ�����B											*
 *																					*
 *	�쐬���F2008�N11�� 8��															*
 *																					*
 *	�X�V���F2008�N �� ��															*
 *													by �O��@�j						*
 *																					*
 ************************************************************************************/
/*================================
	
		INCLUDE����

=================================*/
#include "PlayerCommon.h"
/*================================
	
		Define����

=================================*/
//�V�I���̊e�p�����[�^
#define STATE_ZION_ATK		(30)
#define STATE_ZION_DEF		(30)
#define STATE_ZION_MAG		(25)
#define STATE_ZION_RES		(30)
#define STATE_ZION_MG		(0)
#define STATE_ZION_MAXMG	(100)
#define STATE_ZION_AGL		(35)
#define STATE_ZION_DEX		(30)
#define STATE_ZION_HP		(180)
#define STATE_ZION_MAXHP	(180)
#define STATE_ZION_AP		(12)
#define STATE_ZION_MAXAP	(12)
#define STATE_ZION_AP_R		(6)
#define STATE_ZION_MOV		(4)
#define STATE_ZION_RANGE	(1)
#define STATE_ZION_LUK		(12)
#define STATE_ZION_MP		(0)
//�o�g���p�����[�^
#define STATE_ZION_X					(0)
#define STATE_ZION_Y					(0)
#define STATE_ZION_DIRECTION			(RIGHT_BACK)
#define STATE_ZION_DIRECTION_ENTER		(0)
#define STATE_ZION_CORRECT				(50)
#define STATE_ZION_SKILLATTACK			(2)
#define STATE_ZION_MPGET				(0)

/*================================
	
		struct����

=================================*/

class C_CharaData_Zion:public C_PlayerCommon
{
public:
	C_CharaData_Zion(void);
	void Init();
	void Draw();

	~C_CharaData_Zion(void);
};
