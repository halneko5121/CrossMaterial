/************************************************************************************
 *																					*
 *	�����F�V�[���̊Ǘ����s���B											�@�@�@�@�@�@*
 *																					*
 *	�����F�Q�[���̏�Ԃɉ����āA�V�[���̐؂�ւ����s���B							*
 *																					*
 *	�쐬���F2008�N 8�� 15��															*
 *																					*
 *	�X�V���F2009�N 2��  5��															*
 *												by		�����@���F			�@�@	*
 *																					*
 ************************************************************************************/
#pragma once

/*================================
	
		INCLUDE����

=================================*/
#include "Logo.h"
#include "Title.h"
#include "Prologue.h"
#include "Adventure.h"
#include "Battle.h"
#include "Ending.h"

/*================================
	
		DEFINE����

=================================*/


/*================================
	
		MACRO����

=================================*/


//SceneManage�N���X
class C_SceneManage
{
	static const char *pSceneName[];

	private:
		int scene_no;			//���݂̃V�[���𔻒f����B

		int *scene_num;			

		C_Scene* pScene;
		
	public:
		C_SceneManage();	//�R���X�g���N�^
		~C_SceneManage();	//�f�X�g���N�^

		void InitScene(C_DGraphics *graphics);

		void ChangeScene();		//�V�[���̐؂�ւ����s���B

		void DrawScene();		//�V�[���̕`����s���B

		void Control(int *key);	//�R���g���[��

		void ReleaseScene();	//���

		int GetSceneNo()	{return scene_no;}

};



