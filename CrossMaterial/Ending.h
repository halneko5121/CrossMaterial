#pragma once

/************************************************************************************
 *																					*
 *	�����F�G���f�B���O��ʂ̊Ǘ������܂�											*
 *																					*
 *	�����F�����������t�@�C����ς��X�^�b�t���[�����X�N���[��������			*
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
#include "Scene.h"

/*================================
	
		Define

=================================*/
#define NEXTSCENE_POS	(350.f)			// �����܂ł����玟�̃V�[��
#define SLIDE_SPEED		(1.f)		
#define MAX_STAFFNAME	(20)	
#define WAITTIME		(400)	

#define ALPHA_STOP		(100)
#define ALPHA_F_OUT		(2)
#define ALPHA_F_IN		(3)
#define LAST_ALPHA_IN	(2)
#define ALPHA_STOP		(100)

#define SP_SLIDE_POS	(1.5f)
#define SP_SLIDE_POS2	(1.5f)


enum TEXTURE_ENDING						// �G���f�B���O��ʂ̃e�N�X�`���f�[�^
{
	T_END_BACK,							// �w�i
	T_END_STAFFNAME1,					// �X�^�b�t�`�l�`��
	T_END_STAFFNAME2,					// �X�^�b�t�`�l�`��
	T_END_STAFFNAME3,					// �X�^�b�t�`�l�`��
	T_END_STAFFNAME4,					// �X�^�b�t�`�l�`��
	T_END_STAFFNAME5,					// �X�^�b�t�`�l�`��
	T_END_STAFFNAME6,					// �X�^�b�t�`�l�`��
	T_END_STAFFNAME7,					// �X�^�b�t�`�l�`��
	T_END_STAFFNAME8,					// �X�^�b�t�`�l�`��
	T_END_LASTMESSAGE,					
	T_END_LOADING,						// LOADING

	T_END_MAX,
};

enum RECT_END							// �G���f�B���O�̋�`�f�[�^
{
	R_END_BACK,							// �w�i
	R_END_STAFFNAME,					// �X�^�b�t�`�l�`��
	R_END_LASTMESSAGE1,					
	R_END_LASTMESSAGE2,					
	R_END_LASTMESSAGE3_4,					
	R_END_LASTMESSAGE5,					
	R_END_LASTMESSAGE6,					
	R_END_LASTMESSAGE7,					
	R_END_LASTMESSAGE8,					

	R_END_LOADING,						// LOADING

	R_END_MAX,
};

enum END_SOUND_DATA						// Ending�̃T�E���h�f�[�^
{
	S_END_BGM,

	MAX_S_END,
};


class C_Ending : public C_Scene
{
private:

	int 	use_texture;		//�g�p����摜�̖������i�[����B

	int		alpha_staff;
	int		count_wait;			//������Ƒ҂���
	int		count_alpha;
	int		staffroll_1;
	int		staffroll_2;
	int		fade_flag;			//�t�F�[�h�C���A�t�F�[�h�A�E�g�̃t���O
	int		stay_cnt;
	int		next_message;

	float	slide_pos;
	float	slide_pos2;				
	float 	alpha_back;			//�A���t�@�l��ύX����B

	bool	endflag;
	bool	lastflag;
	bool	lastmessage;
	bool	flag_slide_1;
	bool	flag_slide_2;
	bool	flag_lastfadein;
	bool	flag_nowloading;

private:
	void FadeControl();
	void FadeIn();
	void FadeOut();
	void Slide();
public:
	C_Ending(C_DGraphics *graphic);
	
	void Control(int* key);

	void Init();

	void Draw();

	void Sound();				//�T�E���h�̊Ǘ�

	void Release();

	~C_Ending(void);
};