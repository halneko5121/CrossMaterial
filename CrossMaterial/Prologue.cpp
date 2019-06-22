#include "Prologue.h"

/************************************************************************************
 *																					*
 *	役割：プロローグを管理します													*
 *																					*
 *	説明：世界観説明→詳細→あらすじ(本編に続く)→本編								*
 *																					*
 *	作成日：2008年 12月 5日															*
 *																					*
 *	更新日：2008年 2月 20日															*
 *													by	三上　亘					*
 *																					*
 ************************************************************************************/

F_RECT rect_prologue[] =
{
	{   0.0f, 600.0f,  0.0f, 800.0f},				//背景

	{   1.0f,  30.0f,   1.0f, 650.0f},				//世界観紹介(1行目)
	{  31.0f,  60.0f,   1.0f, 650.0f},				//世界観紹介(2行目)
	{  61.0f,  90.0f,   1.0f, 650.0f},				//世界観紹介(3行目)
	{   1.0f, 150.0f, 651.0f,1350.0f},				//世界観紹介(詳細)
	{	1.0f,1320.0f,1351.0f,2000.0f},				//あらすじ
	{	0.0f,  30.0f,	0.0f, 200.0f},				//LOADING


};

char* LoadPrologueFile[] =	{					//使う絵を読み込んでおく
	{"Graphic\\BG\\T_Intro.png"},				//背景
	{"Graphic\\T_Sentence.png"},				//文章画像データ
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

	m_scene_flag = PROLOGUE;								//SceneManageクラスにPROLOGUEフラグを返す。

	m_scene_number = new int;

	use_texture = 0;										//使用するテクスチャ数

	use_sound = 0;

	for(int i = 0; LoadSoundPrologue[i] != "\0"; i++){		//使う音の数を知らせる
		use_sound++;	
	}

	for(int i = 0;i < use_sound;i++){
		LoadSound(LoadSoundPrologue[i],i);
	}

	for(int i = 0; LoadPrologueFile[i] != "\0"; i++){		//使う絵の枚数を知らせる
		use_texture++;	
	}

	m_graphics->SetTextureNum(use_texture);					//テクスチャの枚数をセットする

	m_graphics->InitData(R_MAX_PROLOGUE);					//矩形の数だけメモリを確保する。

	m_pTexture = new LPDIRECT3DTEXTURE9[use_texture];		//画像データの数だけメモリを確保する。

	for(int i = 0; i < use_texture; i++){					//テクスチャの読み込みを行う。
		m_graphics->LoadTexture(LoadPrologueFile[i],m_pTexture[i]); 
	}

	for(int i = 0; i < R_MAX_PROLOGUE; i++){				//矩形のセットを行う。
		m_graphics->SetPostion(rect_prologue[i],i);			//矩形情報をセットする
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

	//変数初期化
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
			m_graphics->Draw(POS_WORLD1_LINE1_X,POS_WORLD1_LINE1_Y,m_pTexture[T_WRITING],T_WRITING,R_WORLD1_1LINE);//1行目
			m_graphics->Draw(POS_WORLD1_LINE2_X,POS_WORLD1_LINE2_Y,m_pTexture[T_WRITING],T_WRITING,R_WORLD1_2LINE);//2行目
			m_graphics->Draw(POS_WORLD1_LINE3_X,POS_WORLD1_LINE3_Y,m_pTexture[T_WRITING],T_WRITING,R_WORLD1_3LINE);//3行目
			break;
		case SCENE_WORLD2:
			m_graphics->DrawCC(POS_BG_PROLOGUE_X,POS_BG_PROLOGUE_Y,m_pTexture[T_BG_PROLOGUE],T_BG_PROLOGUE,R_BG_PROLOGUE);//背景
			m_graphics->Draw(POS_WORLD2_X,pos_slide,m_pTexture[T_WRITING],T_WRITING,R_WORLD2);	//世界観説明詳細
			break;
		case SCENE_PLOT:
			m_graphics->DrawCC(POS_BG_PROLOGUE_X,POS_BG_PROLOGUE_Y,m_pTexture[T_BG_PROLOGUE],T_BG_PROLOGUE,R_BG_PROLOGUE);//背景
			m_graphics->Draw(POS_WORLD2_X,pos_slide,m_pTexture[T_WRITING],T_WRITING,R_PLOT);//あらすじ
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
			if(alpha == 0) rect_slide++;		//一回のフェード処理が終了したら

			if(rect_slide < MAX_SLIDE){
				rect_prologue[R_WORLD1_1LINE].top	 = rect_slide * R_SLIDE_SIZE + 1.0f;					//3行分ずつ切り取り位置をずらす
				rect_prologue[R_WORLD1_1LINE].bottom = rect_slide * R_SLIDE_SIZE + FONTSIZE;

				rect_prologue[R_WORLD1_2LINE].top	 = rect_slide * R_SLIDE_SIZE + (FONTSIZE + 1.0f);		//3行分ずつ切り取り位置をずらす
				rect_prologue[R_WORLD1_2LINE].bottom = rect_slide * R_SLIDE_SIZE + (FONTSIZE * 2);

				rect_prologue[R_WORLD1_3LINE].top	 = rect_slide * R_SLIDE_SIZE + (FONTSIZE * 2 + 1.0f);	//3行分ずつ切り取り位置をずらす
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
				rect_prologue[R_WORLD2].top		= rect_slide * R_SLIDE_SIZE2 + 1.0f;		//5行分ずつ切り取り位置をずらす
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
			pos_slide -= SLIDE_SPEED_WORLD2;			//上にスライド

			if(count_wait > WAIT_TIME){				
				if(pos_slide < SLIDE_RETURN){
					pos_slide = POS_WORLD2_Y;			//ここでY座標を下に再設定
					rect_slide++;						//次に切り取る文章をずらす
					count_wait = 0;
				}
			}
			else{
				if(pos_slide < WAIT_POS){
					pos_slide = WAIT_POS;				//STOP!
					count_wait++;						//しばしお待ちを
				}
			}
			break;
		case SCENE_PLOT:
			pos_slide -= SLIDE_SPEED_PLOT;				//上にスライド

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

	if( (0 <= count_fade_pro) && (count_fade_pro < FADE_TIME) ){		//フェードイン
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
	if(count_fade_pro >= FADE_TIME){							//フェードアウト
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
			if(key[DOWN_PRESS-1] == DOWN_PRESS) pos_slide -= FADE_SPEED_PRO;				//上にスライド
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