/************************************************************************************
 *																					*
 *	�����F�L�[�����󂯎��B				�@�@�@�@�@�@�@�@						*
 *																					*
 *	�����F�L�[�����󂯎��n���B�@�@�@�@�@										*
 *																					*
 *	�쐬���F2008�N 8�� 9��															*
 *																					*
 *	�X�V���F2008�N 8�� 11��															*
 *													by		���@�׍O				*
 *																					*
 ************************************************************************************/

#include"Control.h"

C_Control::C_Control()
{
	for(int i = 0; i < KEY_MAX; i++)
	{
		key[i] = NO_PUSH;
	}
}

void  C_Control::KeyControl()
{
	for(int i = 0; i < KEY_MAX; i++)
	{
		key[i] = NO_PUSH;
	}

	RefreshInput();
	
	if(CheckKeyBoard(KEY_UP,KEYBOARD,KEY_PUSH))    {	key[0]  = UP_PUSH;     }	//��L�[�������ꂽ�Ƃ�PUSH��

	if(CheckKeyBoard(KEY_DOWN,KEYBOARD,KEY_PUSH))  {	key[1]  = DOWN_PUSH;   }	//���L�[�������ꂽ�Ƃ�PUSH��	
	
	if(CheckKeyBoard(KEY_LEFT,KEYBOARD,KEY_PUSH))  {	key[2]  = LEFT_PUSH;   }	//���L�[�������ꂽ�Ƃ�PUSH��

	if(CheckKeyBoard(KEY_RIGHT,KEYBOARD,KEY_PUSH)) {	key[3]  = RIGHT_PUSH;  }	//�E�L�[�������ꂽ�Ƃ�PUSH��

	if(CheckKeyBoard(KEY_UP,KEYBOARD,KEY_PRESS))   {	key[4]  = UP_PRESS;    }	//��L�[�������ꂽ�Ƃ�

	if(CheckKeyBoard(KEY_DOWN,KEYBOARD,KEY_PRESS)) {	key[5]  = DOWN_PRESS;  }	//���L�[�������ꂽ�Ƃ�	

	if(CheckKeyBoard(KEY_LEFT,KEYBOARD,KEY_PRESS)) {	key[6]  = LEFT_PRESS;  }	//���L�[�������ꂽ�Ƃ�

	if(CheckKeyBoard(KEY_RIGHT,KEYBOARD,KEY_PRESS)){	key[7]  = RIGHT_PRESS; }	//�E�L�[�������ꂽ�Ƃ�
	 
	if(CheckKeyBoard(KEY_Z,KEYBOARD,KEY_PUSH))     {	key[8]  = Z_PUSH;	   }	//Z�L�[�������ꂽ�Ƃ�PUSH��

	if(CheckKeyBoard(KEY_X,KEYBOARD,KEY_PUSH))     {	key[9]  = X_PUSH;	   }	//X�L�[�������ꂽ�Ƃ�PUSH��

	if(CheckKeyBoard(KEY_A,KEYBOARD,KEY_PUSH))		{	key[10] = A_PUSH;  }		//A�L�[�����ꂽ�Ƃ�PUSH��

	if(CheckKeyBoard(KEY_C,KEYBOARD,KEY_PUSH))     {	key[11]  = C_PUSH;	   }	//X�L�[�������ꂽ�Ƃ�PUSH��

	if(CheckKeyBoard(KEY_S,KEYBOARD,KEY_PUSH))     {	key[12]  = S_PUSH;	   }	//X�L�[�������ꂽ�Ƃ�PUSH��
}
