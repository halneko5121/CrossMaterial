#pragma once

/************************************************************************************
 *																					*
 *	�����F�v�����[�O���Ǘ����܂�													*
 *																					*
 *	�����F���E�ϐ������ڍׁ����炷��(�{�҂ɑ���)���{��								*
 *																					*
 *	�쐬���F2008�N 12�� 5��															*
 *																					*
 *	�X�V���F2008�N 2�� 20��															*
 *													by	�O��@�j					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include"Scene.h"

/*================================
	
		Define����

=================================*/
#define MAX_TEXTURE_PROLOGUE	(5)
//�`��ʒu
#define POS_BG_PROLOGUE_X	(400.0f)
#define POS_BG_PROLOGUE_Y	(300.0f)

#define POS_WORLD1_LINE1_X	(50.0f)
#define POS_WORLD1_LINE1_Y	(200.0f)
#define POS_WORLD1_LINE2_X	(150.0f)
#define POS_WORLD1_LINE2_Y	(300.0f)
#define POS_WORLD1_LINE3_X	(250.0f)
#define POS_WORLD1_LINE3_Y	(400.0f)

#define POS_WORLD2_X		(80.0f)
#define POS_WORLD2_Y		(600.0f)

//���͐؂�ւ��n
//#define COUNT_CHANGE		(200)		//���͂�؂�ւ��Ă�������
#define R_SLIDE_SIZE		(90.0f)		//�؂��镶�͂����炷��(�Љ�1)
#define R_SLIDE_SIZE2		(150.0f)	//�؂��镶�͂����炷��(�Љ�2)
#define MAX_SLIDE			(19)		//�؂���X���C�h���s����(�Љ�1)
#define MAX_SLIDE2			(11)		//�؂���X���C�h���s����(�Љ�2)
#define FONTSIZE			(30.f)	
//���̓t�F�[�h�n
#define FADE_TIME			(300)		//�t�F�[�h�����鑬��
#define FADE_SPEED_PRO		(5)			
#define MAX_ALPHA			(255)		//�A���t�@�l�ő�
#define ALPHA_CHANGE		(10)		//�A���t�@�l�ω���(����1)

//���̓X���C�h
#define SLIDE_SPEED_WORLD2	(10.0f)		//�X���C�h�����鑬��(�����ڍ�)
#define SLIDE_SPEED_PLOT	(0.5f)		//�X���C�h�����鑬��(���炷��)
#define WAIT_TIME			(400)		//�X���C�h���~�߂Ă�������
#define WAIT_POS			(250.0f)	//���̈ʒu�܂ŗ�����STOP!
#define SLIDE_RETURN		(-150.0f)	//���̈ʒu�܂ŗ��������x�����炨����
#define NEXTSTORY_POS		(-1800.0f)	//���̈ʒu�܂ŗ�������v�����[�O�I���B�{�҂�

enum TEXTURE_PROLOGUE		//TEXTURE(�����t�@�C��)�̔ԍ�
{
	T_BG_PROLOGUE,			//�w�i
	T_WRITING,				//���͉摜�f�[�^
	T_PRO_LOADING,

	T_MAX_PROLOGUE,
};

enum RECT_PROLOGUE			//��`�̔ԍ�
{
	R_BG_PROLOGUE,			//�w�i
	R_WORLD1_1LINE,			//���E�ϏЉ�(���͉摜�f�[�^)
	R_WORLD1_2LINE,			//���E�ϏЉ�(���͉摜�f�[�^)
	R_WORLD1_3LINE,			//���E�ϏЉ�(���͉摜�f�[�^)
	R_WORLD2,				//���E�ϏЉ�ڍ�(���͉摜�f�[�^)
	R_PLOT,					//���炷���@(���͉摜�f�[�^)
	R_PRO_LOADING,
	
	R_MAX_PROLOGUE,
};

enum SOUND_PROLOGUE
{
	S_WORLD1_2,
	S_PLOT,
};

class C_Prologue : public C_Scene
{
	private:
		int use_texture;			//�g�p����摜�̖������i�[����B
		int use_sound;
		int count_fade_pro;			//���炷���Ȃǂ̕��͂̃t�F�[�h����
		int alpha;					//���͂̃A���t�@�l��ύX����B
		int alpha2;					
		int rect_slide;				//���͂�؂���ʒu���X���C�h�����Ă���
		int count_wait;				//�҂�����

		float pos_slide;			//�`��ʒu(y�����������ď�֗����܂�)

	public:
		C_Prologue(C_DGraphics* graphic);
		void Init();
		void Control(int* key);
		void Draw();
		void Sound();				//�T�E���h�̊Ǘ�
		void Release();

		void SlideRect();			//��s���؂���ʒu�����炷
		void FadeIn();				//�t�F�[�h�C������
		void FadeOut();				//�t�F�[�h�A�E�g����
		void Slide();				//�`��ʒu���X���C�h
		void ShortCutKey(int* key);
		void DebugKey(int* key);

		~C_Prologue();
};
