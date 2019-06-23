#pragma once

/************************************************************************************
 *																					*
 *	�����F�X�e�[�W�̊Ǘ������܂�													*
 *																					*
 *	�����FMAPTIP�Efield�֌W�̊Ǘ�													*
 *																					*
 *	�쐬���F2008�N 11�� 24��														*
 *																					*
 *	�X�V���F2008�N ����																*
 *													by	����@�w					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include <stdio.h>
#include <string.h>

#include "D_Battle.h"

#include "DirectGraphics.h"
#include "Define.h"
/*================================
	
		Define

=================================*/
#define MAX_TEXTURE_STAGE		(20)			//�e�N�X�`���[�̐�

#define TEXTURE_SIZE_X			(512.0f)		//�����t�@�C���̃T�C�YX
#define TEXTURE_SIZE_Y			(512.0f)		//�����t�@�C���̃T�C�YY

#define SLIDE_X					(50)			//�����X���C�h�������
#define SLIDE_Y					(25)			//�����X���C�h�������

#define CENTER_POSITION_X			(400.0f)	//MAPTIP�̏����z�u�ʒuX
#define CENTER_POSITION_Y		(300.0f)		//MAPTIP�̏����z�u�ʒuY

#define MAX_MAPTIP				(400)			//MAPTIP�̑���
#define BLANK					(0)

enum MAPTIP_ID				//�ǂ�MAPTIP���𔻒f
{
	MAPTIP_BLANK,
	MAPTIP_CACTUS1,		//�T�{�e��1
	MAPTIP_CACTUS2,			//�T�{�e��2
	MAPTIP_ROCK1,			//���1
	MAPTIP_ROCK2,			//���2
	MAPTIP_SAND1,			//���n1
	MAPTIP_SAND2,			//���n2
	MAPTIP_SAND3,			//���n3
	MAPTIP_SAND4,			//���n4
	MAPTIP_GREEN1,			//���n1
	MAPTIP_GREEN2,			//���n1
	MAPTIP_GREEN3,			//���n1
	MAPTIP_GREEN4,			//���n1
	MAPTIP_CHOICE,			//�ړ��E�U���\�͈͕\����MAPTIP
};

enum FLAG_STAGE				//MAPTIP�̐����ʂ�b���ɂ���ĕύX		
{				
	STAGE_FIRST,
	STAGE_SECOND,
	STAGE_LAST
};

enum FLAG_STORY				//���b�ڂ��̔��f
{
	ACTION_CHOICE,			//�s���\�͈͕\���̎��g�p
	STORY_FIRST,			
	STORY_SECOND,
	STORY_LAST

};

enum UNIT_ID{
	U_BLANK_AREA	=  0,
	U_ZION			= 10,
	U_VAN			= 20,
	U_RIO			= 30,
	U_SAHAGIN1		= 40,
	U_SAHAGIN2		= 50,
	U_LIZARDMAN1	= 60,
	U_LIZARDMAN2	= 70,
	U_LIZARDMAN3	= 80,
	U_BOSS			= 90,
};

/*================================
	
		Struct

=================================*/


class C_Stage
{
private:
	//MAPTIP�֌W
	int maptip_wide;									//�b���ɂ����MAPTIP�̐�����ύX(��)	
	int maptip_length;									//�b���ɂ����MAPTIP�̐�����ύX(�c)
	
	FIELD_POS field[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];//MAPTIP��x���Wy���W��ۑ�
	//�o�g���t�B�[���h�̒l��ۑ�
	int field_maptip[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];
	int field_character[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];

	FIELD_POS field_pos[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];	//
	
	int maptip_x;										//�ǂꂾ��
	int maptip_y;											
	int flag_story;										//���b�ڂ����f		

	int char_max;

	int area_distance;			//�͈͂�ۑ�(distance ����)
	int keep_id;
	//2/12�ǉ�(nisii)
	int keep_cmd;				//�I�΂�Ă����R�}���h��ۑ�

	int char_position_x_keep;	//�L�����ʒu���L�[�v���Ă���(��)
	int char_position_y_keep;	//��ɓ���(��)

	int area_info[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];		//�ړ��\�ʒu������

	int player_max;
	int enemy_max;
public:
	void Control(int * key);

	void FieldControl(int x,int y);		//�}�b�v�`�b�v�̕`��ʒu�����߂�

	void Draw();
	void Sound();						//�T�E���h�̊Ǘ�
	void Release();

	/************************************************************************************
	 *	����	�FMAPTIP�̔z��̐���b���ɉ����Č��߂�									*
	 *	����	�F�Ȃ�																	*
	 *	�߂�l	�F�Ȃ�																	*
	 *													by	�O��@�j					*
	 ************************************************************************************/
	void Init();						

	/************************************************************************************
	 *	����	�F//MAPTIP��z���SET����B�}�b�v�`�b�v�Ȃǂ�TEXT����ǂݍ���			*
	 *	����	�F�Ȃ�																	*
	 *	�߂�l	�F�Ȃ�																	*
	 *													by	�O��@�j					*
	 ************************************************************************************/
	void SetMaptip();

	void AreaSeach(int char_position_x,int char_position_y,int unit_id,int distance,int char_commando);			//�ړ��ł���G���A���Z�o(��)
	void AreaDeleat();				//�ړ��ł���G���A�̏������E����

	int IdSeach(int x,int y);		//����ID���ǂ̃L�����Ȃ̂��𔻕ʂ���

	int GameStateSeach();	//�Q�[���̏�(�Q�[���I�[�o�[�E�Q�[���N���A)���Z�o���ʂ��o��
	
public:
	int GetMaptipXData()		{return maptip_x;}
	int GetMaptipYData()		{return maptip_y;}

	int GetFieldMaptipData(int x,int y)	{return field_maptip[x][y];}			//�t�B�[���h�ɉ������邩���擾(�e�|�W�V������)
	int GetFieldMaptipData(COORDINATE no)	{return field_maptip[no.x][no.y];}		//�t�B�[���h�ɉ������邩���擾(�\���̔�)

	FIELD_POS GetFieldPositionData(int x,int y)	{return field[x][y];}		//�t�B�[���h�̕\���ʒu���擾(�e�|�W�V������)
	FIELD_POS GetFieldPositionData(COORDINATE no)	{return field[no.x][no.y];}		//�t�B�[���h�̕\���ʒu���擾(�\���̔�)

	int GetAreaInfoData(int x,int y)	{return area_info[x][y];}				//�e�H���̃G���A���擾

	int GetEnemyMax()	{return enemy_max;}
	void DecEnemy(int dec)		{enemy_max -= dec;}
	int GetPlayerMax()	{return player_max;}
	int GetCharMaxData()	{return char_max;}										//�L�����̍ő吔���擾����

	int GetFieldCharacterData(int x,int y)	{return field_character[x][y];}	//�t�B�[���h�ɃL���������邩���擾(�e�|�W�V������)
	
	void SetFieldCharacterData(COORDINATE no,int data)	{field_character[no.x][no.y] = data;}	//�L�����f�[�^���X�V(�����)
	void SetFieldCharacterData(int x,int y,int data)	{field_character[x][y] = data;}
public:
	C_Stage(void);
	~C_Stage(void);
};

