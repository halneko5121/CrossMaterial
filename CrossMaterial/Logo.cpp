/*================================

	INCLUDEたち

=================================*/
#include "Logo.h"
#include <Time.h>
#include <stdlib.h>


F_RECT rect_logo[] =
{
	{0.0f,600.0f,0.0f,800.0f}	//ロゴ
};

char* LoadLogoFile[] = //使う絵を読み込んでおく
{
	{"Graphic\\BG\\T_Team_logo.PNG"},
	
	{"\0"},
};

char* LoadSoundLogo[] = //使う音を読み込んでおく
{
	{"Sound\\Logo\\9pb_girl01.wav"},
	{"Sound\\Logo\\9pb_girl02.wav"},
	{"Sound\\Logo\\9pb_girl03.wav"},
	{"Sound\\Logo\\9pb_man01.wav"},
	{"Sound\\Logo\\9pb_man02.wav"},
};

C_Logo::C_Logo(C_DGraphics* graphic)	//コンストラクタ
{
	m_scene_flag = LOGO;	//SceneManageクラスにLOGOフラグを返す。

	m_graphics = graphic;

	use_texture = 0;		//使用するテクスチャ数

	alpha = 0;				//画像のアルファ値

	time_count = 0;			//ロゴ開始から終了までをカウント

	for(int i = 0; LoadLogoFile[i] != "\0"; i++)	//使う絵の枚数を知らせる
	{
		use_texture++;	
	}

	m_graphics->SetTextureNum(use_texture);  //テクスチャの枚数をセットする

	m_graphics->InitData(MAX_LOGO_TEXTURE);  //矩形の数だけメモリを確保する。

	m_pTexture = new LPDIRECT3DTEXTURE9[use_texture];		//画像データの数だけメモリを確保する。

	for(int i = 0; i < use_texture; i++)  //テクスチャの読み込みを行う。
	{
		m_graphics->LoadTexture(LoadLogoFile[i],m_pTexture[i]); 
	}

	m_graphics->SetPostion(rect_logo[T_TEAM_LOGO],D_TEAM_LOGO);      //矩形情報をセットする

	m_graphics->SetColor(D3DCOLOR_RGBA(alpha,alpha,alpha,255),T_TEAM_LOGO);

	for(int i = 0;i < MAX_S_LOGO;i++){
		LoadSound(LoadSoundLogo[i],i);	//タイトル画面のBGM
	}
}

C_Logo::~C_Logo()			//デストラクタ
{
}

void C_Logo::Init()
{
	m_alpha_load = 0;

	m_count_fade = 0;

	m_flag_fade  = false;

	//追加　2/28三上
	flag_soundstop = true;
	srand((unsigned int)time(NULL));
	randum_voice = rand() % 5;
}

void C_Logo::Control(int* key)
{
	FadeControl();	//フェード処理
}

void C_Logo::Draw()
{
	m_graphics->DrawCC(400.0f, 300.0f, m_pTexture[T_TEAM_LOGO], T_TEAM_LOGO, D_TEAM_LOGO);  
}

void C_Logo::FadeControl()	//フェード処理
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

void C_Logo::Release()	//解放
{
	for(int i = 0;i < MAX_LOGO_TEXTURE;i++)
	{
		m_pTexture[i]->Release();
	}
}
