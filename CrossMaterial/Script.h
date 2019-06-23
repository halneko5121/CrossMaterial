#pragma once
/************************************************************************************
 *																					*
 *	�����F�X�N���v�g�̊Ǘ������܂�													*
 *																					*
 *	�����FADV�p�[�g�ɂ������b�ȂǂȂǂ��e�L�X�g�ŊǗ��ł���						*
 *																					*
 *	�쐬���F2008�N 11�� 24��														*
 *																					*
 *	�X�V���F2009�N 2��	27��														*
 *													by	�O��@�j					*
 *																					*
 ************************************************************************************/

/*================================
		INCLUDE
=================================*/
#include <stdio.h>
#include <string.h>
#include "Define.h"

#include "DirectGraphics.h"
#include "DirectFont.h"
#include "DirectSound.h"
#include "FileControl.h"
#include "Control.h"
#include "ScriptDefine.h"

/*================================
		Define
=================================*/
//ScriptDefine.h�ɂĒ�`

class C_Script 
{
private:
	C_DGraphics			*graphics;				//DGraphics�N���X�̃C���X�^���X
	LPDIRECT3DTEXTURE9	*pTexture;				//�e�N�X�`���f�[�^	
	DFont				*pFont;					//Font�N���X�ւ̃|�C���^
	F_RECT				rect_adventure[R_MAX_ADV];		//��`���
	C_FileControl		*pFcontrol;

	int use_texture;							//�g�p����摜�̖������i�[����B

	char **string_talk;							//��b�����i�[����|�C���^�ϐ�
	char **string_sound;						//�T�E���h�t�@�C�������i�[
	char **string_graphic;						//CG�t�@�C�������i�[
	char **string_cg_rect;						//CG�t�@�C���̋�`���l���i�[
	char word_copy[KIND_MAX][MAX_STRING];		//�X�N���v�g�̎�ޕʂɕ�������i�[����z��
	char draw_string[TALK_MAXLINE][MAX_STRING];

	int  now_scene;								//ADV�̉��̃V�[��������
	int	 setline;							    //���݂̍s�̈ʒu
	int  drawline;								//�`��̍s�̈ʒu�B
	int  string_section[MAX_FOLDER];			//�e�L�X�g�t�@�C���̍s���𔻒f����B
	int	 flag_talkend;	     					//��b�̏I���𔻒f����B(���b�ڂ̂�)	
	int  next_icon_y;
	int  roop_soundnum; int  keep_soundnum;						
	
	int  quake_x; int  quake_y;
	int	 kind_quake;
	int  count_quake;
	int  flag_quake_continue;

	int	 alpha;
	int  alpha_pendant;
	int	 alpha_fla;
	int  count_fla;	
	int  auto_wait;

	bool flag_nexticon;
	bool flag_stopline;	 						//TRUE�ɂȂ�ƁA�L�[���͂��s����܂ŕ���������X�g�b�v����B
	bool flag_window_msg;						//��b�E�B���h�E�̕\���t���O
	bool flag_quake_x; bool flag_quake_y;
	bool flag_flash;
	bool flag_pendant;
	bool flag_auto;
	bool flag_skip;

	float fade_b[MAX_CHARAPOS];					//bottom
	float fade_t[MAX_CHARAPOS];					//top
	float fade_l[MAX_CHARAPOS];					//left
	float fade_r[MAX_CHARAPOS];					//right
	float slide_char_x; 
	float slide_char2_x; 
	float convert_rev;
	float chara_height[2];

public:
	C_Script(C_DGraphics* graphic);
			
	void Control(int* key);						//�R���g���[��

	void Draw();								//�`��

	void Init(int text_num);					//�f�[�^�̏��������s���B
	
	void Release();								//���

	void DrawTalk();							//���͂̕`��

	/*********************************************************************************
	��b�̏I���𔻒f����
	�֐���	:void TalkEnd(int* key)
	����	:int* key				�L�[���
	�߂�l	:�Ȃ�
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��	�X�V���e:�Ȃ�
	*********************************************************************************/
	void TalkEnd(int* key);					

	/*********************************************************************************
	//�ǂݍ��񂾕��͂�`��p�ɓn��
	�֐���	:void StringAdvanced(int* key)
	����	:�Ȃ�	�߂�l	:�Ȃ�
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��	�X�V���e:�Ȃ�
	*********************************************************************************/
	void StringAdvanced();

	/*********************************************************************************
	�X�N���v�g(�`��֌W)�̃L�[���[�h�Z�b�g
	�֐���	:void SetScript(int max_namedata, char* text_data[], int scriptnum, int* key);
	����	:int max_namedata		�������������O�̍ő吔
			:char* text_data[]		�������镶�����i�[���ꂽchar�^�ւ̃|�C���^	
			:int scriptnum			�X�N���v�g�̎��
			(���� 0:�w�i 1:���ݒn���{�g 2:�L������ 3:���ʒu�̃L���� 4:�E�ʒu�̃L�����̑���)
			:int* key				�L�[���
	�߂�l	:�Ȃ�
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��	�X�V���e:�Ȃ�
	*********************************************************************************/
	void SetScript(int max_namedata, char* text_data[], int scriptnum ,int * key);

