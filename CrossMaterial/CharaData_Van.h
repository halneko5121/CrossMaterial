#pragma once
/************************************************************************************
 *																					*
 *	役割：ヴァンの各ステータスを管理する。											*
 *																					*
 *	説明：ヴァンの各ステータスを管理する。											*
 *																					*
 *	作成日：2008年11月 8日															*
 *																					*
 *	更新日：2008年 月 日															*
 *													by 三上　亘						*
 *																					*
 ************************************************************************************/
/*================================
	
		INCLUDEたち

=================================*/
#include "PlayerCommon.h"
/*================================
	
		Defineたち

=================================*/
//ヴァンの各パラメータ				
#define STATE_VAN_ATK		(45)
#define STATE_VAN_DEF		(40)
#define STATE_VAN_MAG		(20)
#define STATE_VAN_RES		(25)
#define STATE_VAN_MG		(0)
#define STATE_VAN_MAXMG		(100)
#define STATE_VAN_AGL		(20)
#define STATE_VAN_DEX		(20)
#define STATE_VAN_HP		(250)
#define STATE_VAN_MAXHP		(250)
#define STATE_VAN_AP		(10)
#define STATE_VAN_MAXAP		(10)
#define STATE_VAN_AP_R		(7)
#define STATE_VAN_MOV		(3)
#define STATE_VAN_RANGE		(1)
#define STATE_VAN_LUK		(6)
#define STATE_VAN_MP		(0)
//バトルパラメータ
#define STATE_VAN_X					(0)
#define STATE_VAN_Y					(0)
#define STATE_VAN_DIRECTION			(RIGHT_BACK)
#define STATE_VAN_DIRECTION_ENTER	(0)
#define STATE_VAN_CORRECT			(50)
#define STATE_VAN_SKILLATTACK		(2)
#define STATE_VAN_MPGET				(0)
/*================================
	
		structたち

=================================*/

class C_CharaData_Van :	public C_PlayerCommon
{
public:
	C_CharaData_Van(void);
	void Init();
	void Draw();
	~C_CharaData_Van(void);
};
