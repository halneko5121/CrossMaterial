#pragma once
/************************************************************************************
 *																					*
 *	�����F�v�Z�������Ǘ����܂�														*
 *																					*
 *	�����F�o�g���̌v�Z�����i�_���[�W�A�񕜁A�l�o�����Ȃǁj							*
 *																					*
 *	�쐬���F2009�N1��28��															*
 *																					*
 *	�X�V���F2008�N1��28��															*
 *													by	����						*
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
	
		Define����

=================================*/
#define RECOVERYMATH	(3)
#define CRITICALMATH	(2)
#define MGMATH	(10)


class C_Calculate/*public C_EnemyCommon : public C_PlayerCommon*/
{
private:
	int hit_math;	//�������̌v�Z����

	int hit_fate;	//�����_���̌���
	
	int critical_math;	//�N���e�B�J���̌v�Z����
	
	int critical_fate;	//�N���e�B�J���̃����_������
	
	int integer;	//����
	
	int point1;	//�����_��1��
	
	//int point2;	//�����_��2��
public:
	C_Calculate(void);
	~C_Calculate(void);

	void Init();

	void Draw();

	double RioDeDamage(int mg_offense);
	double VanDamage(int offense);
	double ZionDamage(int offense,int dif);

	int HitResult(int hitrate,int evasion);	//�������̔��菈��(������,���)

	double NormalAttackDamage(int offense,int defense);	//�ʏ�U���̃_���[�W����(�U����,�h���)

	double SpecialAttackDamage(int offense,int mg_offense,double topography,double attribute,int defense,int mg_resistance,int id);	//����U���̃_���[�W����(�U����,���@�U����,�n�`����,��������,�h���,���@��R��)

	int SpecialRecovery(int lifemax);	//����񕜂̑�������(�ő�HP)

	int SuperAttackDamage(int n_damege);	//���K�E�̃_���[�W����(�ʏ�U���̃_���[�W)

	double Critical(int probability);	//�N���e�B�J�����菈��(�N���e�B�J��)

	int MGPlus(int enemy_no);	//MG�Q�[�W��������(�_���[�W,�ő�AP)

	int RoundOff(int general,int divide);	//�l�̌ܓ�����(�S��,����l)

	double AttributeAffinity(int standard,int comparison);	//�������ʏ���(�U��������L�����̑���,�󂯂�L�����̑���)
};
