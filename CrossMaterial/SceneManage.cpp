/************************************************************************************
 *																					*
 *	�����F�V�[���̊Ǘ����s���B														*
 *																					*
 *	�����F�Q�[���̏�Ԃɉ����āA�V�[���̐؂�ւ����s���B							*
 *																					*
 *	�쐬���F2008�N 8�� 15��															*
 *																					*
 *	�X�V���F2008�N �� ��															*
 *													by		�����@���F				*
 *																					*
 ************************************************************************************/


/*================================
	
		INCLUDE����

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

C_SceneManage::C_SceneManage()			//�R���X�g���N�^
{
	scene_no	= LOGO;					//�Q�[���N�����̃V�[�����w�肷��B
	scene_num	= new int[MAX_SCENE];
}
C_SceneManage::~C_SceneManage()			//�f�X�g���N�^
{

}

void C_SceneManage::InitScene(C_DGraphics *graphics)	//�t���O�̏�Ԃɉ����āA�e�V�[���ɃQ�[���̏�Ԃ��΂��B
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
	scene_no = pScene->GetSceneFlag();	//�����Ŏ��̃V�[���̃t���O��n��
	scene_num= pScene->GetSceneNum(scene_no);
}

void C_SceneManage::DrawScene()
{
	pScene->Draw();										//�e�V�[����Draw
}

void C_SceneManage::Control(int *key)
{
	pScene->Sound();
	pScene->Control(key);								//�e�V�[����Control
}

void C_SceneManage::ReleaseScene()
{
	pScene->Release();
	delete pScene;						//�O�̃V�[��������
}