	/*********************************************************************************
	�`��X�N���v�g(�Z�b�g���ꂽ�L�[���[�h�ɉ������������s��)
	�֐���	:void DrawScript(int max_data, char* text_data[], int scriptnum);			
	����	:int max_data			�������������O�̍ő吔
			:char* text_data[]		�������镶�����i�[���ꂽchar�^�ւ̃|�C���^	
			:int scriptnum			�X�N���v�g�̎��(���� 0:�w�i 1:���ݒn���{�g 2:�L������ 3:���ʒu�̃L���� 4:�E�ʒu�̃L�����̑���)
			:int* key				�L�[���
	�߂�l	:�Ȃ�
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��	�X�V���e:�Ȃ�
	*********************************************************************************/
	void DrawScript(int max_data, char* text_data[], int scriptnum);			

	/*********************************************************************************
	�L�����̕`��(�q�b�g�����ԍ��ɉ������L�����̕`����s��)
	�֐���	:void DrawChara(int scriptnum, int i);
	����	:int scriptnum			�X�N���v�g�̎��
			:int i�@				�q�b�g�����L�������̔ԍ�	
	�߂�l	:�Ȃ�
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��	�X�V���e:�Ȃ�
	*********************************************************************************/
	void DrawChara(int scriptnum, int i);

//	void S_SoundLoad();							//�T�E���h�̓ǂݍ���
	void S_SoundPlay_or_Stop();					//�T�E���h�f�[�^�̍Đ��E��~����

	void CharaSlide();								

	void IventCheck(int *key);

	void NextIcon();

	void AutoTalk(int *key);					
	void SkipTalk(int* key);
	void SetCharaFont();						//�L�������ƂɃt�H���g�ς�

	void WordCheck(int *key);					//�e�L�[���[�h���`�F�b�N����
	void WordCheckDraw(int* key);
	void WordCheckWindow();
	void WordCheckSound();

	int GetFlagTalkEnd(){return flag_talkend;}	//�I���̃t���O��Ԃ��Ă��

	/*********************************************************************************
	for���Ō����P����������q�b�g�����ԍ��ɉ������t�F�[�h���s��
	�֐���	:void FadeControl(int script_i);
	����	:int script_i			�X�N���v�g�̎��
	�߂�l	:�Ȃ�
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��	�X�V���e:�Ȃ�
	*********************************************************************************/
	void FadeControl(int script_i);
	void FadeIn();	
	void FadeOut();
	void FadeRect_Top();				//��`��Top��������		
	void FadeRect_Bottom();				//�VBottom��������
	void FadeRect_Right();				//�VRight��������
	void FadeRect_Left();				//�VLeft��������

	/*********************************************************************************
	for���Ō����P����������q�b�g�����ԍ��ɉ�������ʌ��ʂ��s��
	�֐���	:voidScreenAction(int script_i);
	����	:int script_i			�X�N���v�g�̎��
	�߂�l	:�Ȃ�
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��	�X�V���e:�Ȃ�
	*********************************************************************************/
	void ScreenAction(int script_i);			

	/*********************************************************************************
	��ʂ̏c�h��or���h��
	�֐���	:void ActionQuake(int kind_quake);
	����	:int kind_quake		1:���h��	2:�c�h��
	�߂�l	:�Ȃ�
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��	�X�V���e:�Ȃ�
	*********************************************************************************/
	void ActionQuake(int kind_quake);			
	void ActionPendant();
	void ActionFlash();							
	
	/*********************************************************************************
	int�^������char�^�����ɕ������ăe�L�X�g���̐����̌���(for���ŉ�)
	�֐���	:void ConvertNum(int j, char* search);
	����	:int j				�������鐔��
			:char* search		������char������
	�߂�l	:�Ȃ�
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��	�X�V���e:�Ȃ�
	*********************************************************************************/
	void ConvertNum(int j, char* search);

	/*********************************************************************************
	���]���ɕ`��ʒu�����炵�ĊG�̌��؂��h�~
	�֐���	:void ConvertRev(int scriptnum);
	����	:int scriptnum		�X�N���v�g�̎��
	�߂�l	:�Ȃ�
	�쐬��	:�O��
	�X�V��	:  �N  ��  ��	�X�V���e:�Ȃ�
	*********************************************************************************/
	void ConvertRev(int scriptnum);

	void LineUpHeight(int scriptnum);

	int GetSection(int kind_folder){ return string_section[kind_folder]; }	//�e�L�X�g�̍s����Ԃ��܂�

	~C_Script(void);

};
