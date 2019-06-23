#pragma once

/************************************************************************************
 *																					*
 *	�����F�V�[���̊��N���X														*
 *																					*
 *	�����F�V�[���̊��N���X														*
 *																					*
 *	�쐬���F2008�N 11��30��															*
 *																					*
 *	�X�V���F2009�N 2�� 20��															*
 *													by	���� ���F					*
 *													�X�V�@�O�� �j					*
 ************************************************************************************/

/*================================

		INCLUDE����

=================================*/
#include "Control.h"
#include "DirectGraphics.h"
#include "DirectSound.h"
#include "Define.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


class C_Scene
{
	protected:
		C_Control			*p_control;			//�R���g���[���N���X�ւ̃|�C���^
		
		C_DGraphics			*m_graphics;		//C_DGraphics�̃I�u�W�F�N�g�����w��
		
		LPDIRECT3DTEXTURE9	*m_pTexture;		//�e�N�X�`���f�[�^
	
		LPDIRECT3DTEXTURE9  *pChara;
		
		F_RECT *getRect;						//�摜�f�[�^��Rect���

		int					m_max_texture;		//�e�N�X�`������
		
		int					m_max_sound;		//�T�E���h�f�[�^��
		
		int					m_scene_flag;		//���݂̃V�[�����𔻒f����B

		int					*m_scene_number;	//�V�[�����̋�؂�𔻒f����B

		int					*m_scene_num[MAX_SCENE];//�V�[�����̂ǂ�����n�߂邩(ADV�Ȃ�AADV�p�[�g�̉��b���Ȃ�)(�ǉ�)
		
		int					m_count_fade;		//�t�F�[�h�̉�

		int					m_alpha_load;

		bool				m_flag_fade;		//�t�F�[�h�C���E�A�E�g�̃t���O
			
		char				**m_p_sound_file;	//�T�E���h�t�@�C����
		
		char				*m_scene_name;		//���݂̃V�[�������w�肷��B
	
	public:

		virtual void Control(int *key) = 0;		//�R���g���[��
		
		virtual void Draw()    = 0;				//�`��

		virtual void Init()    = 0;				//������

		virtual void Sound()   = 0;				//�T�E���h�̊Ǘ�	

		virtual void Release() = 0;				//���

		/************************************************************************************
		*	����	�F���̃V�[���ڍs���ɂ����鎞�Ԃ̊ԂɁwNowLoading�x��_�ŕ\������		*
		*	����	�F�Ȃ�																	*
		*	�߂�l	�F�Ȃ�																	*
		*													by	�O��@�j					*
		************************************************************************************/
		void NowLoading();	

		/************************************************************************************
		*	����	�F�V�[�����ڍs������B�wNowLoading�x��_�ŕ\������						*
		*	����	�Fint scene_flag�@	�ڍs��̃V�[���t���O								*
		*	�߂�l	�F�Ȃ�																	*
		*													by	�O��@�j					*
		************************************************************************************/
		void NowLoading(int scene_flag);	

		/************************************************************************************
		*	����	�F�V�[���ڍs�{�V�[�����ݒ�B�wNowLoading�x��_�ŕ\������				*
		*	����	�Fint scene_flag�@	�ڍs��̃V�[���t���O								*
		*			�Fint scene_number�@�ڍs�V�[�����̔ԍ�									*
		*	�߂�l	�F�Ȃ�																	*
		*													by	�O��@�j					*
		************************************************************************************/
		void NowLoading(int scene_flag, int scene_number);	

		/************************************************************************************
		 *	����	�F���݂̃V�[���̒��̏���(��:�wADV�p�[�g�x�́w1�b�x�Ȃ�)���Z�b�g����		*
		 *	����	�Fint m_scene_flag		���݂̃V�[��									*
		 *			  int *scene_number		�V�[���̏���									*
		 *	�߂�l	�F�Ȃ�																	*
		 *													by	�O��@�j					*
		 ************************************************************************************/
		void SetSceneNum(int m_scene_flag,int *m_scene_number) {m_scene_num[m_scene_flag] = m_scene_number;}

		/************************************************************************************
		 *	����	�F���݂̃V�[���̒��̏���(��:�wADV�p�[�g�x�́w1�b�x�Ȃ�)���Ƃ��Ă���		*
		 *	����	�F�Ȃ�																	*
		 *	�߂�l	�Fint scene_no															*
		 *													by	�O��@�j					*
		 ************************************************************************************/
		int* GetSceneNum(int m_scene_flag)  {return m_scene_num[m_scene_flag];}	
		
		void SoundLoad(char *m_scene_name);					//�T�E���h�f�[�^��ǂݍ��ށB

		void SetName(char* name) {m_scene_name = name;}		//�V�[���؂�ւ���̃V�[�������Z�b�g���Ȃ����B

		void SetFRect(F_RECT *get)	{getRect = get;}		//Rect�̒l���Z�b�g����B

		int GetSceneFlag() {return m_scene_flag;}			//m_scene_flag���擾����B

		void SetTextureData(LPDIRECT3DTEXTURE9 *get) {pChara = get;}	//�e�N�X�`�������Z�b�g����B

		LPDIRECT3DTEXTURE9 *GetTexture() {return &m_pTexture[0];}			//�e�N�X�`�������擾����B

};

		
