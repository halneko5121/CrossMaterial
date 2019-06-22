#pragma once
/************************************************************************************
 *																					*
 *	役割：ボスの各ステータスを管理する。											*
 *																					*
 *	説明：ボスの各ステータスを管理する。											*
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
//ドラゴン上級(敵4)の各パラメータ				
#define STATE_LIZARD3_ATK		(40)
#define STATE_LIZARD3_DEF		(15)
#define STATE_LIZARD3_MAG		(35)
#define STATE_LIZARD3_RES		(25)
#define STATE_LIZARD3_MG		(0)
#define STATE_LIZARD3_MAXMG		(0)
#define STATE_LIZARD3_AGL		(35)
#define STATE_LIZARD3_DEX		(40)
#define STATE_LIZARD3_HP		(200)
#define STATE_LIZARD3_MAXHP		(200)
#define STATE_LIZARD3_AP		(8)
#define STATE_LIZARD3_MAXAP		(8)
#define STATE_LIZARD3_AP_R		(5)
#define STATE_LIZARD3_MOV		(4)
#define STATE_LIZARD3_RANGE		(1)
#define STATE_LIZARD3_LUK		(4)
#define STATE_LIZARD3_MP		(0)
//バトルパラメータ
#define STATE_LIZARD3_X					(0)
#define STATE_LIZARD3_Y					(0)
#define STATE_LIZARD3_DIRECTION			(LEFT_FLONT)
#define STATE_LIZARD3_DIRECTION_ENTER	(0)
#define STATE_LIZARD3_CORRECT			(50)
#define STATE_LIZARD3_SKILLATTACK		(2)
#define STATE_LIZARD3_MPGET				(0)
/*================================
	
		structたち

=================================*/

class C_CharaData_Boss  :public C_EnemyCommon
{
public:
	C_CharaData_Boss(void);
	void Init();
	void Draw(){};
	~C_CharaData_Boss(void);
};
