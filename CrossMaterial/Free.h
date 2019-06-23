#pragma once
/************************************************************************************
 *																					*
 *	�����FFREE�p�[�g���Ǘ����܂�													*
 *																					*
 *	�����FFREE�p�[�g��Control��Render������܂�										*
 *																					*
 *	�쐬���F2009�N 3��	9��															*
 *																					*
 *	�X�V���F    �N  ���@ ��															*
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
#include "Script.h"

/*================================
	
		Define����

=================================*/

enum FREE_STATE
{
	BASE,
	CLASS,
	MATERIAL,
	MPSET,
	STATE,
	SAVE,
};

enum TEXTURE_FREE						// �G���f�B���O��ʂ̃e�N�X�`���f�[�^
{
	T_FREE_BG,							// �w�i
	T_FREE_LOADING,						// LOADING

	T_FREE_MAX,
};

enum RECT_FREE							//��`�f�[�^
{
	R_FREE_BG,							// �w�i
	R_FREE_LOADING,						// LOADING

	R_FREE_MAX,
};

enum FREE_SOUND_DATA						// �^�C�g���̃T�E���h�f�[�^
{
	S_FREE_BGM,

	MAX_S_FREE,
};

class C_Free 
{
private:
	C_DGraphics			*graphics;				//DGraphics�N���X�̃C���X�^���X
	LPDIRECT3DTEXTURE9	*pTexture;				//�e�N�X�`���f�[�^	
	DFont				*pFont;					//Font�N���X�ւ̃|�C���^
	C_Script			*pScript;
//	F_RECT				rect_adventure[R_MAX_ADV];		//��`���

	int			cursor_locate;

	int 		use_texture;		//�g�p����摜�̖������i�[����B
	int 		*scene_check;		//�V�[�����̋�؂�𔻒f����


public:
	C_Free(C_DGraphics *graphic);
	void Init();
	void Control(int * key);
	void Draw();
	void Sound();				//�T�E���h�̊Ǘ�
	void Release();

	void FreeBase();	//��{
	void FreeClass();	//����
	void FreeMaterial();//�}�e���A��
	void FreeMpset();	//�l�o�Z�b�g
	void FreeState();	//�X�e�[�^�X�\��
	void FreeSave();	//�Z�[�u
public:
	C_Free(void);	
	~C_Free(void);
};
