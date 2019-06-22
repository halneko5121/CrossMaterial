/************************************************************************************
 *																					*
 *	役割：シーンの管理を行う。														*
 *																					*
 *	説明：ゲームの状態に応じて、シーンの切り替えを行う。							*
 *																					*
 *	作成日：2008年 8月 15日															*
 *																					*
 *	更新日：2008年 月 日															*
 *													by		早瀬　公彦				*
 *																					*
 ************************************************************************************/


/*================================
	
		INCLUDEたち

=================================*/
#include "SceneManage.h"

const char *C_SceneManage::pSceneName[] = 
{
	{"LOGO"},
	{"TITLE"},
	{"PROLOGUE"},
	{"ADV_SCENE"},
	{"BATTLE_SCENE"},
	{"GAMEOVER"},
	{"ENDING"},
};

C_SceneManage::C_SceneManage()			//コンストラクタ
{
	scene_no	= LOGO;					//ゲーム起動時のシーンを指定する。
	scene_num	= new int[MAX_SCENE];
}
C_SceneManage::~C_SceneManage()			//デストラクタ
{

}

void C_SceneManage::InitScene(C_DGraphics *graphics)	//フラグの状態に応じて、各シーンにゲームの状態を飛ばす。
{
	switch(scene_no)
	{
	case LOGO:
		pScene = new C_Logo(graphics);
		pScene->SetName((char*)pSceneName[scene_no]);
		pScene->Init();	
		break;

	case TITLE:
		pScene = new C_Title(graphics);
		pScene->SetName((char*)pSceneName[scene_no]);
		pScene->Init();	
		break;

	case PROLOGUE:
		pScene = new C_Prologue(graphics);
		pScene->SetName((char*)pSceneName[scene_no]);
		pScene->SetSceneNum(scene_no,scene_num);
		pScene->Init();	
		break;

	case ADV_SCENE:
		pScene = new C_Adventure(graphics);
		pScene->SetName((char*)pSceneName[scene_no]);
		pScene->SetSceneNum(scene_no,scene_num);
		pScene->Init();	
		break;

	case BATTLE_SCENE:
		pScene = new C_Battle(graphics);
		pScene->SetName((char*)pSceneName[scene_no]);
		pScene->Init();	
		break;

	case ENDING:
		pScene = new C_Ending(graphics);
		pScene->SetName((char*)pSceneName[scene_no]);
		pScene->Init();	
		break;

	}
}

void C_SceneManage::ChangeScene()
{
	scene_no = pScene->GetSceneFlag();	//ここで次のシーンのフラグを渡す
	scene_num= pScene->GetSceneNum(scene_no);
}

void C_SceneManage::DrawScene()
{
	pScene->Draw();										//各シーンのDraw
}

void C_SceneManage::Control(int *key)
{
	pScene->Sound();
	pScene->Control(key);								//各シーンのControl
}

void C_SceneManage::ReleaseScene()
{
	pScene->Release();
	delete pScene;						//前のシーンを消す
}