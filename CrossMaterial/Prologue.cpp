#include "Prologue.h"

/************************************************************************************
 *																					*
 *	�����F�v�����[�O���Ǘ����܂�													*
 *																					*
 *	�����F���E�ϐ������ڍׁ����炷��(�{�҂ɑ���)���{��								*
 *																					*
 *	�쐬���F2008�N 12�� 5��															*
 *																					*
 *	�X�V���F2008�N 2�� 20��															*
 *													by	�O��@�j					*
 *																					*
 ************************************************************************************/

F_RECT rect_prologue[] =
{
	{   0.0f, 600.0f,  0.0f, 800.0f},				//�w�i

	{   1.0f,  30.0f,   1.0f, 650.0f},				//���E�ϏЉ�(1�s��)
	{  31.0f,  60.0f,   1.0f, 650.0f},				//���E�ϏЉ�(2�s��)
	{  61.0f,  90.0f,   1.0f, 650.0f},				//���E�ϏЉ�(3�s��)
	{   1.0f, 150.0f, 651.0f,1350.0f},				//���E�ϏЉ�(�ڍ�)
	{	1.0f,1320.0f,1351.0f,2000.0f},				//���炷��
	{	0.0f,  30.0f,	0.0f, 200.0f},				//LOADING


};

char* LoadPrologueFile[] =	{					//�g���G��ǂݍ���ł���
	{"Graphic\\BG\\T_Intro.png"},				//�w�i
	{"Graphic\\T_Sentence.png"},				//���͉摜�f�[�^
	{"Graphic\\NowLoading.png"},
	{"\0"},
};

char* LoadSoundPrologue[] ={
	{"Sound\\World.wav"},
	{"Sound\\Plot.wav"},
	{"\0"},
};

C_Prologue::C_Prologue(C_DGraphics* graphic)
{
	m_graphics = graphic;

	m_scene_flag = PROLOGUE;								//SceneManage�N���X��PROLOGUE�t���O��Ԃ��B

	m_scene_number = new int;

	use_texture = 0;										//�g�p����e�N�X�`����

	use_sound = 0;

	for(int i = 0; LoadSoundPrologue[i] != "\0"; i++){		//�g�����̐���m�点��
		use_sound++;	
	}

	for(int i = 0;i < use_sound;i++){
		LoadSound(LoadSoundPrologue[i],i);
	}

	for(int i = 0; LoadPrologueFile[i] != "\0"; i++){		//�g���G�̖�����m�点��
		use_texture++;	
	}

	m_graphics->SetTextureNum(use_texture);					//�e�N�X�`���̖������Z�b�g����

	m_graphics->InitData(R_MAX_PROLOGUE);					//��`�̐��������������m�ۂ���B

	m_pTexture = new LPDIRECT3DTEXTURE9[use_texture];		//�摜�f�[�^�̐��������������m�ۂ���B

	for(int i = 0; i < use_texture; i++){					//�e�N�X�`���̓ǂݍ��݂��s���B
		m_graphics->LoadTexture(LoadPrologueFile[i],m_pTexture[i]); 
	}

	for(int i = 0; i < R_MAX_PROLOGUE; i++){				//��`�̃Z�b�g���s���B
		m_graphics->SetPostion(rect_prologue[i],i);			//��`�����Z�b�g����
	}
}

C_Prologue::~C_Prologue()
{

}

void C_Prologue::Init()
{
	m_alpha_load	  = m_count_fade = 0;
	m_flag_fade		  = false;
	m_scene_number[0] = 0;

	//�ϐ�������
	rect_slide = count_fade_pro = count_wait = 0;
	alpha			= 1;
	alpha2			= 255;
	pos_slide		= POS_WORLD2_Y;
}

