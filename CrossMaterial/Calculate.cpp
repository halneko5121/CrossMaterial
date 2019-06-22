#include "Calculate.h"

C_Calculate::C_Calculate(void)
{
	hit_math=0;
	integer=point1=0;
}

C_Calculate::~C_Calculate(void)
{
}

void C_Calculate::Init()
{
}

void C_Calculate::Draw()
{
}

int C_Calculate::HitResult(int hitrate, int evasion)	//–½’†—¦
{
	int decision;
	hit_math=100-evasion+hitrate;
	if(hit_math>=100)
	{
		decision=1;
	}
	else if(hit_math<100)
	{
		hit_fate=rand()%100+1;
		if(hit_fate<=hit_math)
		{
			decision=1;
		}
		else
			decision=0;
	}
	return decision;
}

double C_Calculate::NormalAttackDamage(int offense, int defense)
{
	double uncertain = 1.0;	//Šm—¦
	double n_damege;
	uncertain += (rand()%4+3) * 0.1;
	n_damege = offense * uncertain - defense;
	return n_damege;
}

double C_Calculate::SpecialAttackDamage(int offense,int mg_offense,double topography,double attribute,int defense,int mg_resistance,int id)
{
	double uncertain = 2.0;	//Šm—¦
	double s_damege;
	uncertain += (rand()%5+1) * 0.1;
	if(id != 30) { s_damege = (offense * uncertain - defense) * topography * attribute; }
	else { s_damege = (mg_offense * uncertain - mg_resistance) * topography * attribute; }
	if(s_damege<0) s_damege=0;
	return s_damege;
}

int C_Calculate::SpecialRecovery(int lifemax)
{
	int r_increase;
	r_increase = RoundOff(lifemax,RECOVERYMATH);
	return r_increase;
}

int C_Calculate::SuperAttackDamage(int n_damege)
{
	int sa_damege;
	sa_damege = n_damege * 3;
	return sa_damege;
}

double C_Calculate::Critical(int probability)
{
	double criticaljudge;
	critical_math = RoundOff(probability,CRITICALMATH);
	critical_fate=rand()%100+1;
	if(critical_fate<=critical_math)
	{
		criticaljudge = 1.5;
	}
	else{
		criticaljudge = 1.0;
	}
	return criticaljudge;
}

int C_Calculate::MGPlus(int enemy_no)
{
	int mg_increase = 0;
	double uncertain = 0.8;
	uncertain += rand()%5 * 0.1;
	mg_increase = (int)(enemy_no / 3 * uncertain);
	return mg_increase;
}

int C_Calculate::RoundOff(int general,int divide)
{
	int callculation;	//Œ‹‰Ê
	integer = general / divide;	//®”
	point1 = general % divide;	//­”
	point1 = (int)(((float)(point1 / divide)) * 10);
	switch(point1)
	{
		case 0:case 1:case 2:case 3:case 4:
			callculation = integer;
			break;
		case 5:case 6:case 7:case 8:case 9:
			callculation = integer + 1;
			break;
	}
	return callculation;
}

double C_Calculate::AttributeAffinity(int standard,int comparison)
{
	double attributepoint;
	switch(standard)
	{
		case SALAMANDER:
			switch(comparison)
			{
				case GNOME:
					attributepoint=1.5;
					break;
				case SALAMANDER:case SYLPH:
					attributepoint=1.0;
					break;
				case UNDINE:
					attributepoint=0.5;
					break;
			}
			break;
		case UNDINE:
			switch(comparison)
			{
				case SALAMANDER:
					attributepoint=1.5;
					break;
				case UNDINE:case GNOME:
					attributepoint=1.0;
					break;
				case SYLPH:
					attributepoint=0.5;
					break;
			}
			break;
		case SYLPH:
			switch(comparison)
			{
				case UNDINE:
					attributepoint=1.5;
					break;
				case SALAMANDER:case SYLPH:
					attributepoint=1.0;
					break;
				case GNOME:
					attributepoint=0.5;
					break;
			}
			break;
		case GNOME:
			switch(comparison)
			{
				case SYLPH:
					attributepoint=1.5;
					break;
				case UNDINE:case GNOME:
					attributepoint=1.0;
					break;
				case SALAMANDER:
					attributepoint=0.5;
					break;
			}
			break;
	}
	return attributepoint;
}

double C_Calculate::RioDeDamage(int mg_offense)
{
	double damege = 0;
	damege = mg_offense*1.3*2.5;
	return damege;
}

double C_Calculate::VanDamage(int offense)
{
	double damege = 0;
	damege = offense*1.3*2.5;
	return damege;
}

double C_Calculate::ZionDamage(int offense, int dif)
{
	double damege = 0;
	damege = (offense * 1.4 - dif)* 0.33;
	return damege;
}