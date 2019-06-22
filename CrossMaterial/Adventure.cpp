#include "Adventure.h"

/************************************************************************************
 *																					*
 *	役割：ADVパートを管理する														*
 *																					*
 *	説明：スクリプトの実行、スクリプト.cppの終了結果のよって次のシーンに飛ばします　*
 *																					*
 *	作成日：2008年 12月 10日														*
 *																					*
 *	更新日：2008年 2月	20日														*
 *													by	三上　亘					*
 *																					*
 ************************************************************************************/

F_RECT rect_adv[] =				//ADVパートのなのでプロローグでもキャラ絵に関しては
{
	{  0.0f, 30.0f,  0.0f,200.0f},	//LOADING
};

char* LoadADVFile[] = //使う絵を読み込んでおく
{
	{"Graphic\\NowLoading.png"},
	{"\0"},
};

C_Adventure::C_Adventure(C_DGraphics* graphic)
{
	m_scene_flag = ADV_SCENE;							//SceneManageクラスにADVフラグを返す。

	m_graphics = graphic;

	use_texture = 0;									//使用するテクスチャ数

	for(int i = 0; LoadADVFile[i] != "\0"; i++)			//使う絵の枚数を知らせる
	{
		use_texture++;	
	}

	m_graphics->InitData(R_ADV_MAX);					 //矩形の数だけメモリを確保する。

	m_pTexture = new LPDIRECT3DTEXTURE9[use_texture];	//画像データの数だけメモリを確保する。

	m_scene_number = new int;

	m_scene_number[0] = TEXT_PROLOGUE;

	alpha = 1;

	flag_end = FLAG_CONTINUE;

	pScript = new C_Script(m_graphics);	//Scriptクラスのオブジェクトを生成する。

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
					SetSceneNum(ADV_SCENE,m_scene_number);		//ADVパートの『STORY3_1 ～ 戦闘前』へ
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

void C_Adventure::Sound()						//サウンドの管理
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
	m_graphics->SetTextureNum(use_texture);		//テクスチャの枚数をセットする

	for(int i = 0; i < use_texture; i++)		//テクスチャの読み込みを行う。
	{
		m_graphics->LoadTexture(LoadADVFile[i],m_pTexture[i]); 
	}
	
	for(int i = 0; i < R_ADV_MAX; i++)
	{
		m_graphics->SetPostion(rect_adv[i],i);	//矩形情報をセットする
	}	

}