void C_Prologue::Control(int* key)
{
#ifdef _DEBUG
	DebugKey(key);
#endif
	ShortCutKey(key);

	switch(*m_scene_num[PROLOGUE]){
		case SCENE_WORLD1:
			SoundPlay(true,S_WORLD1_2);
			FadeIn();
			FadeOut();
			m_graphics->SetColor(D3DCOLOR_ARGB(alpha,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_WORLD1_1LINE);
			m_graphics->SetColor(D3DCOLOR_ARGB(alpha,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_WORLD1_2LINE);
			m_graphics->SetColor(D3DCOLOR_ARGB(alpha,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_WORLD1_3LINE);

			SlideRect();
			break;
		case SCENE_WORLD2:
			SoundStop(true,S_WORLD1_2);
			SoundPlay(true,S_PLOT);
			Slide();
			SlideRect();
			break;
		case SCENE_PLOT:
			SoundPlay(true,S_PLOT);
			Slide();
			break;
	}
}

void C_Prologue::Draw()
{
	switch(*m_scene_num[PROLOGUE]){
		case SCENE_WORLD1:
			m_graphics->Draw(POS_WORLD1_LINE1_X,POS_WORLD1_LINE1_Y,m_pTexture[T_WRITING],T_WRITING,R_WORLD1_1LINE);//1�s��
			m_graphics->Draw(POS_WORLD1_LINE2_X,POS_WORLD1_LINE2_Y,m_pTexture[T_WRITING],T_WRITING,R_WORLD1_2LINE);//2�s��
			m_graphics->Draw(POS_WORLD1_LINE3_X,POS_WORLD1_LINE3_Y,m_pTexture[T_WRITING],T_WRITING,R_WORLD1_3LINE);//3�s��
			break;
		case SCENE_WORLD2:
			m_graphics->DrawCC(POS_BG_PROLOGUE_X,POS_BG_PROLOGUE_Y,m_pTexture[T_BG_PROLOGUE],T_BG_PROLOGUE,R_BG_PROLOGUE);//�w�i
			m_graphics->Draw(POS_WORLD2_X,pos_slide,m_pTexture[T_WRITING],T_WRITING,R_WORLD2);	//���E�ϐ����ڍ�
			break;
		case SCENE_PLOT:
			m_graphics->DrawCC(POS_BG_PROLOGUE_X,POS_BG_PROLOGUE_Y,m_pTexture[T_BG_PROLOGUE],T_BG_PROLOGUE,R_BG_PROLOGUE);//�w�i
			m_graphics->Draw(POS_WORLD2_X,pos_slide,m_pTexture[T_WRITING],T_WRITING,R_PLOT);//���炷��
			if(alpha2 <= 0) m_graphics->DrawCC(650,550,m_pTexture[T_PRO_LOADING],T_PRO_LOADING,R_PRO_LOADING);
			break;
	}	
}

void C_Prologue::Sound()
{

}

void C_Prologue::Release()
{
	for(int i = 0;i < use_sound;i++) SoundRelease(i);
}

void C_Prologue::SlideRect()
{
	switch(*m_scene_num[PROLOGUE]){
		case SCENE_WORLD1:
			if(alpha == 0) rect_slide++;		//���̃t�F�[�h�������I��������

			if(rect_slide < MAX_SLIDE){
				rect_prologue[R_WORLD1_1LINE].top	 = rect_slide * R_SLIDE_SIZE + 1.0f;					//3�s�����؂���ʒu�����炷
				rect_prologue[R_WORLD1_1LINE].bottom = rect_slide * R_SLIDE_SIZE + FONTSIZE;

				rect_prologue[R_WORLD1_2LINE].top	 = rect_slide * R_SLIDE_SIZE + (FONTSIZE + 1.0f);		//3�s�����؂���ʒu�����炷
				rect_prologue[R_WORLD1_2LINE].bottom = rect_slide * R_SLIDE_SIZE + (FONTSIZE * 2);

				rect_prologue[R_WORLD1_3LINE].top	 = rect_slide * R_SLIDE_SIZE + (FONTSIZE * 2 + 1.0f);	//3�s�����؂���ʒu�����炷
				rect_prologue[R_WORLD1_3LINE].bottom = rect_slide * R_SLIDE_SIZE + (FONTSIZE * 3);

				m_graphics->SetPostion(rect_prologue[R_WORLD1_1LINE],R_WORLD1_1LINE);
				m_graphics->SetPostion(rect_prologue[R_WORLD1_2LINE],R_WORLD1_2LINE);
				m_graphics->SetPostion(rect_prologue[R_WORLD1_3LINE],R_WORLD1_3LINE);
			}
			else{
				rect_slide = 0;
				*m_scene_num[PROLOGUE] = SCENE_WORLD2;
			}
			break;
		case SCENE_WORLD2:
			if(rect_slide < MAX_SLIDE2){
				rect_prologue[R_WORLD2].top		= rect_slide * R_SLIDE_SIZE2 + 1.0f;		//5�s�����؂���ʒu�����炷
				rect_prologue[R_WORLD2].bottom  = (rect_slide + 1)* R_SLIDE_SIZE2;

				m_graphics->SetPostion(rect_prologue[R_WORLD2],R_WORLD2);
			}
			else{
				rect_slide = 0;
				*m_scene_num[PROLOGUE] = SCENE_PLOT;
			}
			break;
	}
}

void C_Prologue::Slide()
{
	switch(*m_scene_num[PROLOGUE]){
		case SCENE_WORLD1: break;
		case SCENE_WORLD2:
			pos_slide -= SLIDE_SPEED_WORLD2;			//��ɃX���C�h

			if(count_wait > WAIT_TIME){				
				if(pos_slide < SLIDE_RETURN){
					pos_slide = POS_WORLD2_Y;			//������Y���W�����ɍĐݒ�
					rect_slide++;						//���ɐ؂��镶�͂����炷
					count_wait = 0;
				}
			}
			else{
				if(pos_slide < WAIT_POS){
					pos_slide = WAIT_POS;				//STOP!
					count_wait++;						//���΂����҂���
				}
			}
			break;
		case SCENE_PLOT:
			pos_slide -= SLIDE_SPEED_PLOT;				//��ɃX���C�h

			if(pos_slide < NEXTSTORY_POS){
				alpha2 = m_graphics->FadeOut(FADE_SPEED_PRO,alpha2);
				m_graphics->SetColor(D3DCOLOR_ARGB(alpha2,255,255,255),R_BG_PROLOGUE);
			}
			if(alpha2 <= 0){
				count_fade_pro = 0;
				NowLoading(ADV_SCENE,TEXT_STORY3_1);
				m_graphics->SetColor(D3DCOLOR_ARGB(m_alpha_load,255,255,255),R_PRO_LOADING);
			}
			break;
	}
}

void C_Prologue::FadeIn()
{
	count_fade_pro++;

	if( (0 <= count_fade_pro) && (count_fade_pro < FADE_TIME) ){		//�t�F�[�h�C��
		switch(*m_scene_num[PROLOGUE]){
			case SCENE_WORLD1:
				alpha = m_graphics->FadeIn(ALPHA_CHANGE,alpha); 	break;
			case SCENE_WORLD2:
				alpha2 = m_graphics->FadeIn(ALPHA_CHANGE,alpha2);	break;
		}
	}
}

void C_Prologue::FadeOut()
{
	if(count_fade_pro >= FADE_TIME){							//�t�F�[�h�A�E�g
		switch(*m_scene_num[PROLOGUE]){
			case SCENE_WORLD1:
				alpha =	m_graphics->FadeOut(ALPHA_CHANGE,alpha);   break;
			case SCENE_WORLD2: case SCENE_PLOT:
				alpha2 = m_graphics->FadeOut(ALPHA_CHANGE,alpha2); break;
		}
	}
	if(alpha <= 0) count_fade_pro = 0;
}

void C_Prologue::ShortCutKey(int* key)
{
	switch(*m_scene_num[PROLOGUE]){
		case SCENE_WORLD1:
			if(key[X_PUSH-1] == X_PUSH){ count_fade_pro = 300; alpha = 0; }
			break;
		case SCENE_WORLD2:
			if(pos_slide == WAIT_POS){
				if(key[X_PUSH-1] == X_PUSH){ count_wait = WAIT_TIME; }
			}
			break;
		case SCENE_PLOT:
			if(key[DOWN_PRESS-1] == DOWN_PRESS) pos_slide -= FADE_SPEED_PRO;				//��ɃX���C�h
			break;
	}
}

void C_Prologue::DebugKey(int* key)
{
	if(key[S_PUSH-1] == S_PUSH){
		switch(*m_scene_num[PROLOGUE]){
			case SCENE_WORLD1: *m_scene_num[PROLOGUE] = SCENE_WORLD2; break;
			case SCENE_WORLD2: *m_scene_num[PROLOGUE] = SCENE_PLOT;	  break;
			case SCENE_PLOT:	pos_slide = NEXTSTORY_POS;			  break;
		}
	}
}