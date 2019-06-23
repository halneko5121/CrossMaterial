#pragma once

/************************************************************************************
 *																					*
 *	�����F�L�[���͂��Ǘ�����B														*
 *																					*
 *	�����F���͑��u�̏�Ԃ𔻒f���A�K�؂ȃL�[������U��B							*
 *																					*
 *	�쐬���F2008�N 8�� 8��															*
 *																					*
 *	�X�V���F2008�N 8�� 9��															*
 *													by	���@�׍O					*
 *																					*
 ************************************************************************************/


/*================================
	
		INCLUDE����

=================================*/
#include "DirectInput.h"
#include "Define.h"

/*================================
	
		DEFINE����

=================================*/
#define HEIGHT_MAX	(20)
#define WIDTH_MAX	(15)
#define BLANK_KEY	(0)


/*================================
	
		MACRO����

=================================*/


//Control�N���X
class C_Control
{
	private:
		int key[KEY_MAX];

	public:
		C_Control();

		void KeyControl();

		int *GetKey()	{return &key[0];}

		void CursorControl(int *height_piece,int *width_piece,int field[20][20],int *flag_key_z);	//�J�[�\������(���݂̏c�C���݂̉��C�t�B�[���h���)
};