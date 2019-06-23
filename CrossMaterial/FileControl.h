#pragma once

/************************************************************************************
 *																					*
 *	�����F�t�@�C���̓ǂݍ��݂����܂�												*
 *																					*
 *	�����F�e�L�X�g�t�@�C�����當����l��ǂݍ��݃Z�b�g���܂�						*
 *																					*
 *	�쐬���F2009�N 2 ��15��															*
 *																					*
 *	�X�V���F�N �� ��																*
 *													by	�O��@�j					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE


=================================*/
#include<stdio.h>
#include<string.h>

#include"Define.h"

/*================================
	
		Define

=================================*/

enum TEXT_FOLDER
{
	FOLDER_GRAPHIC,			//�G�̃t�H���_
	FOLDER_SOUND,			//���̃t�H���_
	FOLDER_SCRIPT,			//�X�N���v�g�̃t�H���_
	FOLDER_RECT,			//��`���̃t�H���_

	MAX_FOLDER,
};

class C_FileControl
{
private:
	FILE *fp;
	errno_t err;
	int		string_section[MAX_FOLDER];			//�e�L�X�g�t�@�C���̍s���𔻒f����B
	char	l_talk_no[MAX_STRING];				//�ǂݍ��ވׂ̕�����i�[�p
	char	text_buffer[MAX_STRING];			//��b�E�B���h�E1�s������̍ő啶����

public:
	C_FileControl(void);

	//�������֐�
	void Init();
	void Init(int folder_num);

	/*********************************************************************************
	�e�L�X�g�f�[�^�̓ǂݍ���
	�֐���	:char** SetText(char* filefolder,char* filename, char** file_string, int kind_folder)
	����	:char*	filefolder			�t�@�C���̂���t�H���_�����w��
			:char*	filename			�t�@�C�������w��
			:char** file_string			�t�@�C���̒��ɂ��镶���f�[�^���i�[����
			:int	kind_folder			�t�H���_�̎�ނ��w��
	�߂�l	:����	char**	file_string	��������擾
			 ���s	0					�t�@�C�����Ȃ��ꍇ
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��
	�X�V���e:�Ȃ�
	*********************************************************************************/
	char** SetText(char* filefolder,char* filename, char** file_string, int kind_folder);

	/*********************************************************************************
	�ǂݍ��񂾃e�L�X�g�̍s�����擾
	�֐���	:int�@GetSectionint kind_folder) { return string_section[kind_folder]; }
	����	:int�@kind_folder		�t�H���_�̎��
	�߂�l	:string_section[kindfolder]		�w�肵���t�H���_�̕�����̍s�����擾
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��	�X�V���e:�Ȃ�
	*********************************************************************************/
	int GetSection(int kind_folder){ return string_section[kind_folder]; }	//�e�L�X�g�̍s����Ԃ��܂�

	~C_FileControl(void);
};
