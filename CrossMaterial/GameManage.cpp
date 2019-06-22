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
#include "GameManage.h"


C_GameManage::C_GameManage(LPDIRECT3DDEVICE9 pD3Device)	//コンストラクタ
{
	graphics = new C_DGraphics();	 //DirectGraphicsのオブジェクトを生成する。
	
	graphics->SetDevice(pD3Device);	 //描画用のデバイスをセットする。

	control = new C_Control();		 //Controlのオブジェクトを生成する。

	scene_manage = new C_SceneManage(); //SceneManageのオブジェクトを生成する。 
	scene_manage->InitScene(graphics);	//DirectGraphicsのオブジェクトを渡す
}

void C_GameManage::Control()	//コントロール
{
	static int now_scene = scene_manage->GetSceneNo();	//現在のシーンをチェック

	control->KeyControl();							//キーの入力を確認する。
		
	scene_manage->Control(control->GetKey());		//各シーンのコントロール

	scene_manage->ChangeScene();					//シーンの切り替え

	if(now_scene != scene_manage->GetSceneNo())		//現在のシーンと前のシーン番号が違えば
	{	
		scene_manage->ReleaseScene();				//前のシーンを消す
		scene_manage->InitScene(graphics);			//今のシーンにDirectGraphicsのオブジェクトを渡す
		now_scene = scene_manage->GetSceneNo();		//現在のシーンの更新
	}
}

void C_GameManage::Draw()		//描画
{
	scene_manage->DrawScene();	//シーンごとの描画を行う。
}

C_GameManage::~C_GameManage()
{
	delete control;

	delete scene_manage; 		

	delete graphics;
}