/*================================

	INCLUDE����

=================================*/
#include "Logo.h"
#include <Time.h>
#include <stdlib.h>


F_RECT rect_logo[] =
{
	{0.0f,600.0f,0.0f,800.0f}	//���S
};

char* LoadLogoFile[] = //�g���G��ǂݍ���ł���
{
	{"Graphic\\BG\\T_Team_logo.PNG"},
	
	{"\0"},
};

char* LoadSoundLogo[] = //�g������ǂݍ���ł���
{
	{"Sound\\Logo\\9pb_girl01.wav"},
	{"Sound\\Logo\\9pb_girl02.wav"},
	{"Sound\\Logo\\9pb_girl03.wav"},
	{"Sound\\Logo\\9pb_man01.wav"},
	{"Sound\\Logo\\9pb_man02.wav"},
};

C_Logo::C_Logo(C_DGraphics* graphic)	//�R���X�g���N�^
{
	m_scene_flag = LOGO;	//SceneManage�N���X��LOGO�t���O��Ԃ��B

	m_graphics = graphic;

	use_texture = 0;		//�g�p����e�N�X�`����

	alpha = 0;				//�摜�̃A���t�@�l

	time_count = 0;			//���S�J�n����I���܂ł��J�E���g

	for(int i = 0; LoadLogoFile[i] != "\0"; i++)	//�g���G�̖�����m�点��
	{
		use_texture++;	
	}

	m_graphics->SetTextureNum(use_texture);  //�e�N�X�`���̖������Z�b�g����

	m_graphics->InitData(MAX_LOGO_TEXTURE);  //��`�̐��������������m�ۂ���B

	m_pTexture = new LPDIRECT3DTEXTURE9[use_texture];		//�摜�f�[�^�̐��������������m�ۂ���B

	for(int i = 0; i < use_texture; i++)  //�e�N�X�`���̓ǂݍ��݂��s���B
	{
		m_graphics->LoadTexture(LoadLogoFile[i],m_pTexture[i]); 
	}

	m_graphics->SetPostion(rect_logo[T_TEAM_LOGO],D_TEAM_LOGO);      //��`�����Z�b�g����

	m_graphics->SetColor(D3DCOLOR_RGBA(alpha,alpha,alpha,255),T_TEAM_LOGO);

	for(int i = 0;i < MAX_S_LOGO;i++){
		LoadSound(LoadSoundLogo[i],i);	//�^�C�g����ʂ�BGM
	}
}

C_Logo::~C_Logo()			//�f�X�g���N�^
{
}

void C_Logo::Init()
{
	m_alpha_load = 0;

	m_count_fade = 0;

	m_flag_fade  = false;

	//�ǉ��@2/28�O��
	flag_soundstop = true;
	srand((unsigned int)time(NULL));
	randum_voice = rand() % 5;
}

void C_Logo::Control(int* key)
{
	FadeControl();	//�t�F�[�h����
}

void C_Logo::Draw()
{
	m_graphics->DrawCC(400.0f, 300.0f, m_pTexture[T_TEAM_LOGO], T_TEAM_LOGO, D_TEAM_LOGO);  
}

void C_Logo::FadeControl()	//�t�F�[�h����
{	

	time_count++;
	
	if(time_count > 0 && time_count < 5)	
	{
		alpha += 10;
	}

	else if(time_count >= 5 && time_count < 48)
	{
		alpha += 5;
	}

	else if(time_count>= 48 && time_count < 200){
		alpha=255;

		if(flag_soundstop){
			SoundPlay(false,randum_voice);
			flag_soundstop = false;
		}
	}

	else if(time_count >= 200 && time_count < 185)
	{
		alpha -= 10;
	}

	else if(time_count >= 185)
	{
		alpha -= 5;

		if(alpha <= 0){
			alpha = 0;
			m_scene_flag = TITLE;
		}
	}

	m_graphics->SetColor(D3DCOLOR_RGBA(alpha,alpha,alpha,255),T_TEAM_LOGO);
}

void C_Logo::Sound()
{
}

void C_Logo::Release()	//���
{
	for(int i = 0;i < MAX_LOGO_TEXTURE;i++)
	{
		m_pTexture[i]->Release();
	}
}
