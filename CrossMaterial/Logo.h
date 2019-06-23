#pragma once

/************************************************************************************
 *																					*
 *	�����F���S��ʂ̊Ǘ�������														*
 *																					*
 *	�����F���S��ʂ�Control��Render������܂�										*
 *																					*
 *	�쐬���F2008�N 8�� 6��															*
 *																					*
 *	�X�V���F2009�N 2�� 5��															*
 *													by	�����@�F�T					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include"Scene.h"

/*================================
	
		Define����

=================================*/
#define LOGO_END_COUNT			(220)		//���S�I���J�E���g
#define TEXTURE_SIZE_LOGO		(1024.0f)	//�e�N�X�`���̃T�C�Y
#define MAX_TEXTURE_LOGO		(4)			//���S��ʂŎg���e�N�X�`���̐�

enum TEXTURE_LOGO
{
	T_TEAM_LOGO,

	MAX_LOGO_TEXTURE,
};

enum DATA_LOGO
{
	D_TEAM_LOGO,	

	MAX_STAGE_DATA,
};

enum LOGO_SOUND_DATA	//���S�̃T�E���h�f�[�^
{
	S_LOGO_1,
	S_LOGO_2,
	S_LOGO_3,
	S_LOGO_4,
	S_LOGO_5,

	MAX_S_LOGO,
};
class C_Logo : public C_Scene
{
	private:
		int use_texture;	//�g�p����摜�̖������i�[����B

		int time_count;		//���S�̃^�C���J�E���g�B
	
		int alpha;			//���S�̃A���t�@�l��ύX����B

		int randum_voice;

		bool flag_soundstop;
	
	public:
		C_Logo(C_DGraphics *in_graphics);//�R���X�g���N�^
		
		~C_Logo();	//�f�X�g���N�^
		
		void Init();

		void Control(int* key);			//�R���g���[��
		
		void Draw();						//�`��
		
		void Sound();						//�T�E���h�̊Ǘ�
		
		void Release();						//���
		
		void FadeControl(); 				//�t�F�[�h����

};