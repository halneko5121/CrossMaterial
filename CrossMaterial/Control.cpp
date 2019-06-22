/************************************************************************************
 *																					*
 *	役割：キー情報を受け取る。				　　　　　　　　						*
 *																					*
 *	説明：キー情報を受け取り渡す。　　　　　										*
 *																					*
 *	作成日：2008年 8月 9日															*
 *																					*
 *	更新日：2008年 8月 11日															*
 *													by		大川　泰弘				*
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
	
	if(CheckKeyBoard(KEY_UP,KEYBOARD,KEY_PUSH))    {	key[0]  = UP_PUSH;     }	//上キーが押されたときPUSH版

	if(CheckKeyBoard(KEY_DOWN,KEYBOARD,KEY_PUSH))  {	key[1]  = DOWN_PUSH;   }	//下キーが押されたときPUSH版	
	
	if(CheckKeyBoard(KEY_LEFT,KEYBOARD,KEY_PUSH))  {	key[2]  = LEFT_PUSH;   }	//左キーが押されたときPUSH版

	if(CheckKeyBoard(KEY_RIGHT,KEYBOARD,KEY_PUSH)) {	key[3]  = RIGHT_PUSH;  }	//右キーが押されたときPUSH版

	if(CheckKeyBoard(KEY_UP,KEYBOARD,KEY_PRESS))   {	key[4]  = UP_PRESS;    }	//上キーが押されたとき

	if(CheckKeyBoard(KEY_DOWN,KEYBOARD,KEY_PRESS)) {	key[5]  = DOWN_PRESS;  }	//下キーが押されたとき	

	if(CheckKeyBoard(KEY_LEFT,KEYBOARD,KEY_PRESS)) {	key[6]  = LEFT_PRESS;  }	//左キーが押されたとき

	if(CheckKeyBoard(KEY_RIGHT,KEYBOARD,KEY_PRESS)){	key[7]  = RIGHT_PRESS; }	//右キーが押されたとき
	 
	if(CheckKeyBoard(KEY_Z,KEYBOARD,KEY_PUSH))     {	key[8]  = Z_PUSH;	   }	//Zキーが押されたときPUSH版

	if(CheckKeyBoard(KEY_X,KEYBOARD,KEY_PUSH))     {	key[9]  = X_PUSH;	   }	//Xキーが押されたときPUSH版

	if(CheckKeyBoard(KEY_A,KEYBOARD,KEY_PUSH))		{	key[10] = A_PUSH;  }		//Aキー押されたときPUSH版

	if(CheckKeyBoard(KEY_C,KEYBOARD,KEY_PUSH))     {	key[11]  = C_PUSH;	   }	//Xキーが押されたときPUSH版

	if(CheckKeyBoard(KEY_S,KEYBOARD,KEY_PUSH))     {	key[12]  = S_PUSH;	   }	//Xキーが押されたときPUSH版
}
