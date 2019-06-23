#pragma once
/************************************************************************************
 *																					*
 *	�����F���I�̊e�X�e�[�^�X���Ǘ�����B											*
 *																					*
 *	�����F���I�̊e�X�e�[�^�X���Ǘ�����B											*
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
//���I�̊e�p�����[�^				
#define STATE_RIO_ATK		(20)
#define STATE_RIO_DEF		(25)
#define STATE_RIO_MAG		(35)
#define STATE_RIO_RES		(30)
#define STATE_RIO_MG		(0)
#define STATE_RIO_MAXMG		(100)
#define STATE_RIO_AGL		(40)
#define STATE_RIO_DEX		(40)
#define STATE_RIO_HP		(250)
#define STATE_RIO_MAXHP		(250)
#define STATE_RIO_AP		(8)
#define STATE_RIO_MAXAP		(8)
#define STATE_RIO_AP_R		(5)
#define STATE_RIO_MOV		(4)
#define STATE_RIO_RANGE		(3)
#define STATE_RIO_LUK		(16)
#define STATE_RIO_MP		(0)
//�o�g���p�����[�^
#define STATE_RIO_X					(0)
#define STATE_RIO_Y					(0)
#define STATE_RIO_DIRECTION			(RIGHT_BACK)
#define STATE_RIO_DIRECTION_ENTER	(0)
#define STATE_RIO_CORRECT			(50)
#define STATE_RIO_SKILLATTACK		(2)
#define STATE_RIO_MPGET				(0)
/*================================
	
		struct����

=================================*/

class C_CharaData_Rio :	public C_PlayerCommon
{
private:
	CharaData_player rio; 
public:
	C_CharaData_Rio(void);
	void Init();
	void Draw();

	~C_CharaData_Rio(void);
};
