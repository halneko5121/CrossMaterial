#include "Ending.h"

/************************************************************************************
 *																					*
 *	役割：エンディング画面の管理をします											*
 *																					*
 *	説明：少しずつ統合ファイルを変えつつスタッフロールをスクロールさせる			*
 *																					*
 *	作成日：2009年 2 月28日															*
 *																					*
 *	更新日：年 月 日																*
 *													by	三上　亘					*
 *																					*
 ************************************************************************************/

F_RECT rect_ending[]={

	{0.0f,600.0f,0.0f,800.0f},	//背景
	{0.0f,600.0f,0.0f,800.0f},	//スタッフロール

	{ 50.0f, 90.0f,125.0f,670.0f},	//1
	{120.0f,160.0f,115.0f,685.0f},	//2
	{190.0f,270.0f, 75.0f,725.0f},	//3.4
	{300.0f,340.0f,315.0f,485.0f},	//5
	{370.0f,410.0f,250.0f,545.0f},	//6
	{440.0f,480.0f, 70.0f,720.0f},	//7
	{520.0f,560.0f,220.0f,580.0f},	//8

	{0.0f,30.0f,0.0f,200.0f},	//LOADING

};

RECT rect_string = {0,0,800,600};

char* LoadEndFile[] = //使う絵を読み込んでおく
{
	{"Graphic\\STAFFROLL\\EndingTitle.png"},
	{"Graphic\\STAFFROLL\\Staff_01.png"},
	{"Graphic\\STAFFROLL\\Staff_02.png"},
	{"Graphic\\STAFFROLL\\Staff_03.png"},
	{"Graphic\\STAFFROLL\\Staff_04.png"},
	{"Graphic\\STAFFROLL\\Staff_05.png"},
	{"Graphic\\STAFFROLL\\Staff_06.png"},
	{"Graphic\\STAFFROLL\\Staff_07.png"},
	{"Graphic\\STAFFROLL\\Staff_08.png"},
	{"Graphic\\STAFFROLL\\LastMessage.png"},
	{"Graphic\\NowLoading.png"},
	{"\0"},
};

char* LoadSoundEnding[] = //使う音を読み込んでおく
{
	{"Sound\\Ending\\Ending1.wav"},
	{"\0"},
};

C_Ending::C_Ending(C_DGraphics *graphic)
{
	m_scene_flag = ENDING;						//SceneManageクラスにENDINGフラグを返す。

	m_graphics = graphic;

	m_scene_number = new int;

	use_texture = 0;			

	for(int i=0; LoadEndFile[i] != "\0"; i++)		//使う絵の枚数を知らせる
	{
		use_texture++;	
	}

	m_graphics->SetTextureNum(use_texture);					//テクスチャの枚数をセットする

	m_graphics->InitData(R_END_MAX);						//矩形の数だけメモリを確保する。

	m_pTexture = new LPDIRECT3DTEXTURE9[use_texture];		//画像データの数だけメモリを確保する。

	for(int i=0; i<R_END_MAX; i++)
	{
		m_graphics->SetPostion(rect_ending[i],i);			//矩形情報をセットする
	}	

	for(int i=0; i < use_texture; i++)						//テクスチャの読み込みを行う。
	{
		m_graphics->LoadTexture(LoadEndFile[i],m_pTexture[i]); 
	}

	for(int i=0; i<MAX_S_END; i++){
		LoadSound(LoadSoundEnding[i],i);					//エンディング画面のBGM
	}
	SoundPlay(false,S_END_BGM);
}

C_Ending::~C_Ending(void)
{
}

void C_Ending::Init()
{
	m_alpha_load	  = m_count_fade	= 0;
	m_flag_fade		  = false;	
	m_scene_number[0] = 0;

	endflag		 = lastflag = lastmessage = flag_lastfadein = flag_slide_2 = flag_nowloading = false;
	flag_slide_1 = true; 

	slide_pos	 = slide_pos2 = 610.f;
	staffroll_1	 = 1; staffroll_2 = 2;
	count_wait	 = count_alpha = fade_flag = stay_cnt = next_message = 0;
	alpha_back	 = 0.f;
	alpha_staff  = 1;
	for(int i = 0;i < (R_END_LASTMESSAGE8 - 1);i++){
		m_graphics->SetColor(D3DCOLOR_ARGB(alpha_staff,255,255,255),(R_END_LASTMESSAGE1 + i));
	}

	m_graphics->SetColor(D3DCOLOR_ARGB((int)alpha_back,255,255,255),R_END_BACK);
}

void C_Ending::Control(int* key)
{
#ifdef _DEBUG
	if(fade_flag ==2){
		if(key[5]){
			if(flag_slide_1) slide_pos	-= 10; 
			if(flag_slide_2) slide_pos2	-= 10;
		}
	}
#endif

	FadeControl();

	if(flag_nowloading){				
		NowLoading(LOGO);
		m_graphics->SetColor(D3DCOLOR_ARGB(m_alpha_load,255,255,255),R_END_LOADING);
	}
}

