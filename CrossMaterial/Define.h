#pragma once

/************************************************************************************
 *																					*
 *	�����F�Q�[���S�̂�define�̒�`													*
 *																					*
 *	�����F																			*
 *																					*
 *	�쐬���F2008�N 12�� 5��															*
 *																					*
 *	�X�V���F2008�N 2�� 20��															*
 *													by	�O��@�j�@���̑�			*
 *																					*
 ************************************************************************************/

#define DEBUG


#define MAX_STRING	( 64)		//�t�@�C���̍ő啶�������w��	
#define MAX_ARGB	(255) 	
#define	MAX_ALPHA	(255)		//�A���t�@�l�̍ő�


enum SCENE_NUM		//�V�[���̔ԍ�
{
	LOGO,			//���S
	TITLE,			//�^�C�g��
	PROLOGUE,		//�v�����[�O
	ADV_SCENE,		//�A�h�x���`���[�p�[�g
	BATTLE_SCENE,	//�o�g���p�[�g
	GAMEOVER,		//�Q�[���I�[�o�[
	ENDING,

	MAX_SCENE,
};

//ADV���V�[��
enum TEXT_STORY
{
	TEXT_PROLOGUE,							//�v�����[�O
	TEXT_STORY3_1,							//��O�b(1)
	TEXT_STORY3_2,							//��O�b(2)
	TEXT_STORY3_3,							//��O�b(3)
	TEXT_BATTLE_BEFORE,						//�퓬�O�̃V�[��
	TEXT_EPILOGUE,							//�G�s���[�O
	TEXT_ENDING_1,							//�G���f�B���O(�X�^�b�t���[���Ȃ�)

	MAX_TEXTNAME,
};

//�v�����[�O���V�[��
enum SCENE_PROLOGUE
{
	SCENE_WORLD1,						//���E�ϐ���1
	SCENE_WORLD2,						//���E�ϐ���2(�ׂ����Љ�)
	SCENE_PLOT,							//ADV�̃v�����[�O���I�������B�{�҂֌q���邠�炷���V�[��
};

enum KEY_TYPE	//�L�[���𔻒f����B
{
	NO_PUSH,	
	UP_PUSH,
	DOWN_PUSH,
	LEFT_PUSH,
	RIGHT_PUSH,
	UP_PRESS,
	DOWN_PRESS,
	LEFT_PRESS,
	RIGHT_PRESS,
	Z_PUSH,
	X_PUSH,
	A_PUSH,
	C_PUSH,
	S_PUSH,

	KEY_MAX,
};
