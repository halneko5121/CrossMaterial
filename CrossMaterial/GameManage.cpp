/************************************************************************************
 *																					*
 *	�����F���C���ł��I																*
 *																					*
 *	�����F���C���ł��I�I															*
 *																					*
 *	�쐬���F2008�N 8��15��															*
 *																					*
 *	�X�V���F2008�N �� ��															*
 *													by ���� ���F					*
 *																					*
 ************************************************************************************/


/*================================
	
		INCLUDE����

=================================*/
#include "GameManage.h"


C_GameManage::C_GameManage(LPDIRECT3DDEVICE9 pD3Device)	//�R���X�g���N�^
{
	graphics = new C_DGraphics();	 //DirectGraphics�̃I�u�W�F�N�g�𐶐�����B
	
	graphics->SetDevice(pD3Device);	 //�`��p�̃f�o�C�X���Z�b�g����B

	control = new C_Control();		 //Control�̃I�u�W�F�N�g�𐶐�����B

	scene_manage = new C_SceneManage(); //SceneManage�̃I�u�W�F�N�g�𐶐�����B 
	scene_manage->InitScene(graphics);	//DirectGraphics�̃I�u�W�F�N�g��n��
}

void C_GameManage::Control()	//�R���g���[��
{
	static int now_scene = scene_manage->GetSceneNo();	//���݂̃V�[�����`�F�b�N

	control->KeyControl();							//�L�[�̓��͂��m�F����B
		
	scene_manage->Control(control->GetKey());		//�e�V�[���̃R���g���[��

	scene_manage->ChangeScene();					//�V�[���̐؂�ւ�

	if(now_scene != scene_manage->GetSceneNo())		//���݂̃V�[���ƑO�̃V�[���ԍ����Ⴆ��
	{	
		scene_manage->ReleaseScene();				//�O�̃V�[��������
		scene_manage->InitScene(graphics);			//���̃V�[����DirectGraphics�̃I�u�W�F�N�g��n��
		now_scene = scene_manage->GetSceneNo();		//���݂̃V�[���̍X�V
	}
}

void C_GameManage::Draw()		//�`��
{
	scene_manage->DrawScene();	//�V�[�����Ƃ̕`����s���B
}

C_GameManage::~C_GameManage()
{
	delete control;

	delete scene_manage; 		

	delete graphics;
}