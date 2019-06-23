#include "Title.h"

//�^�C�g���̋�`���{top,bottom,left,right}
F_RECT rect_title[]={
	{  0.0f,600.0f,  0.0f,800.0f},	//�^�C�g���̔w�i
	{  0.0f, 39.0f,  0.0f,179.0f},	//START�̃t�H���g
	{ 81.0f,120.0f,  0.0f,121.0f},	//END�̃t�H���g
	{240.0f,279.0f,  0.0f,270.0f},	//�A�C�R��
	{  0.0f, 30.0f,  0.0f,200.0f},	//LOADING
};

char* LoadTitleFile[] = //�g���G��ǂݍ���ł���
{
	{"Graphic\\BG\\T_Title.png"},			
	{"Graphic\\Font�EConsor\\T_TitleFont.png"},
	{"Graphic\\Font�EConsor\\T_status.png"},
	{"Graphic\\NowLoading.png"},
	{"\0"},
};

char* LoadSoundTitle[] = //�g������ǂݍ���ł���
{
	{"Sound\\Title\\title.wav"}, 
	{"Sound\\Title\\se-select.wav"},
	{"Sound\\Title\\se-enter.wav"},
	{"Sound\\Title\\se-cancel.wav"},
};

C_Title::C_Title(C_DGraphics *graphic)
{
	m_scene_flag = TITLE;						//SceneManage�N���X��TITLE�t���O��Ԃ��B

	m_graphics = graphic;

	use_texture = 0;							//�g�p����e�N�X�`����

	title_draw_flag=0;

	alpha = 0;		//�摜�̃A���t�@�l
	
	alpha_count= 0; //�A���t�@�J�E���g
	
	menu_flag=0;	//���j���[�̈ʒu

	fade_flag=0;	//�t�F�[�h�t���O

	for(int i = 0; LoadTitleFile[i] != "\0"; i++)	//�g���G�̖�����m�点��
	{
		use_texture++;	
	}

	m_graphics->SetTextureNum(use_texture);			//�e�N�X�`���̖������Z�b�g����

	m_graphics->InitData(R_TITLE_MAX);				//��`�̐��������������m�ۂ���B

	m_pTexture = new LPDIRECT3DTEXTURE9[use_texture];		//�摜�f�[�^�̐��������������m�ۂ���B

	for(int i = 0; i < use_texture; i++)			//�e�N�X�`���̓ǂݍ��݂��s���B
	{
		m_graphics->LoadTexture(LoadTitleFile[i],m_pTexture[i]); 
	}
	
	for(int i = R_TITLE_BG; i < R_TITLE_MAX; i++)
	{
		m_graphics->SetPostion(rect_title[i],i);      //��`�����Z�b�g����
	}

	m_graphics->SetColor(D3DCOLOR_RGBA(alpha,alpha,alpha,255),T_TITLE_BG);

	for(int i = 0;i < MAX_S_TITLE;i++){
		LoadSound(LoadSoundTitle[i],i);	//�^�C�g����ʂ�BGM
	}

	//3/10�ǉ��@�O��
	m_scene_number = new int;
	m_scene_number[0] = 0;
	cursor_draw_x = 1.f;
	cursor_draw_y = 1.f;
	keep_pos_y	  = 0.f;
}

C_Title::~C_Title()
{
}

void C_Title::Init()
{
	m_alpha_load = m_count_fade = 0;
	m_flag_fade  = false;
}

void C_Title::Control(int* key)
{
#ifdef _DEBUG
	if(key[12] == S_PUSH) fade_flag = 2;
#endif

	if(fade_flag==1)
	{
		if(key[0]  == UP_PUSH)
		{
			menu_flag--;
			if(SoundCheck(S_TITLE_SELECT)!=true)
			{
				SoundStop(false,S_TITLE_SELECT);
				SoundPlay(false,S_TITLE_SELECT);
			}
			if(menu_flag<0)	menu_flag=0;
		}

		if(key[1]  == DOWN_PUSH)
		{
			menu_flag++;
			if(SoundCheck(S_TITLE_SELECT)!=true)
			{
				SoundStop(false,S_TITLE_SELECT);
				SoundPlay(false,S_TITLE_SELECT);
			}
			if(menu_flag>1) menu_flag=1;
		}

		if(key[8] == Z_PUSH)
		{
			if(SoundCheck(S_TITLE_ENTER)!=true) SoundPlay(false,S_TITLE_ENTER);

			switch(menu_flag)
			{
				case M_START:
					fade_flag=2;
					break;
				case M_END:
					fade_flag=3;
					break;
			}
		}

		if(title_draw_flag==1)
		{
			if(key[9] == X_PUSH)
			{
				if(SoundCheck(S_TITLE_CANCEL)!=true)
					SoundPlay(false,S_TITLE_CANCEL);
				title_draw_flag=0;
				menu_flag=0;
			}
		}
	}
	FadeControl();
}