void C_Ending::Draw()
{
	m_graphics->DrawCC(400.f,300.f,m_pTexture[T_END_BACK],T_END_BACK,R_END_BACK);

	if(!lastmessage){
		m_graphics->Draw(0.f,slide_pos ,m_pTexture[staffroll_1],staffroll_1,R_END_STAFFNAME);
		m_graphics->Draw(0.f,slide_pos2,m_pTexture[staffroll_2],staffroll_2,R_END_STAFFNAME);
	}
	else if(flag_nowloading)m_graphics->DrawCC(650,550,m_pTexture[T_END_LOADING],T_END_LOADING,R_END_LOADING);
	
	else{
		m_graphics->DrawCC(400.f, 50.f,m_pTexture[T_END_LASTMESSAGE],T_END_LASTMESSAGE,R_END_LASTMESSAGE1);
		m_graphics->DrawCC(400.f,120.f,m_pTexture[T_END_LASTMESSAGE],T_END_LASTMESSAGE,R_END_LASTMESSAGE2);
		m_graphics->DrawCC(400.f,230.f,m_pTexture[T_END_LASTMESSAGE],T_END_LASTMESSAGE,R_END_LASTMESSAGE3_4);
		m_graphics->DrawCC(400.f,330.f,m_pTexture[T_END_LASTMESSAGE],T_END_LASTMESSAGE,R_END_LASTMESSAGE5);
		m_graphics->DrawCC(400.f,400.f,m_pTexture[T_END_LASTMESSAGE],T_END_LASTMESSAGE,R_END_LASTMESSAGE6);
		m_graphics->DrawCC(400.f,470.f,m_pTexture[T_END_LASTMESSAGE],T_END_LASTMESSAGE,R_END_LASTMESSAGE7);
		m_graphics->DrawCC(400.f,550.f,m_pTexture[T_END_LASTMESSAGE],T_END_LASTMESSAGE,R_END_LASTMESSAGE8);
	}
}

void C_Ending::Slide()
{
	if(flag_slide_1) slide_pos  -= SP_SLIDE_POS;
	if(flag_slide_2) slide_pos2 -= SP_SLIDE_POS2;

	if(staffroll_1 == T_END_LASTMESSAGE){
		flag_slide_1 = false;
		if(slide_pos2 < -600.f){ 
			lastflag = flag_lastfadein = true; fade_flag = 3; 
		}
	}
	else if(!lastflag){
		if(slide_pos < -600.f){
			staffroll_1 += 2; slide_pos = 610.f;
		}
		else if(slide_pos < 0.f)flag_slide_2 = true;
		
		if(slide_pos2 < -600.f){ staffroll_2 += 2; slide_pos2 = 610.f;}
	}
}

void C_Ending::Sound()
{

}

void C_Ending::Release()
{
	for(int i = 0;i < MAX_S_END;i++) SoundRelease(i);
	for(int i = 0;i < T_END_MAX;i++) m_pTexture[i]->Release();
}

void C_Ending::FadeIn()
{
	if(lastflag){
		if(flag_lastfadein){
			if(count_alpha++ > 1)		{ alpha_staff += ALPHA_F_IN; count_alpha = 0; }
			if(alpha_staff > MAX_ALPHA) { next_message++; alpha_staff = 0; }
			if(next_message >= 7){
				flag_lastfadein  = false; alpha_staff = MAX_ALPHA;
			}
			m_graphics->SetColor(D3DCOLOR_ARGB(alpha_staff,MAX_ARGB,MAX_ARGB,MAX_ARGB),(R_END_LASTMESSAGE1 + next_message) );
		}
	}
	else{
		if(fade_flag > 1) return;

		if(count_alpha++>1){ alpha_back += LAST_ALPHA_IN; count_alpha = 0; }
		if(alpha_back > MAX_ALPHA){ alpha_back  = MAX_ALPHA; count_alpha = 0; }
		m_graphics->SetColor(D3DCOLOR_ARGB((int)alpha_back,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_END_BACK);
	}
}

void C_Ending::FadeOut()
{
	if(!lastflag){
		if(fade_flag == 1 && alpha_back <= 100) return;
		
		if(count_alpha++ > 1)		{ alpha_back -= ALPHA_F_OUT; count_alpha = 0; }
		if(alpha_back < ALPHA_STOP) { alpha_back  = 100;		 count_alpha = 0; }
		m_graphics->SetColor(D3DCOLOR_ARGB((int)alpha_back,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_END_BACK);
	}
	else if(flag_lastfadein){//最後の一枚
		alpha_back = m_graphics->FadeOut((0.1),alpha_back);
		m_graphics->SetColor(D3DCOLOR_ARGB((int)alpha_back,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_END_BACK);
	}

	if(next_message >= 7){	
		alpha_staff = m_graphics->FadeOut(1,alpha_staff);
		for(int i = 0;i < (R_END_LASTMESSAGE8 - 1);i++){
			m_graphics->SetColor(D3DCOLOR_ARGB(alpha_staff,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_END_LASTMESSAGE1 + i);
		}
		if(alpha_staff <= 0) flag_nowloading = true;
	}
}

void C_Ending::FadeControl()
{
	switch(fade_flag){
	case 0:	//フェードイン
		FadeIn();
		if(alpha_back>= MAX_ALPHA && stay_cnt++>120){
			fade_flag = 1; stay_cnt  = 0;
		}
		break;
	case 1:
		FadeOut();
		if(alpha_back <= 100 && stay_cnt++>120){
			fade_flag = 2; stay_cnt  = 0;
		}
		break;
	case 2:
		Slide();
		break;
	case 3:
		lastmessage = true;
		FadeOut();
		FadeIn();
		break;
	}
}
