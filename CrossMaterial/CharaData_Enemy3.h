#pragma once
/************************************************************************************
 *																					*
 *	役割：ドラゴン(雑魚3)の各ステータスを管理する。									*
 *																					*
 *	説明：ドラゴン(雑魚3)の各ステータスを管理する。									*
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
//Enemy3(雑魚3)の各パラメータ				
#define STATE_LIZARD1_ATK		(30)
#define STATE_LIZARD1_DEF		(5)
#define STATE_LIZARD1_MAG		(25)
#define STATE_LIZARD1_RES		(25)
#define STATE_LIZARD1_MG		(0)
#define STATE_LIZARD1_MAXMG		(0)
#define STATE_LIZARD1_AGL		(35)
#define STATE_LIZARD1_DEX		(30)
#define STATE_LIZARD1_HP		(120)
#define STATE_LIZARD1_MAXHP		(120)
#define STATE_LIZARD1_AP		(8)
#define STATE_LIZARD1_MAXAP		(8)
#define STATE_LIZARD1_AP_R		(5)
#define STATE_LIZARD1_MOV		(2)
#define STATE_LIZARD1_RANGE		(1)
#define STATE_LIZARD1_LUK		(4)
#define STATE_LIZARD1_MP		(0)
//バトルパラメータ
#define STATE_LIZARD1_X					(0)
#define STATE_LIZARD1_Y					(0)
#define STATE_LIZARD1_DIRECTION			(LEFT_FLONT)
#define STATE_LIZARD1_DIRECTION_ENTER	(0)
#define STATE_LIZARD1_CORRECT			(50)
#define STATE_LIZARD1_SKILLATTACK		(2)
#define STATE_LIZARD1_MPGET				(0)
/*================================
	
		structたち

=================================*/

class C_CharaData_Enemy3 :	public C_EnemyCommon
{
public:
	C_CharaData_Enemy3(void);
	void Init();
	void Draw(){};
	~C_CharaData_Enemy3(void);
};
