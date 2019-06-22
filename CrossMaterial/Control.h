#pragma once

/************************************************************************************
 *																					*
 *	役割：キー入力を管理する。														*
 *																					*
 *	説明：入力装置の状態を判断し、適切なキーを割り振る。							*
 *																					*
 *	作成日：2008年 8月 8日															*
 *																					*
 *	更新日：2008年 8月 9日															*
 *													by	大川　泰弘					*
 *																					*
 ************************************************************************************/


/*================================
	
		INCLUDEたち

=================================*/
#include "DirectInput.h"
#include "Define.h"

/*================================
	
		DEFINEたち

=================================*/
#define HEIGHT_MAX	(20)
#define WIDTH_MAX	(15)
#define BLANK_KEY	(0)


/*================================
	
		MACROたち

=================================*/


//Controlクラス
class C_Control
{
	private:
		int key[KEY_MAX];

	public:
		C_Control();

		void KeyControl();

		int *GetKey()	{return &key[0];}

		void CursorControl(int *height_piece,int *width_piece,int field[20][20],int *flag_key_z);	//カーソル操作(現在の縦，現在の横，フィールド情報)
};