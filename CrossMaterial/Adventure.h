#pragma once

/************************************************************************************
 *																					*
 *	�����FADV�p�[�g���Ǘ�����														*
 *																					*
 *	�����F�X�N���v�g�̎��s�A�X�N���v�g.cpp�̏I�����ʂ̂���Ď��̃V�[���ɔ�΂��܂��@*
 *																					*
 *	�쐬���F2008�N 12�� 10��														*
 *																					*
 *	�X�V���F2008�N 2��	20��														*
 *													by	�O��@�j					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include "Scene.h"
#include "Script.h"
#include "Define.h"

/*================================
	
		Define����

=================================*/
#define MAX_TEXTURE_ADV			(4)			//���S��ʂŎg���e�N�X�`���̐�

//�`��ʒu

//���̓t�F�[�h�n
#define MAX_ALPHA			(255)		//�A���t�@�l�ő�
#define ALPHA_CHANGE		(10)		//�A���t�@�l�ω���(����1)
#define ALPHA_CHANGE2		(5)			//�A���t�@�l�ω���(���炷��)

enum TEXTURE_DATA_ADV					//ADV��ʂ̃e�N�X�`���f�[�^
{
	T_ADV_LOADING,

	T_ADV_MAX,
};

enum RECT_DATA_ADV						//ADV�̋�`�f�[�^
{
	R_ADV_LOADING,						
	
	R_ADV_MAX,
};

class C_Adventure : public C_Scene
{
	private:
		C_Script	*pScript;
		int use_texture;				//�g�p����摜�̖������i�[����B
		int alpha;						//�A���t�@�l��ύX����B
		int flag_end;
	public:
		C_Adventure(C_DGraphics *graphic);
		void Control(int * key);
		void Draw();
		void Sound();				
		void Release();
		void Init();
		void SetInit();

		~C_Adventure();
};
