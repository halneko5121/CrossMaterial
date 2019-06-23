#include "Adventure.h"

/************************************************************************************
 *																					*
 *	�����FADV�p�[�g���Ǘ�����														*
 *																					*
 *	�����F�X�N���v�g�̎��s�A�X�N���v�g.cpp�̏I�����ʂ̂���Ď��̃V�[���ɔ�΂��܂��@*
 *																					*
 *	�쐬���F2008�N 12�� 10��														*
 *																					*
 *	�X�V���F2008�N 2��	20��														*
 *													by	�O��@�j					*
 *																					*
 ************************************************************************************/

F_RECT rect_adv[] =				//ADV�p�[�g�̂Ȃ̂Ńv�����[�O�ł��L�����G�Ɋւ��Ă�
{
	{  0.0f, 30.0f,  0.0f,200.0f},	//LOADING
};

char* LoadADVFile[] = //�g���G��ǂݍ���ł���
{
	{"Graphic\\NowLoading.png"},
	{"\0"},
};

C_Adventure::C_Adventure(C_DGraphics* graphic)
{
	m_scene_flag = ADV_SCENE;							//SceneManage�N���X��ADV�t���O��Ԃ��B

	m_graphics = graphic;

	use_texture = 0;									//�g�p����e�N�X�`����

	for(int i = 0; LoadADVFile[i] != "\0"; i++)			//�g���G�̖�����m�点��
	{
		use_texture++;	
	}

	m_graphics->InitData(R_ADV_MAX);					 //��`�̐��������������m�ۂ���B

	m_pTexture = new LPDIRECT3DTEXTURE9[use_texture];	//�摜�f�[�^�̐��������������m�ۂ���B

	m_scene_number = new int;

	m_scene_number[0] = TEXT_PROLOGUE;

	alpha = 1;

	flag_end = FLAG_CONTINUE;

	pScript = new C_Script(m_graphics);	//Script�N���X�̃I�u�W�F�N�g�𐶐�����B

}

C_Adventure::~C_Adventure()
{
}

void C_Adventure::Init()
{
	m_alpha_load	  = m_count_fade = 0;
	m_flag_fade		  = false;

	for(int i = TEXT_PROLOGUE; i < MAX_TEXTNAME;i++){
		if(*m_scene_num[ADV_SCENE] == i){
			pScript->Init(i);
			break;
		}
	}
}

void C_Adventure::Control(int* key)
{
	pScript->Control(key);

	flag_end = pScript->GetFlagTalkEnd();

	switch(flag_end){
		case TEXT_PROLOGUE:
			SetInit();
			NowLoading(PROLOGUE,SCENE_WORLD1);
			m_graphics->SetColor(D3DCOLOR_ARGB(m_alpha_load,255,255,255),R_ADV_LOADING);
			break;
		case TEXT_STORY3_1:
		case TEXT_STORY3_2:
		case TEXT_STORY3_3:
			for(int i = TEXT_STORY3_1;i < TEXT_BATTLE_BEFORE;i++){
				if(flag_end == i){
					m_scene_number[0] = i + 1;
					SetSceneNum(ADV_SCENE,m_scene_number);		//ADV�p�[�g�́wSTORY3_1 �` �퓬�O�x��
					Init();
					break;
				}
			}
			break;
		case TEXT_BATTLE_BEFORE:
			SetInit();
			NowLoading(BATTLE_SCENE);
			m_graphics->SetColor(D3DCOLOR_ARGB(m_alpha_load,255,255,255),R_ADV_LOADING);
			break;
		case TEXT_EPILOGUE:
			m_scene_flag		= ENDING;
			break;
	}
}

void C_Adventure::Draw()
{
	if( (flag_end == TEXT_PROLOGUE)||(flag_end == TEXT_BATTLE_BEFORE) ){
		m_graphics->DrawCC(650,550,m_pTexture[T_ADV_LOADING],T_ADV_LOADING,R_ADV_LOADING);
	}
	else pScript->Draw();
	
}

void C_Adventure::Sound()						//�T�E���h�̊Ǘ�
{
}

void C_Adventure::Release()
{
	if(flag_end == TEXT_EPILOGUE){
		pScript->Release();
		delete pScript;
	}

}

void C_Adventure::SetInit()
{
	m_graphics->SetTextureNum(use_texture);		//�e�N�X�`���̖������Z�b�g����

	for(int i = 0; i < use_texture; i++)		//�e�N�X�`���̓ǂݍ��݂��s���B
	{
		m_graphics->LoadTexture(LoadADVFile[i],m_pTexture[i]); 
	}
	
	for(int i = 0; i < R_ADV_MAX; i++)
	{
		m_graphics->SetPostion(rect_adv[i],i);	//��`�����Z�b�g����
	}	

}