void C_Title::Draw()
{
	m_graphics->DrawCC(400.f,300.f,m_pTexture[T_TITLE_BG],T_TITLE_BG,R_TITLE_BG);

	if(fade_flag == 1)
	{
		switch(title_draw_flag)
		{
			case 0:
				MenuDraw();
				DrawCursor();
				break;
		}
	}
	if(fade_flag == 2)
	{
		DrawCursor();
		if(alpha==0){
			m_graphics->DrawCC(650,550,m_pTexture[T_TITLE_LOADING],T_TITLE_LOADING,R_TITLE_LOADING);
		}
	}
	if(fade_flag == 3) DrawCursor();
}


void C_Title::MenuDraw()
{
	for(int i= R_TITLE_START; i<=R_TITLE_END; i++)
	{
		m_graphics->DrawCC(400.f,420.f+70.f*(i-1),m_pTexture[T_TITLE_FC],T_TITLE_FC,i);
	}
}

void C_Title::FadeControl()
{
	switch(fade_flag)
	{
		case 0:	//�t�F�[�h�C��
			FadeIn();
			if(alpha==255) fade_flag=1;
			SoundPlay(true,S_TITLE_BGM);
			break;
		case 1:
			alpha=TITLE_MAX_ALPHA;
			alpha_count=0;
			break;
		case 2:	//START��I��������A�t�F�[�h�A�E�g�AADV(�v�����[�O)�ֈڍs����
			FadeOut();
			//3/10 �O�� �ǉ���
			if(alpha == 0){
				SoundStop(true,S_TITLE_BGM);
				NowLoading(ADV_SCENE,TEXT_PROLOGUE);
				m_graphics->SetColor(D3DCOLOR_ARGB(m_alpha_load,255,255,255),R_TITLE_LOADING);
			}
			break;
			//3/10 �O�� �ǉ���
		case 3:	//END��I��������t�F�[�h�A�E�g���ďI��������
			FadeOut();
			if(alpha==0)	PostQuitMessage(0);
			break;
	}
	m_graphics->SetColor(D3DCOLOR_RGBA(alpha,alpha,alpha,255),T_TITLE_BG);
}

void C_Title::FadeIn()
{
	if(alpha_count++>1)
	{
		alpha+=TITLE_ALPHA_INCREASE;
		alpha_count=0;
	}
	if(alpha>TITLE_MAX_ALPHA)
	{
		alpha=TITLE_MAX_ALPHA;
		alpha_count=0;
	}
}

void C_Title::FadeOut()
{
	if(alpha_count++>1)
	{
		alpha-=TITLE_ALPHA_INCREASE;
		alpha_count=0;
	}
	if(alpha<0)
	{
		alpha=0;
		alpha_count=0;
	}
}

void C_Title::Sound()						//�T�E���h�̊Ǘ�
{

}
void C_Title::Release()
{
	for(int i = T_TITLE_BG; i < T_TITLE_MAX; i++)
	{
		m_pTexture[i]->Release();
	}

}

void C_Title::DrawCursor()
{
	if(fade_flag == 1){
		m_graphics->SetColor(D3DCOLOR_ARGB(175,255,255,255),R_TITLE_ICON);
		m_graphics->DrawCC(DRAW_BG_POS_X,(410.f + (70.f * menu_flag) ),m_pTexture[T_TITLE_FC],T_TITLE_FC,R_TITLE_ICON);
	}
	else{
		cursor_draw_x += DRAW_CURSOR_X;
		if(cursor_draw_y > 0) cursor_draw_y -= DRAW_CURSOR_Y;
		keep_pos_y += (DRAW_CURSOR_Y * 10);

		m_graphics->SetSize(cursor_draw_x,cursor_draw_y,R_TITLE_ICON);
		m_graphics->DrawCC(DRAW_BG_POS_X,( (410.f + keep_pos_y) + (70.f * menu_flag) ),m_pTexture[T_TITLE_FC],T_TITLE_FC,R_TITLE_ICON);
	}
}
