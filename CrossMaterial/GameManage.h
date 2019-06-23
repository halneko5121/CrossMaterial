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
#include "Control.h"
#include "SceneManage.h"
#include "DirectGraphics.h"

/*================================
	
		DEFINE����

=================================*/


/*================================
	
		MACRO����

=================================*/

class C_GameManage
{
	private:	
		C_DGraphics *graphics;		  //DirectGraphics�̃I�u�W�F�N�g�����w��

		C_Control *control;			  //Control�̃I�u�W�F�N�g�����w��
			
		C_SceneManage *scene_manage;  //SceneManage�̃I�u�W�F�N�g�����w��

	public:
		C_GameManage(LPDIRECT3DDEVICE9 pD3Device);	//�R���X�g���N�^
		
		~C_GameManage();	//�f�X�g���N�^

		void Draw();		//�`��	
		
		void Control();		//�R���g���[��

};
		