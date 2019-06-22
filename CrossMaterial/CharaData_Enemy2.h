#pragma once
/************************************************************************************
 *																					*
 *	役割：サハギン上級(雑魚2)の各ステータスを管理する。									*
 *																					*
 *	説明：サハギン上級(雑魚2)の各ステータスを管理する。									*
 *																					*
 *	作成日：2008年11月 9日															*
 *																					*
 *	更新日：2008年 月 日															*
 *													by 三上　亘						*
 *																					*
 ************************************************************************************/
/*================================
	
		INCLUDEたち

=================================*/
#include "Enemycommon.h"

/*================================
	
		Defineたち

=================================*/
//Enemy1(雑魚1)の各パラメータ				
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
//バトルパラメータ
#define STATE_SAHAGIN2_X					(0)
#define STATE_SAHAGIN2_Y					(0)
#define STATE_SAHAGIN2_DIRECTION			(LEFT_FLONT)
#define STATE_SAHAGIN2_DIRECTION_ENTER		(0)
#define STATE_SAHAGIN2_CORRECT				(50)
#define STATE_SAHAGIN2_SKILLATTACK			(2)
#define STATE_SAHAGIN2_MPGET				(0)
/*================================
	
		structたち

=================================*/


class C_CharaData_Enemy2 :	public C_EnemyCommon
{
public:
	C_CharaData_Enemy2(void);
	void Init();
	void Draw(){};
	~C_CharaData_Enemy2(void);
};
