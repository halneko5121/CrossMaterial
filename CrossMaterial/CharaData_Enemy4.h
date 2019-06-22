#pragma once
/************************************************************************************
 *																					*
 *	役割：ドラゴン上級(敵4)の各ステータスを管理する。								*
 *																					*
 *	説明：ドラゴン上級(敵4)の各ステータスを管理する。								*
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
#define STATE_LIZARD2_ATK		(40)
#define STATE_LIZARD2_DEF		(10)
#define STATE_LIZARD2_MAG		(35)
#define STATE_LIZARD2_RES		(25)
#define STATE_LIZARD2_MG		(0)
#define STATE_LIZARD2_MAXMG		(0)
#define STATE_LIZARD2_AGL		(35)
#define STATE_LIZARD2_DEX		(40)
#define STATE_LIZARD2_HP		(160)
#define STATE_LIZARD2_MAXHP		(160)
#define STATE_LIZARD2_AP		(8)
#define STATE_LIZARD2_MAXAP		(8)
#define STATE_LIZARD2_AP_R		(5)
#define STATE_LIZARD2_MOV		(1)
#define STATE_LIZARD2_RANGE		(1)
#define STATE_LIZARD2_LUK		(4)
#define STATE_LIZARD2_MP		(0)
//バトルパラメータ
#define STATE_LIZARD2_X					(0)
#define STATE_LIZARD2_Y					(0)
#define STATE_LIZARD2_DIRECTION			(LEFT_FLONT)
#define STATE_LIZARD2_DIRECTION_ENTER	(0)
#define STATE_LIZARD2_CORRECT			(50)
#define STATE_LIZARD2_SKILLATTACK		(2)
#define STATE_LIZARD2_MPGET				(0)
/*================================
	
		structたち

=================================*/

class C_CharaData_Enemy4 :public C_EnemyCommon
{
public:
	C_CharaData_Enemy4(void);
	void Init();
	void Draw(){};
	~C_CharaData_Enemy4(void);
};
