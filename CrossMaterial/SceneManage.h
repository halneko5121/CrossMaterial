/************************************************************************************
 *																					*
 *	役割：シーンの管理を行う。											　　　　　　*
 *																					*
 *	説明：ゲームの状態に応じて、シーンの切り替えを行う。							*
 *																					*
 *	作成日：2008年 8月 15日															*
 *																					*
 *	更新日：2009年 2月  5日															*
 *												by		早瀬　公彦			　　	*
 *																					*
 ************************************************************************************/
#pragma once

/*================================
	
		INCLUDEたち

=================================*/
#include "Logo.h"
#include "Title.h"
#include "Prologue.h"
#include "Adventure.h"
#include "Battle.h"
#include "Ending.h"

/*================================
	
		DEFINEたち

=================================*/


/*================================
	
		MACROたち

=================================*/


//SceneManageクラス
class C_SceneManage
{
	static const char *pSceneName[];

	private:
		int scene_no;			//現在のシーンを判断する。

		int *scene_num;			

		C_Scene* pScene;
		
	public:
		C_SceneManage();	//コンストラクタ
		~C_SceneManage();	//デストラクタ

		void InitScene(C_DGraphics *graphics);

		void ChangeScene();		//シーンの切り替えを行う。

		void DrawScene();		//シーンの描画を行う。

		void Control(int *key);	//コントロール

		void ReleaseScene();	//解放

		int GetSceneNo()	{return scene_no;}

};



