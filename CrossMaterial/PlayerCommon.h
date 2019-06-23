#pragma once
/************************************************************************************
 *																					*
 *	�����F�����L�����ɋ��ʕ������Ǘ�����B											*
 *																					*
 *	�����F�����L�����̋��ʕ������Ǘ�����B											*
 *																					*
 *	�쐬���F2008�N11�� 8��															*
 *																					*
 *	�X�V���F2009�N 2�� 5��															*
 *													by �O��@�j						*
 *												�X�V�� ����	 �F�T					*
 ************************************************************************************/

/*================================
	
		INCLUDE����

=================================*/
#include "CharaCommon.h"

/*================================
	
		Define����

=================================*/

enum FILE_DATA
{
	F_SAVE1,				//SAVE1
	F_SAVE2,				//SAVE2
	F_SAVE3,				//SAVE3
	F_PRESENT,				//���݂̃f�[�^
	F_INITIAL,				//�����f�[�^
};
/*/*================================
	
		struct����

=================================*/

struct CharaData_player							//�����L�������L�̃X�e�[�^�X
{
	//�e�����L�����Œ�̂���
	int			m_kind_matrix;					//�}�g���N�X��ޔ��ʗp
	//�}�e���A���ɂ���ĕω�
	int  		m_material_id;					//�}�e���A�����Z�b�g���邽�߂̎󂯎M
												//�ǂ̃}�e���A�����̔���@1 �� 2�� 3�y 4�� �Ȃ� 
	int			m_skill1,m_skill2;				//�Z�̎��	(�������Ă���}�e���A���ŕω�)
	int			m_ap_use1,m_ap_use2;			//����AP
};

class C_PlayerCommon :	public C_CharaCommon
{
private:
	CharaData_player player;
public:
	void LoadPlayerData(int read_no);
	void SavePlayerData(int record_no);
	C_PlayerCommon(void);
	~C_PlayerCommon(void);
	void Init();
	void Draw();
};
