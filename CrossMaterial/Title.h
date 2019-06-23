#pragma once

/************************************************************************************
 *																					*
 *	�����F�^�C�g����ʂ̊Ǘ������܂�												*
 *																					*
 *	�����F�^�C�g����ʂ�Control��Render������܂�									*
 *																					*
 *	�쐬���F2008�N 8�� 6��															*
 *																					*
 *	�X�V���F2009�N 2��28��															*
 *													by	�����@�F�T					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include "Scene.h"
#include "PlayerCommon.h"

/*================================
	
		Define

=================================*/
#define TITLE_ALPHA_INCREASE		(5)		//�A���t�@�l�̑�����
#define	TITLE_MAX_ALPHA				(255)	//�A���t�@�l�̍ő�
#define D_T_MENU_C_Y				(430.0f)//�I������Y�̒��S���W

//�ǉ� 3/10�O�に
#define DRAW_CURSOR_X				(0.1f)
#define DRAW_CURSOR_Y				(0.1f)
#define DRAW_BG_POS_X				(400.0f)//�Q�[����ʂ̒��SX
#define DRAW_BG_POS_Y				(300.0f)//�Q�[����ʂ̒��SY
//�ǉ� 3/10�O�な

enum TEXTURE_DATA_TITLE		//�^�C�g����ʂ̃e�N�X�`���f�[�^
{
	T_TITLE_BG,		//�w�i
	T_TITLE_FC,		//�^�C�g���Ɏg���t�H���g
	T_TITLE_CORSOR,
	T_TITLE_LOADING,

	T_TITLE_MAX,
};

enum RECT_DATA_TITLE	//�^�C�g���̋�`�f�[�^
{
	R_TITLE_BG,		//�w�i
	R_TITLE_START,	//�uSTART�v�̕���
	//R_TITLE_LOAD,	//�uLOAD�v�̕���
	R_TITLE_END,	//�uEND�v�̕���
	//R_TITLE_SAVE1,	//�uSAVE1�v
	//R_TITLE_SAVE2,	//�uSAVE2�v
	//R_TITLE_SAVE3,	//�uSAVE3�v
	R_TITLE_ICON,	//�A�C�R��
	R_TITLE_LOADING,//LOADING
	
	R_TITLE_MAX,
};

enum TITLE_SOUND_DATA	//�^�C�g���̃T�E���h�f�[�^
{
	S_TITLE_BGM,
	S_TITLE_SELECT,
	S_TITLE_ENTER,
	S_TITLE_CANCEL,

	MAX_S_TITLE,
};

enum MENU_SCENE
{
	M_START,
	//M_LOAD,
	M_END,

	M_MAX,
};

class C_Title : public C_Scene
{
private:
	C_PlayerCommon p_data;

	int use_texture;			//�g�p����摜�̖������i�[����B

	int alpha;					//�A���t�@�l
	
	int alpha_count;			//�A���t�@�̃J�E���g
	
	int menu_flag;				//���j���[�t���O

	int f_menu_alpha;			//���j���[�t�H���g�̃A���t�@�l

	int title_draw_flag;		//SAVE�̃t�H���g�̃t���O

	int fade_flag;				//�t�F�[�h�C���A�t�F�[�h�A�E�g�̃t���O

	//�ǉ�
	float cursor_draw_x;
	float cursor_draw_y;
	float keep_pos_y;

	//int  m_count_fade_title;		//�t�F�[�h�̉�

	//bool m_flag_fade_title;		//�t�F�[�h�C���E�A�E�g�̃t���O

public:
	C_Title(C_DGraphics *graphic);//�R���X�g���N�^

	~C_Title(void);				//�f�X�g���N�^

	void Control(int *key);

	void FadeControl();			//�t�F�[�h�R���g���[��

	void FadeIn();				//�t�F�[�h�C��

	void FadeOut();				//�t�F�[�h�A�E�g

	void MenuDraw();			//���j���[�`��

	void SaveDraw();			//�Z�[�u�f�[�^�`��

	void CursorDraw();

	void Init();

	void Draw();

	void Sound();				//�T�E���h�̊Ǘ�

	void Release();

	/*********************************************************************************
	�J�[�\���̕`��Ǘ�
	�֐���	:void DrawCursur()
	����	:�Ȃ�
	�߂�l	:�Ȃ�
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��	�X�V���e:�Ȃ�
	*********************************************************************************/
	void DrawCursor();

};