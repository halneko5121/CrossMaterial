#include "Title.h"

//タイトルの矩形情報{top,bottom,left,right}
F_RECT rect_title[]={
	{  0.0f,600.0f,  0.0f,800.0f},	//タイトルの背景
	{  0.0f, 39.0f,  0.0f,179.0f},	//STARTのフォント
	{ 81.0f,120.0f,  0.0f,121.0f},	//ENDのフォント
	{240.0f,279.0f,  0.0f,270.0f},	//アイコン
	{  0.0f, 30.0f,  0.0f,200.0f},	//LOADING
};

char* LoadTitleFile[] = //使う絵を読み込んでおく
{
	{"Graphic\\BG\\T_Title.png"},			
	{"Graphic\\Font・Consor\\T_TitleFont.png"},
	{"Graphic\\Font・Consor\\T_status.png"},
	{"Graphic\\NowLoading.png"},
	{"\0"},
};

char* LoadSoundTitle[] = //使う音を読み込んでおく
{
	{"Sound\\Title\\title.wav"}, 
	{"Sound\\Title\\se-select.wav"},
	{"Sound\\Title\\se-enter.wav"},
	{"Sound\\Title\\se-cancel.wav"},
};

C_Title::C_Title(C_DGraphics *graphic)
{
	m_scene_flag = TITLE;						//SceneManageクラスにTITLEフラグを返す。

	m_graphics = graphic;

	use_texture = 0;							//使用するテクスチャ数

	title_draw_flag=0;

	alpha = 0;		//画像のアルファ値
	
	alpha_count= 0; //アルファカウント
	
	menu_flag=0;	//メニューの位置

	fade_flag=0;	//フェードフラグ

	for(int i = 0; LoadTitleFile[i] != "\0"; i++)	//使う絵の枚数を知らせる
	{
		use_texture++;	
	}

	m_graphics->SetTextureNum(use_texture);			//テクスチャの枚数をセットする

	m_graphics->InitData(R_TITLE_MAX);				//矩形の数だけメモリを確保する。

	m_pTexture = new LPDIRECT3DTEXTURE9[use_texture];		//画像データの数だけメモリを確保する。

	for(int i = 0; i < use_texture; i++)			//テクスチャの読み込みを行う。
	{
		m_graphics->LoadTexture(LoadTitleFile[i],m_pTexture[i]); 
	}
	
	for(int i = R_TITLE_BG; i < R_TITLE_MAX; i++)
	{
		m_graphics->SetPostion(rect_title[i],i);      //矩形情報をセットする
	}

	m_graphics->SetColor(D3DCOLOR_RGBA(alpha,alpha,alpha,255),T_TITLE_BG);

	for(int i = 0;i < MAX_S_TITLE;i++){
		LoadSound(LoadSoundTitle[i],i);	//タイトル画面のBGM
	}

	//3/10追加　三上
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
		case 0:	//フェードイン
			FadeIn();
			if(alpha==255) fade_flag=1;
			SoundPlay(true,S_TITLE_BGM);
			break;
		case 1:
			alpha=TITLE_MAX_ALPHA;
			alpha_count=0;
			break;
		case 2:	//STARTを選択した後、フェードアウト、ADV(プロローグ)へ移行する
			FadeOut();
			//3/10 三上 追加↓
			if(alpha == 0){
				SoundStop(true,S_TITLE_BGM);
				NowLoading(ADV_SCENE,TEXT_PROLOGUE);
				m_graphics->SetColor(D3DCOLOR_ARGB(m_alpha_load,255,255,255),R_TITLE_LOADING);
			}
			break;
			//3/10 三上 追加↑
		case 3:	//ENDを選択したらフェードアウトして終了処理へ
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

void C_Title::Sound()						//サウンドの管理
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
