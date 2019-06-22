#pragma once
/************************************************************************************
 *																					*
 *	役割：計算処理を管理します														*
 *																					*
 *	説明：バトルの計算処理（ダメージ、回復、ＭＰ増加など）							*
 *																					*
 *	作成日：2009年1月28日															*
 *																					*
 *	更新日：2008年1月28日															*
 *													by	兼武						*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Define.h"
#include"PlayerCommon.h"
#include"EnemyCommon.h"
/*================================
	
		Defineたち

=================================*/
#define RECOVERYMATH	(3)
#define CRITICALMATH	(2)
#define MGMATH	(10)


class C_Calculate/*public C_EnemyCommon : public C_PlayerCommon*/
{
private:
	int hit_math;	//命中率の計算結果

	int hit_fate;	//ランダムの結果
	
	int critical_math;	//クリティカルの計算結果
	
	int critical_fate;	//クリティカルのランダム結果
	
	int integer;	//整数
	
	int point1;	//小数点第1位
	
	//int point2;	//小数点第2位
public:
	C_Calculate(void);
	~C_Calculate(void);

	void Init();

	void Draw();

	double RioDeDamage(int mg_offense);
	double VanDamage(int offense);
	double ZionDamage(int offense,int dif);

	int HitResult(int hitrate,int evasion);	//命中率の判定処理(命中率,回避率)

	double NormalAttackDamage(int offense,int defense);	//通常攻撃のダメージ処理(攻撃力,防御力)

	double SpecialAttackDamage(int offense,int mg_offense,double topography,double attribute,int defense,int mg_resistance,int id);	//特殊攻撃のダメージ処理(攻撃力,魔法攻撃力,地形効果,属性効果,防御力,魔法抵抗力)

	int SpecialRecovery(int lifemax);	//特殊回復の増加処理(最大HP)

	int SuperAttackDamage(int n_damege);	//超必殺のダメージ処理(通常攻撃のダメージ)

	double Critical(int probability);	//クリティカル判定処理(クリティカル)

	int MGPlus(int enemy_no);	//MGゲージ増加処理(ダメージ,最大AP)

	int RoundOff(int general,int divide);	//四捨五入処理(全体,割る値)

	double AttributeAffinity(int standard,int comparison);	//属性効果処理(攻撃をするキャラの属性,受けるキャラの属性)
};
