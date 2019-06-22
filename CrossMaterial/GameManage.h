/************************************************************************************
 *																					*
 *	役割：メインです！																*
 *																					*
 *	説明：メインです！！															*
 *																					*
 *	作成日：2008年 8月15日															*
 *																					*
 *	更新日：2008年 月 日															*
 *													by 早瀬 公彦					*
 *																					*
 ************************************************************************************/


/*================================
	
		INCLUDEたち

=================================*/
#include "Control.h"
#include "SceneManage.h"
#include "DirectGraphics.h"

/*================================
	
		DEFINEたち

=================================*/


/*================================
	
		MACROたち

=================================*/

class C_GameManage
{
	private:	
		C_DGraphics *graphics;		  //DirectGraphicsのオブジェクト名を指定

		C_Control *control;			  //Controlのオブジェクト名を指定
			
		C_SceneManage *scene_manage;  //SceneManageのオブジェクト名を指定

	public:
		C_GameManage(LPDIRECT3DDEVICE9 pD3Device);	//コンストラクタ
		
		~C_GameManage();	//デストラクタ

		void Draw();		//描画	
		
		void Control();		//コントロール

};
		